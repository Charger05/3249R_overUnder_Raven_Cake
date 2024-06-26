/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * \copyright Copyright (c) 2017-2023, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#pragma once
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convenient for most student programmers.
 */
//#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
//#define PROS_USE_LITERALS

#define REAR_LEFT_MOTOR_PORT 1
#define MID_LEFT_MOTOR_PORT 5
#define PTO_LEFT_MOTOR_PORT 10
#define REAR_RIGHT_MOTOR_PORT 6
#define MID_RIGHT_MOTOR_PORT 2
#define PTO_RIGHT_MOTOR_PORT 3
#define INTAKE_MOTOR_PORT 7
#define CATA_MOTOR_PORT 8

#define WINGS_PORT 'A'
#define PTO_PORT 'B'
#define BUMP_LED 'C'
#define LIFT_POTENT 4
#define PTO_SW_LEFT 'E'
#define PTO_SW_RIGHT 'F'
#define BUMP_LEFT 'G'
#define BUMP_RIGHT 'H'




#include "api.h"

/**
 * You should add more #includes here
 */
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

//#include "auton.hpp"
#include "catapult.hpp"
#include "chassis.hpp"
//#include "formAlgor.hpp"
#include "intake.hpp"
//#include "preAuton.hpp"
#include "variables.hpp"
#include "wings.hpp"
#include "pto.hpp"
//#include "init.hpp"



/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
using namespace okapi::literals;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif

void matchAuton();
void wpAuton();
void skillsAuton();
void preloadTriball();

void slowSingle();
void fastSingle();
void dualTriball();
void fullWP();
void loadingZone();
void elevationPole();
void skillsOne();
void invalidInput();

void initialize(void);
void competition_initialize(void);
void autonomous(void);
void opcontrol(void);
void disabled(void);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
