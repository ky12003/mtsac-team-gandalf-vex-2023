#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller controller1(primary);

/*-----
Drivetrain motors (naming scheme below, orientation facing forward from the back of the robot)
------*/
// A: frontmost motor group
// B: middle motor group
// C: backmost motor group
// left/right: motors on the left/right
// top/bottom: frontmost/backmost motors in motor group
// motor FrontLeftBottom(PORT19, ratio18_1, true);
// motor FrontLeftTop(PORT20, ratio18_1, false);

// motor FrontRightTop(PORT12, ratio18_1, false); 
// motor FrontRightBottom(PORT11, ratio18_1, true);

motor BackRightTop(PORT1, ratio18_1, true); 
motor BackRightBottom(PORT2, ratio18_1, true);

motor BackLeftTop(PORT10, ratio18_1, false); 
motor BackLeftBottom(PORT9, ratio18_1, false);


// FrontLeftTop, FrontLeftBottom,
// FrontRightTop, FrontRightBottom,
motor_group leftDrive( BackLeftTop, BackLeftBottom, BackLeftTop);
motor_group rightDrive( BackRightTop, BackRightBottom, BackRightTop);

//intake motors
//Fronttopright, Fronttopleft
motor intakeSpinMotor1(PORT12, ratio6_1, false);
motor intakeSpinMotor2(PORT20, ratio6_1,  false);

//intake motors-group
//Fronttopright, Fronttopleft
motor_group intakeSpinMotor(intakeSpinMotor1, intakeSpinMotor2); 

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
