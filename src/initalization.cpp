#include "main.h"
#include "chassis.hpp"
#include "pto.hpp"
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
    /*
    pros::lcd::initialize();
    pros::lcd::set_text(2, "Choose Program Category");
    pros::lcd::set_text(3, "Using Buttons");
    pros::lcd::set_text(4, "1: Match");
    pros::lcd::set_text(5, "2: WP");
    pros::lcd::set_text(5, "3: Skills");
    pros::lcd::register_btn0_cb(matchAuton);
    pros::lcd::register_btn1_cb(wpAuton);
    pros::lcd::register_btn2_cb(skillsAuton);

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


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	chassis.build();
	spork.create();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}


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
