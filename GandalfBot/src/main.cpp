#include "vex.h"
#include "robot-config.h"
#include "Drivingfunction.h"
#include "routines.h"

using namespace vex;
competition Competition;
void usercontrol(){
  while (1){
    tankdrive();
    // arcadedrive();
    intakeControl();
    toggleFlywheel();
  }
}

void Autonomous(){
  firstRoutine();
  // secondRoutine();
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Competition.drivercontrol(usercontrol);
  Competition.autonomous(Autonomous); // too sleepy to text
  
}