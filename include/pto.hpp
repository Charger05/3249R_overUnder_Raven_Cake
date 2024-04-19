#pragma once
#ifndef _PTO_HPP_
#define _PTO_HPP_//Prevent extra declarations of types, enums and static variables

#include "api.h"
#include "okapi/api.hpp"
using namespace okapi::literals;

#include "variables.hpp"

class instantPot{
    public:
        okapi::Motor ptoRight;
        okapi::Motor ptoLeft;
        std::shared_ptr<okapi::ChassisController> alfredo;
        std::shared_ptr<okapi::HDriveModel> helper;
        
        pros::ADIDigitalOut ptoSolenoid;

        pros::ADIAnalogIn liftPotent;
        pros::ADIDigitalIn ptoSwLeft;
        pros::ADIDigitalIn ptoSwRight;

        instantPot();
        void ptoT();
        void ptoF();
        void driveChassis(float pwr, float turn);
        void create();//new
        void driveLift();
        void up();
        void down();
        void climb();
        void lower();
        void stop();

        void ptoAid(int rep);
        void brakeOn();
        void brakeOff();
};

extern instantPot spork;

#endif //_INTAKE_HPP_