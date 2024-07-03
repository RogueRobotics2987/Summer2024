// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  void SetSpeed(double speed);
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  rev::CANSparkMax RightBackMotor{51, rev::CANSparkMax::MotorType::kBrushless}; 
  rev::CANSparkMax RightFrontMotor{15, rev::CANSparkMax::MotorType::kBrushless};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
