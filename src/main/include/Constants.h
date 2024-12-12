// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <numbers>

#include <frc/TimedRobot.h>
#include <frc/geometry/Translation2d.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/trajectory/TrapezoidProfile.h>
#include <units/acceleration.h>
#include <units/angle.h>
#include <units/angular_acceleration.h>
#include <units/angular_velocity.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or bool constants.  This should not be used for any other purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {
  constexpr int kFrontLeftDriveMotorPort = 3;
  constexpr int kRearLeftDriveMotorPort = 2;
  constexpr int kFrontRightDriveMotorPort = 4;
  constexpr int kRearRightDriveMotorPort = 1;

  constexpr int kFrontLeftTurningMotorPort = 48;
  constexpr int kRearLeftTurningMotorPort = 43;
  constexpr int kFrontRightTurningMotorPort = 9;
  constexpr int kRearRightTurningMotorPort = 47;

  constexpr int kFrontLeftTurningEncoderPort = 13; 
  constexpr int kRearLeftTurningEncoderPort = 16;
  constexpr int kFrontRightTurningEncoderPort = 14;
  constexpr int kRearRightTurningEncoderPort = 15;

  constexpr bool kFrontLeftTurningEncoderReversed = false;
  constexpr bool kRearLeftTurningEncoderReversed = false;
  constexpr bool kFrontRightTurningEncoderReversed = false;
  constexpr bool kRearRightTurningEncoderReversed = false;

  constexpr bool kFrontLeftDriveEncoderReversed = true;
  constexpr bool kRearLeftDriveEncoderReversed = false;
  constexpr bool kFrontRightDriveEncoderReversed = true;
  constexpr bool kRearRightDriveEncoderReversed = false;

  constexpr int kFrontLeftDriveCPR = 42;
  constexpr int kRearLeftDriveCPR = 42;
  constexpr int kFrontRightDriveCPR = 42;
  constexpr int kRearRightDriveCPR = 42;

  constexpr int kFrontLeftTurningCPR = 1;
  constexpr int kRearLeftTurningCPR = 1;
  constexpr int kFrontRightTurningCPR = 1;
  constexpr int kRearRightTurningCPR = 1;

  constexpr rev::SparkRelativeEncoder::Type sparkEncoderType = rev::SparkRelativeEncoder::Type::kHallSensor;

// If you call DriveSubsystem::Drive with a different period make sure to update
// this.
inline constexpr units::second_t kDrivePeriod = frc::TimedRobot::kDefaultPeriod;

// These are example values only - DO NOT USE THESE FOR YOUR OWN ROBOT!
// These characterization values MUST be determined either experimentally or
// theoretically for *your* robot's drive. The SysId tool provides a convenient
// method for obtaining these values for your robot.
inline constexpr auto ks = 1_V;
inline constexpr auto kv = 0.8 * 1_V * 1_s / 1_m;
inline constexpr auto ka = 0.15 * 1_V * 1_s * 1_s / 1_m;

// Example value only - as above, this must be tuned for your drive!
inline constexpr double kPFrontLeftVel = 0.5;
inline constexpr double kPRearLeftVel = 0.5;
inline constexpr double kPFrontRightVel = 0.5;
inline constexpr double kPRearRightVel = 0.5;
}  // namespace DriveConstants

namespace ModuleConstants {
inline constexpr int kEncoderCPR = 1024;
inline constexpr double kWheelDiameterMeters = 0.15;
inline constexpr double kDriveEncoderDistancePerPulse =
    // Assumes the encoders are directly mounted on the wheel shafts
    (kWheelDiameterMeters * std::numbers::pi) /
    static_cast<double>(kEncoderCPR);

inline constexpr double kTurningEncoderDistancePerPulse =
    // Assumes the encoders are directly mounted on the wheel shafts
    (std::numbers::pi * 2) / static_cast<double>(kEncoderCPR);

inline constexpr double kPModuleTurningController = 1;
inline constexpr double kPModuleDriveController = 1;
}  // namespace ModuleConstants

namespace AutoConstants {
inline constexpr auto kMaxSpeed = 3_mps;
inline constexpr auto kMaxAcceleration = 3_mps_sq;
inline constexpr auto kMaxAngularSpeed = 3.142_rad_per_s;
inline constexpr auto kMaxAngularAcceleration = 3.142_rad_per_s_sq;

inline constexpr double kPXController = 0.5;
inline constexpr double kPYController = 0.5;
inline constexpr double kPThetaController = 0.5;

//

extern const frc::TrapezoidProfile<units::radians>::Constraints
    kThetaControllerConstraints;

}  // namespace AutoConstants

namespace OIConstants {
inline constexpr int kDriverControllerPort = 0;
}  // namespace OIConstants
