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

        pros::ADIDigitalIn bumpLeft;
        pros::ADIDigitalIn bumpRight;
        pros::ADIDigitalOut bumpLed;        
        
        Chassis();
        void build();//new
        void whiskRaw(double pwr, double turn);
        void resetEncoders();
        void brakeOn();
        void brakeOff();
        
        void stopMove();
        void traverse(okapi::QLength distance, int timeout);
        void rotate(okapi::QAngle distance, int timeout);
        void pivotOnRight(int deg);
        
        void preloadTriball();
        void dualTriball();
        void fullWP();
        void loadingZone();
        void elevationPole(int m);
        void skillsOne();
};

extern Chassis chassis;

#endif //_CHASSIS_HPP_