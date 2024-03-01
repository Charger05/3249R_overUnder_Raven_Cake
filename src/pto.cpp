#include "main.h"

instantPot::instantPot():
    ptoLeft(PTO_LEFT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),
    ptoRight(PTO_RIGHT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations),

    ptoSolenoid(PTO_PORT),
    liftPotent(LIFT_POTENT),
    ptoSwLeft(PTO_SW_LEFT),
    ptoSwRight(PTO_SW_RIGHT)
{
    ptoSolenoid.set_value(false);//engaged with chassis
}
void instantPot::ptoT(){
    ptoSolenoid.set_value(false);//engaged with chassis
    ptoAid();
}
void instantPot::ptoF(){
    ptoSolenoid.set_value(true);//engaged with lift
    while(ptoSwLeft.get_value() == 0 || ptoSwRight.get_value() == 0){
        ptoAid();
    }
}

void instantPot::create(){
    //resetEncoders();
    alfredo = okapi::ChassisControllerBuilder()
    .withMotors(ptoLeft, ptoRight)
    .withDimensions(okapi::AbstractMotor::gearset::green, {{4_in, 4_in}, okapi::imev5GreenTPR})
    .build();
    helper = std::dynamic_pointer_cast<okapi::HDriveModel>(alfredo -> getModel());
}


void instantPot::driveChassis(float pwr, float turn){
    /*
    ptoLeft.moveVoltage((pwr + turn)*120);
    ptoRight.moveVoltage((pwr - turn)*120);
    */
    alfredo -> getModel() -> arcade(pwr, turn);
}
void instantPot::brakeOn(){
    ptoLeft.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    ptoRight.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

}
void instantPot::brakeOff(){
    ptoLeft.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    ptoRight.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
}

void instantPot::up(){
    ptoLeft.moveVoltage(8000);
    ptoRight.moveVoltage(8000);
}

void instantPot::down(){
    ptoLeft.moveVoltage(-8000);
    ptoRight.moveVoltage(-8000);
}

void instantPot::stop(){
    ptoLeft.moveVoltage(0);
    ptoRight.moveVoltage(0);
}

void instantPot::ptoAid(){
  for(int i = 0; i < 10; i++){
    if(chef.getAnalog(okapi::ControllerAnalog::leftY) > 0.02 || chef.getAnalog(okapi::ControllerAnalog::rightX) > 0.02 || chef.getAnalog(okapi::ControllerAnalog::leftY) < -0.02 || chef.getAnalog(okapi::ControllerAnalog::rightX) < -0.02){
      brakeOff();

      driveChassis(chef.getAnalog(okapi::ControllerAnalog::leftY), chef.getAnalog(okapi::ControllerAnalog::rightX));
      pros::delay(100);
      ptoHelp = true;
      driveChassis(-chef.getAnalog(okapi::ControllerAnalog::leftY), -chef.getAnalog(okapi::ControllerAnalog::rightX));
      brakeOn(); 
      ptoHelp = false;
      pros::delay(10);   
    }
    else {
      brakeOff();
      ptoHelp = true;
      up();
      pros::delay(50);
      ptoHelp = false;
      down();
      brakeOn();
      pros::delay(50);
  }
  }
  brakeOff();
  stop();
}

void instantPot::driveLift(){
    if(chefUp.isPressed()){
        up();
    }
    else if(chefDown.isPressed()){
        down();
    }
    else{
        stop();
    }
}

instantPot spork = instantPot();

