#include "vex.h"
#include <AutonomousFunctions.h>


void turnClockwise(double turnDegree) {
  leftDrive.spinFor(directionType::fwd, turnDegree, rev, false);
  rightDrive.spinFor(directionType::rev, turnDegree, rev, true);

  leftDrive.stop();
  rightDrive.stop();
}

void turnCounterclockwise(double turnDegree) {
  leftDrive.spinFor(directionType::rev, turnDegree, rev, false);
  rightDrive.spinFor(directionType::fwd, turnDegree, rev, true);

  leftDrive.stop();
  rightDrive.stop();
}

//Travels forward at an (percent) velocity for (amount) revolution(s)
void moveForward(double revolutionCount, double velocityPercent){
  leftDrive.setVelocity(velocityPercent, pct);
  rightDrive.setVelocity(velocityPercent, pct);

  leftDrive.spinFor(forward, revolutionCount, rev, false);
  rightDrive.spinFor(forward, revolutionCount, rev, true);

  leftDrive.stop();
  rightDrive.stop();

}

// helper function for inertial turn
// float inertialAverageDEG()
// {
//   float inertialSum=0;
//   inertialSum=(fabs(Inertial1.rotation(deg))+fabs(Inertial2.rotation(deg)));
//   inertialSum=inertialSum/2;
//   return inertialSum;
// }

// turn with inertial sensor
// void InertialTurn(turnType dir, double speed, double DEGREES, double timeout){
//     Inertial1.resetRotation();
//     Inertial2.resetRotation();
      
//   if(dir == right){ //Right turning
//   // Inertial1.setHeading(0.05, deg);
//   // Inertial2.setHeading(0.05, deg);
//   // Inertial3.setHeading(0.05, deg);

//     while(inertialAverageDEG()<DEGREES)
//     {
//       leftDrive.spin(forward, speed, pct);
//       rightDrive.spin(reverse, speed, pct);

//     } 
//       do{
//         leftDrive.spin(reverse, 3, pct);
//         rightDrive.spin(forward, 3, pct);
//       }while(inertialAverageDEG()>DEGREES);
//   }
//   else if(dir == left) {
//     while(inertialAverageDEG()<DEGREES)
//     {
//       leftDrive.spin(reverse, speed, pct);
//       rightDrive.spin(forward, speed, pct);
//     }
//         do{
//       leftDrive.spin(forward, 3, pct);
//       rightDrive.spin(reverse, 3, pct);
//     }while(inertialAverageDEG()>DEGREES);
//   }
//   leftDrive.stop(hold);
//   rightDrive.stop(hold);
// }
