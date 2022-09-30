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
//(intakeSpinMotorBelt = conveyer belt, intake 1, 2: top, bottom spinners)
motor intakeSpinMotorBelt(PORT8, ratio36_1, false);
motor intakeSpinMotor1(PORT5, ratio36_1,  true);
motor intakeSpinMotor2(PORT4, ratio36_1, true);

// FLYWHEEL MOTORS
// (left/right side facing torwards the back of the bot)
motor leftFlywheelMotor(PORT1, ratio36_1, false);
motor rightFlywheelMotor(PORT9, ratio36_1, true);

/*-----
MOTOR GROUPS
------*/

// LEFT SIDE/RIGHT SIDE DRIVE MOTORGROUP
motor_group leftDrive( BackLeftTop, BackLeftBottom);
motor_group rightDrive( BackRightTop, BackRightBottom);

// INTAKE MOTORGROUP
motor_group intakeSpinMotors(intakeSpinMotorBelt, intakeSpinMotor1, intakeSpinMotor2); 

// FLYWHEEL PAIR MOTORGROUP
motor_group flywheelSpinMotors(leftFlywheelMotor, rightFlywheelMotor);

/*-----
SENSORS 
------*/
// the 2 inertial sensors

//-------
//***CONSTANTS ARE IN .H FILE***
//-------

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
