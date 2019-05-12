/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/buttons/Trigger.h>
using namespace frc;
#include <frc/WPILib.h>

class POV : public frc::Trigger {
 private:
  Joystick* stick;
 public:
  POV(Joystick* stick);
  bool Get() override;
};
