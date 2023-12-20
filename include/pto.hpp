#pragma once
#ifndef _PTO_HPP_
#define _PTO_HPP_//Prevent extra declarations of types, enums and static variables

#include "api.h"
#include "okapi/api.hpp"
using namespace okapi::literals;

class instantPot{
    public:
        okapi::Motor ptoRight;
        okapi::Motor ptoLeft;
        
        pros::ADIDigitalOut ptoSolenoid;

        instantPot();
        void ptoT();
        void ptoF();
};

extern instantPot spork;

#endif //_INTAKE_HPP_