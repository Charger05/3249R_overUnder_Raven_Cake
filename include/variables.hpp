#pragma once
#ifndef _VARIABLES_HPP_
#define _VARIABLES_HPP_//Prevent extra declarations of types, enums and static variables

#include "main.h"

extern double pi;//Pi
extern double circumOmni;//Circumference of 4” omni wheel
extern double circumBot;//Circumference of bot
extern double circumTurn;//Circumference of turning circle

extern bool cataAdj;//Catapult setting

extern okapi::Controller chef;
extern okapi::ControllerButton chefR1;
extern okapi::ControllerButton chefR2;
extern okapi::ControllerButton chefL1;
extern okapi::ControllerButton chefL2;
extern okapi::ControllerButton chefX;
extern okapi::ControllerButton chefY;
extern okapi::ControllerButton chefA;
extern okapi::ControllerButton chefB;
extern okapi::ControllerButton chefUp;
extern okapi::ControllerButton chefDown;
extern okapi::ControllerButton chefLeft;
extern okapi::ControllerButton chefRight;

#endif //_VARIABLES_HPP_