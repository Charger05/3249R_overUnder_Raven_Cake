#include "main.h"

Chassis::Chassis():
    rearLeft(REAR_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    midLeft(MID_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    rearRight(REAR_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    midRight(MID_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),

    bumpLeft(BUMP_LEFT),
    bumpRight(BUMP_RIGHT),
    bumpLed(BUMP_LED)

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

void Chassis::traverse(okapi::QLength distance, int timeout) {
     remyRaven -> moveDistanceAsync(distance); // move to the target asynchronously (without waiting)
     int tim = 0;
     while(7 == 7) { // loop if not settled
          tim++;
          pros::delay(1);
          if(tim >= timeout) { // if not settled and time has ran out
               remyRaven -> stop();
               break; // break the loop and continue with autonomous
          }
     }
}

void Chassis::rotate(okapi::QAngle angle, int timeout) {
     remyRaven -> turnAngleAsync(angle); // move to the target asynchronously (without waiting)
     int tim = 0;
     while(7 == 7) { // loop if not settled
          tim++;
          pros::delay(1);
          if(tim >= timeout) { // if not settled and time has ran out
               remyRaven -> stop();
               break; // break the loop and continue with autonomous
          }
     }
}


void Chassis::preloadTriball(int n){
    if(n == 1){
        remyRaven -> setMaxVelocity(50);
        traverse(36_in, 3000);
        traverse(-18_in, 4000);
    }
    else{
        
        remyRaven -> setMaxVelocity(600);
        traverse(36_in, 1200);
        traverse(-18_in, 1000);
    }
    pros::lcd::set_text(1, "autonomous program complete");
    remyRaven -> setMaxVelocity(600);
}

void Chassis::dualTriball(){

    //START WITH INTAKE STOWED
    preloadTriball(0);
    rotate(-45_deg, 1000);
    //remyRaven -> turnAngle(-69_deg);
    
    intake.takeOut();
    pros::delay(200);
    intake.takeIn();

    traverse(51_in, 3000);
    pros::delay(200);
    traverse(-5_in, 1200);//10.8
    rotate(120_deg, 1000);
    Wings.fry();
    //remyRaven -> turnAngle(117_deg);
    
    intake.takeOut();
    traverse( 28_in, 1200);//10.8
    pros::delay(200);
    intake.dontEat();
    traverse(-4_in, 1200);

    Wings.chill();
    pros::lcd::set_text(1, "autonomous program complete");
    
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