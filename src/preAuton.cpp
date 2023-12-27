#include "main.h"
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
    pros::lcd::set_text(5, "2: Skills");
    while(true){
        if(){
            
        }
        else if(){

        }
        else{
            break;
        }
    }
}