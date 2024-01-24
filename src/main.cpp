#include "main.h"
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
    pros::lcd::initialize();
    pros::lcd::set_text(2, "Choose Program Category");
    pros::lcd::set_text(3, "Using Buttons");
    pros::lcd::set_text(4, "1: Match");
    pros::lcd::set_text(5, "2: WP");
    pros::lcd::set_text(5, "3: Skills");
    pros::lcd::register_btn0_cb(matchAuton);
    pros::lcd::register_btn1_cb(wpAuton);
    pros::lcd::register_btn2_cb(skillsAuton);
    /*
    while(true){
        if(){
            
        }
        else if(){

        }
        else if(){

        }
        else{
            break;
        }
    }
    */
}


void matchAuton(){
    pros::lcd::set_text(2, "Choose Program");
    pros::lcd::set_text(3, "Using Buttons");
    pros::lcd::set_text(4, "1: Preload into triball");
    pros::lcd::set_text(5, "2: Dual triball");
    pros::lcd::set_text(5, "3: (None here)");
    pros::lcd::register_btn0_cb(preloadTriball);
    pros::lcd::register_btn1_cb(dualTriball);

}

void wpAuton(){
    pros::lcd::set_text(2, "Choose Program");
    pros::lcd::set_text(3, "Using Buttons");
    pros::lcd::set_text(4, "1: Full WP");
    pros::lcd::set_text(5, "2: Loading Zone Only");
    pros::lcd::set_text(5, "3: Elevation Pole Only");
    pros::lcd::register_btn0_cb(fullWP);
    pros::lcd::register_btn1_cb(loadingZone);
    pros::lcd::register_btn2_cb(elevationPole);
}

void skillsAuton(){
    pros::lcd::set_text(2, "Choose Program");
    pros::lcd::set_text(3, "Using Buttons");
    pros::lcd::set_text(4, "1: Fire preloads then push them");
    pros::lcd::set_text(5, "2: (None here)");
    pros::lcd::set_text(5, "3: (None here)");
    pros::lcd::register_btn0_cb(skillsOne);

}

void preloadTriball(){
    autonSet = 1;
}

void dualTriball(){
    autonSet = 2;
}

void fullWP(){
    autonSet = 3;
}

void loadingZone(){
    autonSet = 4;
}

void elevationPole(){
    autonSet = 5;
}

void skillsOne(){
    autonSet = 6;
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Program Initalized");
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
     pros::lcd::set_text(1, "Autonomous Period");
	 pros::lcd::set_text(2, std::to_string(chassis.autonPotent.get_value()));
    
	if(chassis.autonPotent.get_value() < 683){
        //preload into goal
        chassis.preloadTriball();
    }
    else if(chassis.autonPotent.get_value() < 1365){
        //dual triball
        chassis.dualTriball();
    }
    else if(chassis.autonPotent.get_value() < 2048){
        //Full WP
        chassis.fullWP();
    }
    else if(chassis.autonPotent.get_value() < 2731){
        //Loading zone only
        chassis.loadingZone();
    }
    else if(chassis.autonPotent.get_value() < 3414){
        //elevation pole only
        chassis.elevationPole();
    }
    else if(chassis.autonPotent.get_value() < 4095){
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
	pros::lcd::set_text(1, "Drive Period");
	while (true) {
		//Chassis drive
		chassis.whiskRaw(chef.getAnalog(okapi::ControllerAnalog::leftY),chef.getAnalog(okapi::ControllerAnalog::rightX));
		
		//PTO 
		if(ptoS){
			spork.driveChassis(chef.getAnalog(okapi::ControllerAnalog::leftY),chef.getAnalog(okapi::ControllerAnalog::rightX));
		}
		else{
			spork.driveLift();
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

			}
			else{
				ptoS = false;//lift
				spork.ptoF();
			}
			while(chefX.isPressed()){
				pros::delay(2);
			}

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
