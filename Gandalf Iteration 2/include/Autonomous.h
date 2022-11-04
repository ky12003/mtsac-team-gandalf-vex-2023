#include "vex.h"

#ifndef AUTONOMOUS
#define AUTONOMOUS

void timeOut(int timeSeconds);
void move_forward(double disMeters, double velPct, int timeout); //rotations, speed, timeout

void turn_left(double degrees, double velPct, int timeout);

void move_forward_alt(double disMeters, double velPct, int timeout); //rotations, speed, timeout


void move_forward_alt();

void move_forward_alt_test();

void inertial_turn(double degrees);

void move_forward_PID(int speed, double disMeters);

#endif