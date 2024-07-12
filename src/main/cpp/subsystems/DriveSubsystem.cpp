// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem()
{
 
}

void DriveSubsystem::SetSpeedRight (double RightSpeed)
{
 RightBackMotor.Set(RightSpeed);
 RightFrontMotor.Set(RightSpeed);
}
void DriveSubsystem::SetSpeedLeft (double LeftSpeed)
{
 leftFrontMotor.Set(LeftSpeed);
 leftBackMotor.Set(LeftSpeed);
}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}