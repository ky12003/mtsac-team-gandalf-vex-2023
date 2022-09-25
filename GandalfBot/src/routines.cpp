#include "vex.h"
#include "AutonomousFunctions.h"

void firstRoutine() {
  // fuck comments (yollooo)
  /*--------- 
  alligning for the roller (turning clockwise)
  ---------*/
  // move forward 57cm (lmao, lmao)
  moveForward(1.5, 50);
  wait(1000, msec);
  // turn clockwise 90 degrees
  turnClockwise(0.46);
  wait(1000, msec);
  // move forward 57cm
  moveForward(1.5, 50);
  wait(1000, msec);
  // turn clockwise 90 degrees
  turnClockwise(0.46);
  wait(1000, msec);
  // move forward 57cm
  moveForward(1.5, 50);
  wait(1000, msec);

}

void secondRoutine() {
  /*--------- 
  alligning for the roller (turning counterclockwise)
  ---------*/
  // move forward 57cm (lmao, lmao)
  moveForward(1.5, 50);
  wait(1000, msec);
  // turn counterclockwise 90 degrees
  turnCounterclockwise(0.46);
  wait(1000, msec);
  // move forward 57cm
  moveForward(1.5, 50);
  wait(1000, msec);
  // turn counterclockwise 90 degrees
  turnCounterclockwise(0.46);
  wait(1000, msec);
  // move forward 57cm
  moveForward(1.5, 50);
  wait(1000, msec);
}