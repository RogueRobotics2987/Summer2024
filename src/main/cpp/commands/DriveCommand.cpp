// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubsystem &motorRIGHT)
{
  // Register that this command requires the subsystem.
  
  m_motorRIGHT = &motorRIGHT;
  
  AddRequirements(m_motorRIGHT);
}
/*
DriveCommand::DriveCommand(DriveSubsystem &motorLEFT)
{
  // Register that this command requires the subsystem.
  
  m_motorLEFT = &motorLEFT;
  
  AddRequirements(m_motorLEFT);
}
*/
void DriveCommand::Initialize()
{
 m_motorRIGHT->SetSpeed(0.25);
 //m_motorLEFT->SetSpeed(-0.25);
}

void DriveCommand::Execute()
{

}

void DriveCommand::End(bool interrupted)
{
  m_motorRIGHT->SetSpeed(0);
 // m_motorLEFT->SetSpeed(0);
}

bool DriveCommand::IsFinished()
{
  return false;
}