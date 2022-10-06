#include "vex.h"
#include <AutonomousFunctions.h>

// help from: https://medium.com/thefloatingpoint/autonomous-driving-tutorial-for-vex-v5-robots-774703ca2d3c
//Travels forward for a distance (in inches) at a given velocity (percent). Go backwards by using negative input for distance
void moveForward(double distanceInches, double velocityPercent){
  float inchesPerDegree = WHEEL_CIRCUMFERENCE / 360;
  float degreesToRotate = distanceInches / inchesPerDegree;

  leftDrive.setVelocity(velocityPercent, pct);
  rightDrive.setVelocity(velocityPercent, pct);

  leftDrive.spinFor(forward, degreesToRotate * GEAR_RATIO, deg, false);
  rightDrive.spinFor(forward, degreesToRotate * GEAR_RATIO, deg, true);

  leftDrive.stop();
  rightDrive.stop();

}

// turn in place (negative turn degree: counterclockwise, positive turn degree: clockwise)
void turnInPlace(double turnDegrees, double velocityPercent) {
  double turningRatio = TURNING_DIAMETER / WHEEL_DIAMETER;
  double wheelDegrees = turningRatio * turnDegrees;

  leftDrive.setVelocity(velocityPercent, pct);
  rightDrive.setVelocity(velocityPercent, pct);

  leftDrive.spinFor(directionType::fwd, (wheelDegrees * GEAR_RATIO) / 2, deg, false);
  rightDrive.spinFor(directionType::fwd, (wheelDegrees * GEAR_RATIO) / 2, deg, true);

  leftDrive.stop();
  rightDrive.stop();
}

// turn the intake for a certain amount of time
void doIntake(double timeMSec, double velocityPercent) {
  intakeSpinMotors.setVelocity(velocityPercent, pct);

  intakeSpinMotors.spinFor(timeMSec, msec);
}

// turn flywheels to shoot the disks out
void shootDisks(double timeMSec, double velocityPercent) {
  flywheelSpinMotors.setVelocity(velocityPercent, pct);

  intakeSpinMotors.spinFor(timeMSec, msec);
  flywheelSpinMotors.spinFor(timeMSec, msec);
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
