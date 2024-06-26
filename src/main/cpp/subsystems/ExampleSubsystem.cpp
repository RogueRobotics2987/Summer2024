// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ExampleSubsystem.h"

//TODO: Comment out line 11 "ExampleSubsystem::ExampleSubsystem() {"
//And uncomment line 12 "ExampleSubsystem::ExampleSubsystem(int m_MotorController) {"
//And line 14 "m_driveMotor = new rev::CANSparkMax(m_MotorController, rev::CANSparkMax::MotorType::kBrushless);"

ExampleSubsystem::ExampleSubsystem() {
//ExampleSubsystem::ExampleSubsystem(int m_MotorController) {
  // Implementation of subsystem constructor goes here.
  //m_driveMotor = new rev::CANSparkMax(m_MotorController, rev::CANSparkMax::MotorType::kBrushless);
}

frc2::CommandPtr ExampleSubsystem::ExampleMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem. 
  return RunOnce([/* this */] { /* one-time action goes here */ });
}

void ExampleSubsystem::SetDesiredState(double speed)
{
 m_driveMotor->Set(speed);
}
bool ExampleSubsystem::ExampleCondition() {
  // Query some boolean state, such as a digital sensor.
  return false;
}

void ExampleSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ExampleSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

ExampleSubsystem::~ExampleSubsystem()
{
  delete m_driveMotor;
}