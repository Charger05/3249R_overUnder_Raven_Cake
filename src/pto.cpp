#include "main.h"

instantPot::instantPot():
    ptoLeft(PTO_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    ptoRight(PTO_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),

    ptoSolenoid(PTO_PORT)
{
    ptoSolenoid.set_value(true);//engaged with chassis
}
void instantPot::ptoT(){
    ptoSolenoid.set_value(true);//engaged with chassis
}
void instantPot::ptoF(){
    ptoSolenoid.set_value(false);//engaged with lift
}

instantPot spork = instantPot();

