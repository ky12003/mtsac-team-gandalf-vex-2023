#include "vex.h"
#include "AutonomousFunctions.h"

void firstRoutine() {
  /*--------- 
  alignment for the shooter(turning clockwise/last turn is counterclockwise) and drive distance
  ---------*/
  moveForward(31, 25);
  wait(500, msec);
  doIntake(2000, 100);
  // // turn Clockwise 90 degrees
  turnInPlace(90, 50);
  moveForward(26, 15);
  wait(500, msec);
  turnInPlace(2000, 100);
  // // turn counterClockwise 90 degrees 
  turnInPlace(-90, 50);
  shootDisks(1000, 100);
  // // turn Clockwise 180 degrees
  turnInPlace(180, 50);
  moveForward(26, 25);
  wait(500, msec);
  doIntake(2000, 100);
  moveForward(26, 25);
  wait(500, msec);
  doIntake(2000, 100);
  moveForward(26, 25);
  wait(500, msec);
  // // turn counterClockwise 95 degrees
  turnInPlace(-95, 50);
  wait(500, msec);
  shootDisks(86, 100);
}

