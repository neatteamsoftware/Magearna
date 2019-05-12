/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Climb.h"

Climb::Climb() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_climber);
}

// Called just before this Command runs the first time
void Climb::Initialize() {
  Robot::m_climber.SetPower(0);
}

// Called repeatedly when this Command is scheduled to run
void Climb::Execute() {
  Robot::m_climber.SetPower(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool Climb::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void Climb::End() {
  Robot::m_climber.SetPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Climb::Interrupted() {
  this->End();
}
