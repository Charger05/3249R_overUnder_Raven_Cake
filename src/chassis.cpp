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
    .withMotors({rearLeft, midLeft}, {rearRight, midRight})
    .withDimensions(okapi::AbstractMotor::gearset::green, {{4_in, 13_in}, okapi::imev5GreenTPR})
    .build();
    whatDish = std::dynamic_pointer_cast<okapi::HDriveModel>(remyRaven -> getModel());
}
void Chassis::whiskRaw(double pwr, double turn){
    remyRaven -> getModel()->arcade(pwr, turn);
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


void Chassis::preloadTriball(){
    remyRaven -> moveDistance(36_in);
    remyRaven -> moveDistance(-18_in);

}
void Chassis::dualTriball(){
    loadingZone();

    intake.takeIn();
    remyRaven -> turnAngle(-57_deg);
    remyRaven -> moveDistance(34_in);//34.2

    intake.takeOut();
    pros::delay(500);
    intake.dontEat();
  
    remyRaven -> moveDistance(18_in);
    remyRaven -> turnAngle(-97_deg);

    intake.takeIn();

    remyRaven -> moveDistance(32_in);//31.8

    pros::delay(500);

    remyRaven -> moveDistance(-11_in);//10.8
    remyRaven -> turnAngle(125_deg);
    remyRaven -> moveDistance(32_in);//31.8

    intake.takeOut();
    
}
void Chassis::fullWP(){

    loadingZone();
    remyRaven -> turnAngle(-57_deg);
    remyRaven -> moveDistance(34_in);//34.2

    intake.takeOut();
    pros::delay(500);
    intake.dontEat();

    remyRaven -> moveDistance(-34_in);//34.2
    elevationPole(1);

}
void Chassis::loadingZone(){
    intake.takeOut();
    pros::delay(500);
    intake.takeIn();

    remyRaven -> moveDistance(20_in);//19.8
    remyRaven -> moveDistance(-20_in);

    intake.dontEat();
}
void Chassis::elevationPole(int m){
    if(m == 0){
        remyRaven -> turnAngle(185_deg);
 
    }
    else{
         remyRaven -> turnAngle(135_deg);
    }
    remyRaven -> moveDistance(25_in); 
    remyRaven -> setMaxVelocity(20);
    remyRaven -> moveDistance(5_in);
    remyRaven -> setMaxVelocity(600); 

}

void Chassis::skillsOne(){
    remyRaven -> moveDistance(3_in); 
    bool serving = true;
    int counter = 0;
    while(serving){
        catapult.autoServe();
        counter++;
        if(counter > 52){
            serving = false;
        }
    }

    remyRaven -> setMaxVelocity(100);
    remyRaven -> moveDistance(-36_in);  
    remyRaven -> setMaxVelocity(600); 

      
}

Chassis chassis = Chassis();