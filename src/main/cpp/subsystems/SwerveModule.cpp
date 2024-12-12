// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SwerveModule.h"

#include <numbers>

#include <frc/geometry/Rotation2d.h>

#include "Constants.h"

SwerveModule::SwerveModule(int driveMotorChannel, int turningMotorChannel,
                           const int turningEncoderPort,
                           bool driveEncoderReversed,
                           bool turningEncoderReversed)
    : kraken_driveMotor(driveMotorChannel, "canivore"),
      kraken_turningMotor(turningMotorChannel, "canivore"),
      cancoder_turningEncoder(turningEncoderPort, "canivore")
      
       {
  // Set the distance per pulse for the drive encoder. We can simply use the
  // distance traveled for one rotation of the wheel divided by the encoder
  // resolution.
//   m_driveEncoder.SetDistancePerPulse(
//       ModuleConstants::kDriveEncoderDistancePerPulse);


//   // Set whether drive encoder should be reversed or not
//   m_driveEncoder.SetReverseDirection(driveEncoderReversed);

  // Set the distance (in this case, angle) per pulse for the turning encoder.
  // This is the the angle through an entire rotation (2 * std::numbers::pi)
  // divided by the encoder resolution.
//   m_turningEncoder.SetDistancePerPulse(
//       ModuleConstants::kTurningEncoderDistancePerPulse);

  // Set whether turning encoder should be reversed or not
//   m_turningEncoder.SetReverseDirection(turningEncoderReversed);

  // Limit the PID Controller's input range between -pi and pi and set the input
  // to be continuous.
  m_turningPIDController.EnableContinuousInput(
      units::radian_t{-std::numbers::pi}, units::radian_t{std::numbers::pi});


  // CANCoder turning motor configuration, not doing anything right now
  configs::MagnetSensorConfigs magnetConfigs;
  magnetConfigs.WithSensorDirection(signals::SensorDirectionValue::Clockwise_Positive);
  configs::CANcoderConfiguration cancoder_toApply{};

  cancoder_turningEncoder.GetConfigurator().Apply(cancoder_toApply);
  cancoder_turningEncoder.GetConfigurator().Apply(magnetConfigs);

  // Set update status for encoder to 100hz
  BaseStatusSignal::SetUpdateFrequencyForAll(100_Hz, cancoder_turningEncoder.GetPosition(), cancoder_turningEncoder.GetVelocity());

  // Kraken motor configuration, not doing anything right now
  configs::TalonFXConfiguration kraken_toApply{};
  kraken_driveMotor.GetConfigurator().Apply(kraken_toApply);

  // Set update status for encoder to 100hz
  BaseStatusSignal::SetUpdateFrequencyForAll(100_Hz, kraken_driveMotor.GetPosition(), kraken_driveMotor.GetVelocity());

}

frc::SwerveModuleState SwerveModule::GetState() {
  return {units::meters_per_second_t{DriveRotationToDistance(kraken_driveMotor.GetVelocity().GetValue().value())},
          units::radian_t{cancoder_turningEncoder.GetPosition().GetValue()}};
}

frc::SwerveModulePosition SwerveModule::GetPosition() {
  return {units::meter_t{DriveRotationToDistance(kraken_driveMotor.GetPosition().GetValue().value())},
          units::radian_t{cancoder_turningEncoder.GetPosition().GetValue()}};
}

void SwerveModule::SetDesiredState(
    const frc::SwerveModuleState& referenceState) {
  frc::Rotation2d encoderRotation{
      units::radian_t{cancoder_turningEncoder.GetPosition().GetValue()}};

  // Optimize the reference state to avoid spinning further than 90 degrees
  auto state =
      frc::SwerveModuleState::Optimize(referenceState, encoderRotation);

  // Scale speed by cosine of angle error. This scales down movement
  // perpendicular to the desired direction of travel that can occur when
  // modules change directions. This results in smoother driving.
  state.speed *= (state.angle - encoderRotation).Cos();

  // Calculate the drive output from the drive PID controller.
  const auto driveOutput = m_drivePIDController.Calculate(
      kraken_driveMotor.GetVelocity().GetValue().value(), state.speed.value());

  // Calculate the turning motor output from the turning PID controller.
  auto turnOutput = m_turningPIDController.Calculate(
      units::radian_t{cancoder_turningEncoder.GetPosition().GetValue()}, state.angle.Radians());

  // Set the motor outputs.
  kraken_driveMotor.Set(driveOutput);
  kraken_turningMotor.Set(turnOutput);
}

void SwerveModule::ResetEncoders() {
  kraken_driveMotor.SetPosition(units::angle::turn_t(0));
  cancoder_turningEncoder.SetPosition(units::angle::turn_t(0));
}
