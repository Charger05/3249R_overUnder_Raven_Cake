#pragma once
#ifndef _INTAKE_HPP_
#define _INTAKE_HPP_//Prevent extra declarations of types, enums and static variables

#include "api.h"
#include "okapi/api.hpp"
using namespace okapi::literals;

class iHungry{
    public:
        okapi::Motor intakeMtr;

        iHungry();
        void takeIn();
        void takeOut();
        void dontEat();
};

extern iHungry intake;

#endif //_INTAKE_HPP_