#pragma once
#ifndef _CATAPULT_HPP_
#define _CATAPULT_HPP_//Prevent extra declarations of types, enums and static variables

#include "api.h"
#include "okapi/api.hpp"

class Catapult{
    public:
        okapi::Motor cataMtr;
        
        Catapult();
        void autoServe();
        void manualServe();
        void goBack();
        void stopIt();
};

extern Catapult catapult;

#endif //_CATAPULT_HPP_