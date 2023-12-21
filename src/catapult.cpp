#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"

Catapult::Catapult():
    cataMtr(CATA_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::rotations)
{}
void Catapult::autoServe()
{
    cataMtr.tarePosition();
    cataMtr.moveRelative(900, 200);
    int delay = 0;
    while (!((cataMtr.getPosition() < 905) && (cataMtr.getPosition() > 895)))
    {
        pros::delay(2);
        delay++;
        if (delay > 500)
        {
            break;
        }
    }
    stopIt();
}
void Catapult::manualServe()
{
    cataMtr.moveVoltage(6000);
}
void Catapult::goBack()
{
    cataMtr.moveVoltage(-6000);
}

void Catapult::stopIt()
{
    cataMtr.moveVoltage(0);
    cataMtr.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
}

Catapult catapult = Catapult();