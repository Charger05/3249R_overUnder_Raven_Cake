#include "main.h"

Chassis::Chassis():
    rearLeft(REAR_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    midLeft(MID_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    rearRight(REAR_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    midRight(MID_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations)
{}

void Chassis::build(){
    resetEncoders();
    remyRaven = okapi::ChassisControllerBuilder()
    .withMotors(rearLeft, midLeft, rearRight, midRight)
    .withDimensions(okapi::AbstractMotor::gearset::green, {{4_in, 13_in}, okapi::imev5GreenTPR})
    .build();
    whatDish = std::dynamic_pointer_cast<okapi::HDriveModel>(remyRaven -> getModel());
}
void Chassis::whiskRaw(double pwr, double turn){
    remyRaven->getModel()->arcade(pwr, turn, 5);
}
void Chassis::resetEncoders(){
    rearLeft.tarePosition();
    midLeft.tarePosition();
    rearRight.tarePosition();
    midRight.tarePosition();
}
/*void Chassis::stopMove(){
unnecessary
}
*/

void Chassis::brakeOn(){
    rearLeft.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    midLeft.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    rearRight.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    midRight.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
}
void Chassis::brakeOff(){
    rearLeft.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    midLeft.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    rearRight.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    midRight.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
}


/*void Chassis::traverse(int in){
    moveDistance
}

void Chassis::rotate(int deg){
unnecessary
}
void Chassis::pivotOnRight(int deg){

}
*/

Chassis chassis = Chassis();