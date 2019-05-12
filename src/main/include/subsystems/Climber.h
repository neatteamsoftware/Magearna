/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
using namespace frc;
#include <frc/WPILib.h>
#include "../RobotMap.h"

class Climber : public frc::Subsystem {
 private:
  VictorSP* motor;
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Climber();
  void InitDefaultCommand() override;
  void SetPower(double power);
};
