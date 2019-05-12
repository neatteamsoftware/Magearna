/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>

OI::OI() {
  // Process operator interface input here.
  this->stick = new Joystick(JOYSTICK_CHANNEL);
  for (int i=0; i<10; i++)
    this->buttons[i] = new JoystickButton(this->stick, i+1);
  this->pov = new POV(this->stick);
  this->buttons[BUTTON_A]->WhenPressed(new ChangeDoors());
  this->buttons[BUTTON_B]->WhileHeld(new Climb());
  this->pov->WhenActive(new RotatePID(this->stick->GetPOV(0)));
}

Joystick* OI::GetStick() {
  return this->stick;
}
