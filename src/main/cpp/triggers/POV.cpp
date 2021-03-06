/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "triggers/POV.h"

POV::POV(Joystick* stick) {
    this->stick = stick;
    this->angle = -1;
}

bool POV::Get() {
    int cur_angle = this->stick->GetPOV(0);
    if (cur_angle != -1) {
        this->angle = cur_angle;
        return true;
    }
    return false;
}

int POV::GetAngle() {
    return this->angle;
}
