// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"
#include "commands/DriveWithButtons.h"
#include "commands/DriveLEFT.h"
#include "commands/DriveRIGHT.h"
#include <frc2/command/button/Trigger.h>
#include "RobotContainer.h"
#include "subsystems/DriveSubsystem.h"


DriveWithButtons::DriveWithButtons(frc2::CommandXboxController& driverController, DriveSubsystem &drivesMotor) {
  // Use addRequirements() here to declare subsystem dependencies.
  // set local controller object = passed in controller object
  m_driverController = &driverController;
  m_motorDriveSubsystem = &drivesMotor;
AddRequirements(m_motorDriveSubsystem);
}

// Called when the command is initially scheduled.
void DriveWithButtons::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveWithButtons::Execute() {

  /*
  Need to add in my code so it knows what to do
  start with buttons, and then joysticks

  add into RobotContainer
  */

/* This code is from Swerve Drive as an example of what I need to do

      bool noJoystickInput = false; //checks if there is any joystick input (if true the wheels will go to the the 45 degree (X) position)
      double safeX = DeadzoneCubed(m_controller.GetLeftX());
      double safeY =  DeadzoneCubed(m_driverController.GetLeftY());
      double safeRot = DeadzoneCubed(m_driverController.GetRightX());

      bool fieldOrientated;

      if (m_driverController.GetRawAxis(3) > 0.15) //if the right trigger is pulled
      {
        fieldOrientated = false; //robot orientated driving
      }

      if (m_driverController.GetRawAxis(3) < 0.15) //if the right trigger is not pulled
      {
        fieldOrientated = true; //field orientated driving
      }

      if ((safeX == 0) && (safeY == 0) && (safeRot == 0))
      {
        noJoystickInput = true; //the wheels will move to the 45 degree (X) position
      }

      m_drive.Drive(
        units::meters_per_second_t(-safeY * AutoConstants::kMaxSpeed),
        units::meters_per_second_t(-safeX * AutoConstants::kMaxSpeed),
        units::radians_per_second_t(-safeRot * std::numbers::pi * 1.5),
        fieldOrientated,
        noJoystickInput
      );

      END Sample code from Swerve drive
      */
 // Right side motors
 if (m_driverController->GetRawButton(2) == true)
      { 
        m_motorDriveSubsystem->SetRightSpeed(0.25);
      }
else if (m_driverController->GetRawButton(2) == false)
      { 
        m_motorDriveSubsystem->SetRightSpeed(0);
      }
//Left side motors
 if (m_driverController->GetRawButton(1) == true)
      { 
        m_motorDriveSubsystem->SetLeftSpeed(-0.25);
      }
else if (m_driverController->GetRawButton(1) == false)
      { 
        m_motorDriveSubsystem->SetLeftSpeed(0);
      }

    }



// Called once the command ends or is interrupted.
void DriveWithButtons::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveWithButtons::IsFinished() {
  return false;
}
