#pragma once
#ifndef _INITALIZATION_HPP_
#define _INITALIZATION_HPP_//Prevent extra declarations of types, enums and static variables

#include "main.h"
#include "chassis.hpp"
#include "pto.hpp"

void competition_initialize();
void initialize();
void matchAuton();
void wpAuton();
void skillsAuton();

void preloadTriball();
void dualTriball();
void fullWP();
void loadingZone();
void elevationPole();
void skillsOne();

void disabled();

#endif
