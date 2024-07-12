// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem()
{
 
}

void DriveSubsystem::SetRightSpeed(double speed)
{
  RightBackMotor.Set(speed);
  RightFrontMotor.Set(speed);
}
void DriveSubsystem::SetLeftSpeed(double speed)
{
  LeftBackMotor.Set(speed);
  LeftFrontMotor.Set(speed);
}

void DriveSubsystem::Periodic() 
{
  // Implementation of subsystem periodic method goes here.
}
