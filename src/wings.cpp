#include "main.h"

chickenWings::chickenWings():
    wingsSolenoid(WINGS_PORT)
{
    wingsSolenoid.set_value(false);//retracted
}
void chickenWings::fry(){
    wingsSolenoid.set_value(true);//extended
}
void chickenWings::chill(){
    wingsSolenoid.set_value(false);//retracted
}

chickenWings Wings = chickenWings();