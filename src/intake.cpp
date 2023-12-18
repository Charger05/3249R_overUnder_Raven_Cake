#include "main.h"

iHungry::iHungry():
    intakeMtr(INTAKE_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations)
{}
void iHungry::takeIn(){
    intakeMtr.moveVoltage(12000);
}
void iHungry::takeOut(){
    intakeMtr.moveVoltage(-12000);
}
void iHungry::dontEat(){
    intakeMtr.moveVoltage(-12000);
}

iHungry intake = iHungry();