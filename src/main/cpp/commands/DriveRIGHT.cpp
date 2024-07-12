// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveRIGHT.h"

DriveRIGHT::DriveRIGHT(DriveSubsystem &motorRIGHT)
{
  // Register that this command requires the subsystem.
  
  m_motorRIGHT = &motorRIGHT;
  
  AddRequirements(m_motorRIGHT);
}
void DriveRIGHT::Initialize()
{
 m_motorRIGHT->SetRightSpeed(0.25);
}

void DriveRIGHT::Execute()
{

}

void DriveRIGHT::End(bool interrupted)
{
  m_motorRIGHT->SetRightSpeed(0);
}

bool DriveRIGHT::IsFinished()
{
  return false;
}