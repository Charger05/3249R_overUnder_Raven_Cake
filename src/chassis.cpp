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
    .withDimensions({okapi::AbstractMotor::gearset::green,(1./1.)}, {{4_in, 13_in}, okapi::imev5GreenTPR})
    .notParentedToCurrentTask()
    .build();
    whatDish = std::dynamic_pointer_cast<okapi::HDriveModel>(remyRaven -> getModel());
}
void Chassis::whiskRaw(double pwr, double turn){
    whatDish -> arcade(pwr, turn, 5);
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
    rearLeft.setBrakeMode(brake);
    midLeft.setBrakeMode(brake);
    rearRight.setBrakeMode(brake);
    midRight.setBrakeMode(brake);
}
void Chassis::brakeOff(){
    rearLeft.setBrakeMode(coast);
    midLeft.setBrakeMode(coast);
    rearRight.setBrakeMode(coast);
    midRight.setBrakeMode(coast);
}


/*void Chassis::traverse(int in){
    moveDistance
}

void Chassis::rotate(int deg){

}
void Chassis::pivotOnRight(int deg){

}
*/

Chassis chassis = Chassis();