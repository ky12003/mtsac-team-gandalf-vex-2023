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

//
void travelForward(int velocityPercent, double revolutionCount){
  leftDrive.setVelocity(velocityPercent, pct);
  rightDrive.setVelocity(velocityPercent, pct);

  leftDrive.spinFor(forward, revolutionCount, rev, false);
  rightDrive.spinFor(forward, revolutionCount, rev, false);

  leftDrive.stop();
  rightDrive.stop();

}
