#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller controller1(primary);

/*-----
MOTORS 
------*/
// DRIVETRAIN MOTORS (naming scheme below)
// A: frontmost motor group
// B: middle motor group
// C: backmost motor group
// left/right: motors on the left/right
// top/bottom: frontmost/backmost motors in motor group

motor BackRightTop(PORT19, ratio18_1, false); 
motor BackRightBottom(PORT20, ratio18_1, true);

motor BackLeftTop(PORT11, ratio18_1, true); 
motor BackLeftBottom(PORT12, ratio18_1, false);

//INTAKE MOTORS
//(intake 1: in the front, intake 2: in the back)
motor intakeSpinMotor1(PORT15, ratio18_1, true);
motor intakeSpinMotor2(PORT11, ratio18_1,  false);

// FLYWHEEL MOTORS
// (left/right side facing torwards the back of the bot)
motor leftFlywheelMotor(PORT1, ratio36_1, true);
motor rightFlywheelMotor(PORT9, ratio36_1, true);

/*-----
MOTOR GROUPS
------*/

// LEFT SIDE/RIGHT SIDE DRIVE MOTORGROUP
motor_group leftDrive( BackLeftTop, BackLeftBottom);
motor_group rightDrive( BackRightTop, BackRightBottom);

// INTAKE MOTORGROUP
motor_group intakeSpinMotors(intakeSpinMotor1, intakeSpinMotor2); 

// FLYWHEEL PAIR MOTORGROUP
motor_group flywheelSpinMotors(leftFlywheelMotor, rightFlywheelMotor);

/*-----
SENSORS 
------*/
// the 2 inertial sensors


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
