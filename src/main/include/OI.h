/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "Robot.h"
using namespace frc;
#include <frc/WPILib.h>
#include "RobotMap.h"
#include "commands/ChangeDoors.h"
#include "commands/Climb.h"
#include "commands/RotatePID.h"
#include "triggers/POV.h"

class OI {
 private:
  Joystick* stick;
  JoystickButton* buttons[10];
  POV* pov;

 public:
  OI();
  Joystick* GetStick();
};
