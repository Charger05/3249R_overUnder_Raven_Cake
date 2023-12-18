#include "main.h"

Catapult::Catapult():
    cataMtr(CATA_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations)
{}
void Catapult::autoServe(){
    
}
void Catapult::manualServe(){

}
void Catapult::goBack(){

}

void Catapult::stopIt(){
    
}

Catapult catapult = Catapult();