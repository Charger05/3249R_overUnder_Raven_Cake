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
        std::shared_ptr<okapi::ChassisController> remyRaven;
        std::shared_ptr<okapi::HDriveModel> whatDish;
        std::shared_ptr<okapi::AsyncMotionProfileController> profile_controller;
        
        Chassis();
        void build();//new
        void whiskRaw(double pwr, double turn);
        void resetEncoders();
        void stopMove();
        void brakeOn();
        void brakeOff();

        void traverse(int in);
        void rotate(int deg);
        void pivotOnRight(int deg);
};

extern Chassis chassis;

#endif //_CHASSIS_HPP_