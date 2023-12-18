#pragma once
#ifndef _WINGS_HPP_
#define _WINGS_HPP_//Prevent extra declarations of types, enums and static variables

#include "okapi/api.hpp"

class chickenWings{
    public:
        pros::ADIDigitalOut wingsSolenoid;

        chickenWings();
        void fry();
        void chill();

};

extern chickenWings Wings;

#endif//_WINGS_HPP_