/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Doors.h"

Doors::Doors() : Subsystem("Doors") {
  this->right = new Servo(DOOR_RIGHT);
	this->left = new Servo(DOOR_LEFT);
	this->is_opened = false;
}

void Doors::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Doors::ChangeDoors()
{
	if (this->is_opened)
	{
		this->right->Set(1);
		this->left->Set(-1);
		this->is_opened = false;
	}

	else
	{
		this->right->Set(-1);
		this->left->Set(1);
		this->is_opened = true;
	}
}
