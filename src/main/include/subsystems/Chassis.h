/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/PIDSubsystem.h>
using namespace frc;
#include <frc/WPILib.h>
#include <math.h>
#include "../RobotMap.h"
#include "../commands/DriveByJoystick.h"

class Chassis : public frc::PIDSubsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  VictorSP* left_front;
	VictorSP* left_rear;
	VictorSP* right_front;
	VictorSP* right_rear;
	SpeedControllerGroup* left;
	SpeedControllerGroup* right;
	DifferentialDrive* drive;
	ADXRS450_Gyro* gyro;
  bool is_reversed;
 public:
  Chassis();
  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;
  void InitDefaultCommand() override;
  void Drive(double mag, double rot, bool squared);
	void Drive(Joystick* stick);
  void ResetGyro();
  void ReverseDrive();
};
