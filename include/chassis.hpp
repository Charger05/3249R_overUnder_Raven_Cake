#pragma once
#ifndef _CHASSIS_HPP_
#define _CHASSIS_HPP_//Prevent extra declarations of types, enums and static variables

#include "api.h"
#include "okapi/api.hpp"
using namespace okapi::literals;

class Chassis{
    public:
        okapi::Motor rearLeft;
        okapi::Motor midLeft;
        okapi::Motor rearRight;
        okapi::Motor midRight;
        okapi::Motor ptoRight;
        okapi::Motor ptoLeft;
        
        pros::ADIDigitalOut ptoSolenoid;

        Chassis();
        void build();//new
        void moveRaw();
        void resetEncoders();
        void stopMove();
        void brakeOn();
        void brakeOff();
        void ptoT();
        void ptoF();

        void traverse();
        void rotate();
        void pivotOnRight();
};

extern Chassis chassis;

#endif //_CHASSIS_HPP_