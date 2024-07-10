// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveLEFT.h"
/*
DriveCommand::DriveCommand(DriveSubsystem &motorRIGHT)
{
  // Register that this command requires the subsystem.
  
  m_motorRIGHT = &motorRIGHT;
  
  AddRequirements(m_motorRIGHT);
}
*/
DriveLEFT::DriveLEFT(DriveSubsystem &motorLEFT)
{
  // Register that this command requires the subsystem.
  
  m_motorLEFT = &motorLEFT;
  
  AddRequirements(m_motorLEFT);
}

void DriveLEFT::Initialize()
{
 m_motorLEFT->SetSpeed(-0.25);
}

void DriveLEFT::Execute()
{

}

void DriveLEFT::End(bool interrupted)
{
  m_motorLEFT->SetSpeed(0);
}

bool DriveLEFT::IsFinished()
{
  return false;
}