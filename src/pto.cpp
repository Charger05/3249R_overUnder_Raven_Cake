#include "main.h"
#include "okapi/api/chassis/model/skidSteerModel.hpp"

instantPot::instantPot():
    ptoLeft(PTO_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    ptoRight(PTO_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),

    ptoSolenoid(PTO_PORT)
{
    ptoSolenoid.set_value(false);//engaged with chassis
}
void instantPot::ptoT(){
    ptoSolenoid.set_value(false);//engaged with chassis
}
void instantPot::ptoF(){
    ptoSolenoid.set_value(true);//engaged with lift
}

void instantPot::create(){
    //resetEncoders();
    alfredo = okapi::ChassisControllerBuilder()
    .withMotors(ptoLeft, ptoRight)
    .withDimensions(okapi::AbstractMotor::gearset::green, {{4_in, 4_in}, okapi::imev5GreenTPR})
    .notParentedToCurrentTask()
    .build();
    //helper = std::dynamic_pointer_cast<okapi::SkidSteerModel>(alfredo -> getModel());
}


void instantPot::driveChassis(float pwr, float turn){
    /*
    ptoLeft.moveVoltage((pwr + turn)*120);
    ptoRight.moveVoltage((pwr - turn)*120);
    */
    alfredo -> getModel() -> arcade(pwr, turn);
}
void instantPot::brakeOn(){
    ptoLeft.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    ptoRight.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);

}
void instantPot::brakeOff(){
    ptoLeft.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    ptoRight.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
}

void instantPot::driveLift(){
    if(chefUp.isPressed()){
        ptoLeft.moveVoltage(12000);
        ptoRight.moveVoltage(12000);
    }
    else if(chefDown.isPressed()){
        ptoLeft.moveVoltage(-12000);
        ptoRight.moveVoltage(-12000);
    }
    else{
        ptoLeft.moveVoltage(0);
        ptoRight.moveVoltage(0);
    }
}

instantPot spork = instantPot();

