/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RotatePID.h"

RotatePID::RotatePID(int angle) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_chassis);
  this->angle = angle;
}

// Called just before this Command runs the first time
void RotatePID::Initialize() {
  Robot::m_chassis.ResetGyro();
  Robot::m_chassis.SetSetpoint(angle);
  Robot::m_chassis.Enable();
}

// Called repeatedly when this Command is scheduled to run
void RotatePID::Execute() {
  
}

// Make this return true when this Command no longer needs to run execute()
bool RotatePID::IsFinished() {
  return Robot::m_chassis.OnTarget();
}

// Called once after isFinished returns true
void RotatePID::End() {
  Robot::m_chassis.Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotatePID::Interrupted() {
  this->End();
}
