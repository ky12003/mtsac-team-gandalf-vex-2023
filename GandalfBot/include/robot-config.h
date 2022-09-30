using namespace vex;

/*----
GENERAL
-----*/
extern brain Brain;
extern controller controller1;

/*----
MOTORS
-----*/

// drive motors
extern motor BackRightTop; 
extern motor BackRightBottom;
extern motor BackLeftTop; 
extern motor BackLeftBottom;

// intake motors
extern motor intakeSpinMotorBelt;
extern motor intakeSpinMotor1;
extern motor intakeSpinMotor2;
extern motor leftFlywheelMotor;
extern motor rightFlywheelMotor;

/*----
MOTOR GROUPS
-----*/

extern motor_group leftDrive;
extern motor_group rightDrive;
extern motor_group intakeSpinMotors;
extern motor_group flywheelSpinMotors;


/*----
SENSORS
-----*/

/*----
CONSTANTS
-----*/
/*-----
CONSTANTS
------*/
const float WHEEL_DIAMETER = 4.275; // inches
const float WHEEL_CIRCUMFERENCE = WHEEL_DIAMETER * 3.1416;
const float GEAR_RATIO = 1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);