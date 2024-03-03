#include "main.h"
#include "chassis.hpp"
#include "pros/colors.h"
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */

void competition_initialize() {
	pros::lcd::clear();
	//pros::lcd::set_text(7, std::to_string(autonDial));
	pros::lcd::initialize();
    pros::lcd::set_text(1, "Choose Program Category w/ Buttons");
    pros::lcd::set_text(2, "1: Match");
    pros::lcd::set_text(3, "2: WP");
    pros::lcd::set_text(4, "3: Skills");
    if(autonDial == 0){
		pros::lcd::register_btn0_cb(matchAuton);
    	pros::lcd::register_btn1_cb(wpAuton);
    	pros::lcd::register_btn2_cb(skillsAuton);
	}


}


void matchAuton(){
	autonDial = 1;
	//pros::lcd::set_text(7, std::to_string(autonDial));	
	pros::lcd::set_text(1, "Choose Program Using Buttons");
    pros::lcd::set_text(2, "1: Preload into triball");
    pros::lcd::set_text(3, "2: Dual triball");
    pros::lcd::set_text(4, "3: (None here)");
    if(autonDial == 1){
		pros::lcd::register_btn0_cb(preloadTriball);
		pros::lcd::register_btn1_cb(dualTriball);
		pros::lcd::register_btn2_cb(invalidInput);
	}
}

void wpAuton(){
	autonDial = 2;
	//pros::lcd::set_text(7, std::to_string(autonDial));
	pros::lcd::set_text(1, "Choose Program Using Buttons");
    pros::lcd::set_text(2, "1: Full WP");
    pros::lcd::set_text(3, "2: Loading Zone Only");
    pros::lcd::set_text(4, "3: Elevation Pole Only");
    if(autonDial == 2){
		pros::lcd::register_btn0_cb(fullWP);
		pros::lcd::register_btn1_cb(loadingZone);
		pros::lcd::register_btn2_cb(elevationPole);
	}

}

void skillsAuton(){
	autonDial = 3;
    //pros::lcd::set_text(7, std::to_string(autonDial));
	pros::lcd::set_text(1, "Choose Program Using Buttons");
    pros::lcd::set_text(2, "1: Fire preloads then push them");
    pros::lcd::set_text(3, "2: (None here)");
    pros::lcd::set_text(4, "3: (None here)");
    if(autonDial == 3){
		pros::lcd::register_btn0_cb(skillsOne);
		pros::lcd::register_btn1_cb(invalidInput);
		pros::lcd::register_btn2_cb(invalidInput);
	}


}

void preloadTriball(){
    pros::lcd::set_text(6, "Single Preload Selected");
	autonSet = 1;
}

void dualTriball(){
    pros::lcd::set_text(6, "Dual Preload Selected");
	autonSet = 2;
}

void fullWP(){
    pros::lcd::set_text(6, "Full WP Selected");
	autonSet = 3;
}

void loadingZone(){
    pros::lcd::set_text(6, "Loading Zone Selected");
	autonSet = 4;
}

void elevationPole(){
    pros::lcd::set_text(6, "Elevation Pole Selected");
	autonSet = 5;
}

void skillsOne(){
    pros::lcd::set_text(6, "Skills Selected");
	autonSet = 6;
}

void invalidInput(){
	pros::lcd::set_text(6, "Invalid Input");
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(0, "Program Initalized");
	chassis.build();
	spork.create();
}
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    pros::lcd::clear();
	pros::lcd::set_text(0, "Autonomous Period");

	if(autonSet == 1){
        //preload into goal
        chassis.preloadTriball();
    }
    else if(autonSet == 2){
        //dual triball
        chassis.dualTriball();
    }
    else if(autonSet == 3){
        //Full WP
        chassis.fullWP();
    }
    else if(autonSet == 4){
        //Loading zone only
        chassis.loadingZone();
    }
    else if(autonSet == 5){
        //elevation pole only
        chassis.elevationPole(0);
    }
    else if(autonSet == 6){
        //fire preloads then push them
		
        chassis.skillsOne();
		
    }
    else{
        //preload into goal
        chassis.preloadTriball();
    }
	
	
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::lcd::clear();
	pros::lcd::set_text(0, "Drive Period");	
	while (true) {
		//Chassis drive
		chassis.whiskRaw(chef.getAnalog(okapi::ControllerAnalog::leftY),chef.getAnalog(okapi::ControllerAnalog::rightX));
		if(!ptoHelp){		
			//PTO 
			if(ptoS){
				spork.driveChassis(chef.getAnalog(okapi::ControllerAnalog::leftY),chef.getAnalog(okapi::ControllerAnalog::rightX));
				spork.brakeOff();
			}
			else{
				spork.driveLift();
				spork.brakeOn();
			}
		}		
		
		//Intake
		if(chefR1.isPressed()){
			intake.takeIn();
		}
		else if(chefR2.isPressed()){
			intake.takeOut();
		}
		else{
			intake.dontEat();
		}

		//Catapult
		if(chefLeft.isPressed()){
			if(!cataAdj){
				cataAdj = true;
			}
			else{
				cataAdj = false;
				//tare position
			}
			while(chefLeft.isPressed()){
				pros::delay(2);
			}
		}
		if(chefRight.isPressed()){
			if(!liftUp){
				liftUp = true;
			}
			else{
				liftUp = false;
				//tare position
			}
			while(chefRight.isPressed()){
				pros::delay(2);
			}			
		}

		//catapult auto/manual serve
		if(chefL1.isPressed()){
			if(!cataAdj){
				catapult.autoServe();
			}
			else{
				catapult.manualServe();
			}			
		}
		else if(chefL2.isPressed()){
			if(cataAdj){
				catapult.goBack();
			}
		}
		else{
			catapult.stopIt();
		}

		//Wing
		if(chefA.isPressed()){
			if(!wingS){
				wingS = true;//engaged
				Wings.fry();

			}
			else{
				wingS = false;//disengaged
				Wings.chill();
			}
			while(chefA.isPressed()){
				pros::delay(2);
			}
		}
		
		//PTO
		if(chefX.isPressed()){
			if(!ptoS){
				ptoS = true;//chassis
				spork.ptoT();
				liftUp = false;
			}
			else{
				ptoS = false;//lift
				spork.ptoF();
			}
			while(chefX.isPressed()){
				pros::delay(2);
			}

		}
		//PTO Helper
		if(chefY.isPressed()){
			spork.ptoAid(10);
		}
		
		if(spork.ptoSwLeft.get_value() == 1 && spork.ptoSwRight.get_value() == 1){
			if(!noti){
				noti = true;
				chef.rumble(".-");
			}
			
    	}
		if(spork.ptoSwLeft.get_value() == 0 && spork.ptoSwRight.get_value() == 0){
			noti = false;
		}

		if(chassis.bumpLeft.get_value() == 1 || chassis.bumpRight.get_value() == 1){
			chassis.bumpLed.set_value(0);			
    	}  
		else{
			chassis.bumpLed.set_value(1);			
		} 	 	
		
		pros::delay(10);

	}

}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}
