#include "main.h"

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Program Initalized");
	chassis.build();
	spork.create();
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
