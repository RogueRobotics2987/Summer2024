// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubsystem &subsystem)
{
  // Register that this command requires the subsystem.
  
  m_subsystem = &subsystem;

  AddRequirements(m_subsystem);
}

void DriveCommand::Initialize()
{
 m_subsystem->SetSpeed(0.25);
}

void DriveCommand::Execute()
{

}

void DriveCommand::End(bool interrupted)
{
  m_subsystem->SetSpeed(0);
}

bool DriveCommand::IsFinished()
{
  return false;
}