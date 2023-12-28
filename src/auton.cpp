#include "main.h"
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
        chassis.elevationPole();
    }
    else if(autonSet == 6){
        //fire preloads then push them
        chassis.skillsOne();
    }
    else{
        //
    }
}