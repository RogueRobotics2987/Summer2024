// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem()
{
 
}

void DriveSubsystem::SetSpeed(double speed)
{
 Motor.Set(speed);
}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}
