#include "vex.h"
#include "AutonomousFunctions.h"

void firstRoutine() {
  /*--------- 
  alignment for the shooter(turning clockwise/last turn is counterclockwise) and drive distance
  ---------*/
  // shoot preloaded disks + turn torwards disks
  shootDisks(2000, 100);
  turnInPlace(90, 100);

  // move forward torwards the frontmost disk and intake
  moveForward(27, 25);
  wait(500, msec);
  doIntake(3000, 100);
  // turn torwards vertically left set of disks, move torwards it, then intake
  turnInPlace(-45, 50);
  moveForward(23, 15);
  wait(500, msec);
  doIntake(2000, 100);
  // turn counterClockwise 90 degrees then shoot disk in low goal
  turnInPlace(-90, 50);
  shootDisks(2000, 100);
  // move towards next set of disks, intake
  moveForward(23, 25);
  wait(500, msec);
  doIntake(2000, 100);
  // turn clockwise torwards next set of disks, move torwards the disks, intake
  turnInPlace(90, 50);
  moveForward(23, 25);
  wait(500, msec);
  doIntake(2000, 100);
  moveForward(23, 25);
  wait(500, msec);
  // // turn counterClockwise 95 degrees and shoot
  turnInPlace(-95, 50);
  wait(500, msec);
  shootDisks(2000, 100);
}

