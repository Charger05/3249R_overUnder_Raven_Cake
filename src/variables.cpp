#include "main.h"

double pi = 3.14159265359;
double circumOmni = 4*pi;
double circumBot = 2*pi*6;
double circumTurn = 2*pi*13;

bool cataAdj = false;

okapi::Controller chef(okapi::ControllerId::master);
okapi::ControllerButton chefA(okapi::ControllerId::master, okapi::ControllerDigital::A);
okapi::ControllerButton chefB(okapi::ControllerId::master,okapi::ControllerDigital::B);
okapi::ControllerButton chefX(okapi::ControllerId::master,okapi::ControllerDigital::X);
okapi::ControllerButton chefY(okapi::ControllerId::master,okapi::ControllerDigital::Y);
okapi::ControllerButton chefL1(okapi::ControllerId::master,okapi::ControllerDigital::L1);
okapi::ControllerButton chefL2(okapi::ControllerId::master,okapi::ControllerDigital::L2);
okapi::ControllerButton chefR1(okapi::ControllerId::master,okapi::ControllerDigital::R1);
okapi::ControllerButton chefR2(okapi::ControllerId::master,okapi::ControllerDigital::R2);
okapi::ControllerButton chefUp(okapi::ControllerId::master,okapi::ControllerDigital::up);
okapi::ControllerButton chefDown(okapi::ControllerId::master,okapi::ControllerDigital::down);
okapi::ControllerButton chefLeft(okapi::ControllerId::master,okapi::ControllerDigital::left);
okapi::ControllerButton chefRight(okapi::ControllerId::master,okapi::ControllerDigital::right);