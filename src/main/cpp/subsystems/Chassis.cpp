/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Chassis.h"

#include <frc/livewindow/LiveWindow.h>
#include <frc/smartdashboard/SmartDashboard.h>

Chassis::Chassis() : PIDSubsystem("Chassis", 0.008, 0, 0.013) {
  this->left_front = new VictorSP(MOTOR_LEFT_FRONT);
	this->left_rear = new VictorSP(MOTOR_LEFT_REAR);
	this->right_front = new VictorSP(MOTOR_RIGHT_FRONT);
	this->right_rear = new VictorSP(MOTOR_RIGHT_REAR);
	this->left = new SpeedControllerGroup(*this->left_front, *this->left_rear);
	this->right = new SpeedControllerGroup(*this->right_front, *this->right_rear);
	this->drive = new DifferentialDrive(*this->left, *this->right);
  this->gyro = new ADXRS450_Gyro(SPI::Port::kOnboardCS0);
  this->GetPIDController()->SetAbsoluteTolerance(5);
  this->GetPIDController()->SetContinuous(true);
  this->is_reversed = false;
}

double Chassis::ReturnPIDInput() {
  // Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
  if (this->gyro->GetAngle() < 0)
    return fmod(this->gyro->GetAngle(), 360) + 360;
  return fmod(this->gyro->GetAngle(), 360);
}

void Chassis::UsePIDOutput(double output) {
  // Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
  this->Drive(0, output, false);
}

void Chassis::InitDefaultCommand() {
  // Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new DriveByJoystick());
}

void Chassis::Drive(double mag, double rot, bool squared) {
	this->drive->ArcadeDrive(mag, rot, squared);
}

void Chassis::Drive(Joystick* stick) {
  if (this->is_reversed)
	  this->drive->ArcadeDrive(stick->GetY(), -stick->GetX(), stick->GetRawButton(BUTTON_L_STICK));
  else
    this->drive->ArcadeDrive(-stick->GetY(), stick->GetX(), stick->GetRawButton(BUTTON_L_STICK));
}

void Chassis::ResetGyro() {
  this->gyro->Reset();
}

void Chassis::ReverseDrive() {
  this->is_reversed = !this->is_reversed;
}
