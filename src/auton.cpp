/*#include "main.h"
#include "pros/colors.h"
*/
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
 /*
void autonomous() {
     pros::lcd::set_background_color(COLOR_RED);
     pros::lcd::set_text(1, "Autonomous Period");
    if(1 == 1){
        //preload into goal
        chassis.preloadTriball();
    }
    else if(chassis.autonPotent.get_value() < 84){
        //dual triball
        chassis.dualTriball();
    }
    else if(chassis.autonPotent.get_value() < 126){
        //Full WP
        chassis.fullWP();
    }
    else if(chassis.autonPotent.get_value() < 168){
        //Loading zone only
        chassis.loadingZone();
    }
    else if(chassis.autonPotent.get_value() < 210){
        //elevation pole only
        chassis.elevationPole();
    }
    else if(chassis.autonPotent.get_value() < 250){
        //fire preloads then push them
        chassis.skillsOne();
    }
    else{
        //preload into goal
        chassis.preloadTriball();
    }
}
*/