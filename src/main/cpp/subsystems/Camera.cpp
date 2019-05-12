/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Camera.h"

Camera::Camera() : Subsystem("Camera") {
  this->horizontal = new Servo(SERVO_HORIZONTAL);
  this->vertical = new Servo(SERVO_VERTICAL);
}

void Camera::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new MoveCamera());
}

void Camera::RotateCamera() {
  double x = Robot::m_oi.GetStick()->GetRawAxis(AXIS_RIGHT_X);
  double y = Robot::m_oi.GetStick()->GetRawAxis(AXIS_RIGHT_Y);
  this->horizontal->Set(this->horizontal->Get() + x);
  this->vertical->Set(this->vertical->Get() + y);
}
