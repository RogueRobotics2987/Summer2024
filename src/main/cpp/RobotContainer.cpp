// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/DriveRIGHT.h"
#include "commands/DriveLEFT.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `DriveCommand` when `exampleCondition` changes to `true`
  /*frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(DriveCommand(&m_subsystem).ToPtr());
  */

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().ToggleOnTrue(DriveRIGHT(m_motorDriveSubsystem).ToPtr());
  m_driverController.A().ToggleOnTrue(DriveLEFT(m_motorDriveSubsystem).ToPtr());

}
/*frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
*/