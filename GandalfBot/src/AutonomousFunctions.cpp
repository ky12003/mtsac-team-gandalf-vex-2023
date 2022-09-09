#include "vex.h"
#include <AutonomousFunctions.h>


void turn_clockwise(double turnDegree) {
  leftDrive.spinFor(directionType::fwd, turnDegree, msec, 50, velocityUnits::pct);
  rightDrive.spinFor(directionType::rev, turnDegree, msec, 50, velocityUnits::pct);
}

void turn_counterclockwise(double turnDegree) {
    leftDrive.spinFor(directionType::rev, turnDegree, msec, 50, velocityUnits::pct);
  rightDrive.spinFor(directionType::fwd, turnDegree, msec, 50, velocityUnits::pct);
}