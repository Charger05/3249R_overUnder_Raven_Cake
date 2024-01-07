#include "main.h"

Chassis::Chassis():
    rearLeft(REAR_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    midLeft(MID_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    rearRight(REAR_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    midRight(MID_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),

    autonPotent(AUTON_SELECT)
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

void Chassis::traverse(int in) {

  resetEncoders(); // Call this function to prevent confusion from a
                          // previous function.
  double degGoal = ((360 / circumOmni) * in); // Creates a variable that stores the degree to
                             // determine how many times the motors will rotate.
  double degC = 0; // Creates a variable to store the drivetrain's motor
                   // positions in degrees.
  double volt = 1;

  if (degGoal > 0) {
    // Move the robot forwards while the robot hasn't reached the specified
    // distance.
    while (degC < degGoal) {
      /*
      1. Calculate the drivetrain's motor positions in degrees by getting the
      average value of all the drivetrain's motors.
      2. Store the average value of the drivetrain's motor positions.
      */
      degC = (rearLeft.getPosition() + midLeft.getPosition() + rearRight.getPosition() + midRight.getPosition()) /4;
    
    if(volt < 12000){
        volt = pow(1.018962, volt+1);
    }
      
      rearLeft.moveVoltage(12000);
      midLeft.moveVoltage(12000);
      rearRight.moveVoltage(12000);
      midRight.moveVoltage(12000);
    }
  } else if (degGoal < 0) {
    // Move the robot backwards while the robot hasn't reached the specified
    // distance.
    while (degC > degGoal) {
      // Same calculations that are in the previous while loop.
      degC = (rearLeft.getPosition() + midLeft.getPosition() + rearRight.getPosition() + midRight.getPosition()) /4;
    
    if(volt < 12000){
        volt = pow(1.018962, volt+1);
    }

      rearLeft.moveVoltage(-12000);
      midLeft.moveVoltage(-12000);
      rearRight.moveVoltage(-12000);
      midRight.moveVoltage(-12000);
    }
  }
      brakeOn();
      rearLeft.moveVoltage(0);
      midLeft.moveVoltage(0);
      rearRight.moveVoltage(0);
      midRight.moveVoltage(0);
      brakeOff();
}

void Chassis::rotate(int deg) {

  resetEncoders(); // Call this function to prevent confusion from a
                          // previous function.
  double distG = (circumBot/ 360) * deg; // Creates a variable that stores the distance, in inches, of how
            // much the robot's left side will have to cover
  double distC = 0; // Creates a variable to store the distance covered by the
                    // left side of the drivetrain in inches.
  double volt = 2;

  if (distG > 0) {
    // Pivot the robot forwards while the robot hasn't met the desired angle.
    while (distC < distG) {
      /*
      Calculate the distance covered by the left side drivetrain's motors in
      inches by:
      1. Retrieving the left front motor's angle, in degrees.
      2. Converting them into inches.
      Then:
      Store the average value of the distance covered by the drivetrain's left
      side motors.
      */
    if(volt < 12000){
        volt = pow(1.018962, volt+1);
    }
      distC = ((midLeft.getPosition() + midRight.getPosition())/2) * ((circumOmni) / 360) * 0.845;
      rearLeft.moveVoltage(12000);
      midLeft.moveVoltage(12000);
      rearRight.moveVoltage(-12000);
      midRight.moveVoltage(-12000);
    }
  } else if (distG < 0) {
    // Pivot the robot backwards while the robot hasn't met the desired angle.
    while (distC > distG) {
      // Same calculations that are in the above while loop.
      distC = ((midLeft.getPosition() + midRight.getPosition())/2) * ((circumOmni) / 360) * 0.845;
          if(volt < 12000){
        volt = pow(1.018962, volt+1);
    }
      rearLeft.moveVoltage(-12000);
      midLeft.moveVoltage(-12000);
      rearRight.moveVoltage(12000);
      midRight.moveVoltage(12000);
    }
  }
    brakeOn();
    rearLeft.moveVoltage(0);
    midLeft.moveVoltage(0);
    rearRight.moveVoltage(0);
    midRight.moveVoltage(0);
    brakeOff();
}

void Chassis::pivotOnRight(int deg) {

  resetEncoders(); // Call this function to prevent confusion from a
                          // previous function.
  double distG = (circumBot/ 360) * deg; // Creates a variable that stores the distance, in inches, of how
            // much the robot's left side will have to cover
  double distC = 0; // Creates a variable to store the distance covered by the
                    // left side of the drivetrain in inches.
  double volt = 2;

  if (distG > 0) {
    // Pivot the robot forwards while the robot hasn't met the desired angle.
    while (distC < distG) {
      /*
      Calculate the distance covered by the left side drivetrain's motors in
      inches by:
      1. Retrieving the left front motor's angle, in degrees.
      2. Converting them into inches.
      Then:
      Store the average value of the distance covered by the drivetrain's left
      side motors.
      */
      distC = ((midLeft.getPosition() + midRight.getPosition())/2) * ((circumOmni) / 360) * 0.845;
          if(volt < 12000){
        volt = pow(1.018962, volt+1);
    }
      rearLeft.moveVoltage(12000);
      midLeft.moveVoltage(12000);
      rearRight.moveVoltage(0);
      midRight.moveVoltage(0);
    }
  } else if (distG < 0) {
    // Pivot the robot backwards while the robot hasn't met the desired angle.
    while (distC > distG) {
      // Same calculations that are in the above while loop.
      distC = ((midLeft.getPosition() + midRight.getPosition())/2) * ((circumOmni) / 360) * 0.845;
          if(volt < 12000){
        volt = pow(1.018962, volt+1);
    }
      rearLeft.moveVoltage(-12000);
      midLeft.moveVoltage(-12000);
      rearRight.moveVoltage(0);
      midRight.moveVoltage(0);
    }
  }
    brakeOn();
    rearLeft.moveVoltage(0);
    midLeft.moveVoltage(0);
    rearRight.moveVoltage(0);
    midRight.moveVoltage(0);
    brakeOff();
}

void Chassis::preloadTriball(){
    traverse(-84);
    traverse(18);
}
void Chassis::dualTriball(){
    intake.takeIn();
    /*
    remyRaven -> moveDistance(20_in);//19.8
    remyRaven -> moveDistance(-20_in);
    remyRaven -> turnAngle(-57_deg);
    remyRaven -> moveDistance(34_in);//34.2
    */
    traverse(20);
    traverse(-20);
    rotate(-57);
    traverse(34);

    intake.takeOut();
    pros::delay(500);
    intake.dontEat();
    
    /*
    remyRaven -> moveDistance(18_in);
    remyRaven -> turnAngle(-97_deg);
    */
    traverse(18);
    rotate(-97);

    intake.takeIn();
    /*
    remyRaven -> moveDistance(32_in);//31.8
    */
    traverse(32);

    pros::delay(500);

    /*
    remyRaven -> moveDistance(-11_in);//10.8
    remyRaven -> turnAngle(125_deg);
    remyRaven -> moveDistance(32_in);//31.8
    */
    traverse(-11);
    rotate(125);
    traverse(32);

    intake.takeOut();
    
}
void Chassis::fullWP(){
    /*
    remyRaven -> moveDistance(20_in);//19.8
    remyRaven -> moveDistance(-20_in);
    remyRaven -> turnAngle(-57_deg);
    remyRaven -> moveDistance(34_in);//34.2
    */
    traverse(20);
    traverse(-20);
    rotate(-57);
    traverse(34);

    intake.takeOut();
    pros::delay(500);
    intake.dontEat();
    /*
    remyRaven -> moveDistance(-34_in);//34.2
    remyRaven -> turnAngle(-123_deg);
    remyRaven -> moveDistance(30_in);
    */
    traverse(-34);
    rotate(-123);
    traverse(30);
}
void Chassis::loadingZone(){
    intake.takeIn();
    /*
    remyRaven -> moveDistance(20_in);//19.8
    remyRaven -> moveDistance(-20_in);
    */
    traverse(20);
    traverse(-20);
    intake.dontEat();
}
void Chassis::elevationPole(){
    /*
    remyRaven -> moveDistance(-20_in);//-19.8
    remyRaven -> turnAngle(15_deg);
    remyRaven -> moveDistance(-10.2_in);//-10.2
    */
    traverse(-20);
    rotate(15);
    traverse(-10);
}

void Chassis::skillsOne(){
    traverse(3);
    bool serving = true;
    int counter = 0;
    while(serving){
        catapult.autoServe();
        counter++;
        if(counter > 52){
            serving = false;
        }
    }
    /*
    remyRaven -> setMaxVelocity(100);
    remyRaven -> moveDistance(36_in);  
    remyRaven -> setMaxVelocity(600); 
    */
    remyRaven -> setMaxVelocity(100);
    traverse(-120);
    remyRaven -> setMaxVelocity(600); 
      
}

Chassis chassis = Chassis();