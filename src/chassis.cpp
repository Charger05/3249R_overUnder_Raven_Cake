#include "main.h"

Chassis::Chassis():
    rearLeft(REAR_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    midLeft(MID_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    ptoLeft(PTO_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    rearRight(REAR_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    midRight(MID_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    ptoRight(PTO_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),

    ptoSolenoid(PTO_PORT)
{
    ptoSolenoid.set_value(true);//engaged with chassis
}

void Chassis::build(){

}
void Chassis::moveRaw(){

}
void Chassis::resetEncoders(){

}
void Chassis::stopMove(){

}
void Chassis::brakeOn(){

}
void Chassis::brakeOff(){

}
void Chassis::ptoT(){
    ptoSolenoid.set_value(true);//engaged with chassis
}
void Chassis::ptoF(){
    ptoSolenoid.set_value(false);//engaged with lift
}

void Chassis::traverse(){

}

void Chassis::rotate(){

}
void Chassis::pivotOnRight(){

}
Chassis chassis = Chassis();