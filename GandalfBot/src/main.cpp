#include "vex.h"
#include "robot-config.h"
#include "Drivingfunction.h"

using namespace vex;
competition Competition;
void usercontrol(){
  while (1){
    // tankdrive();
    arcadedrive();
  }
}

void Autonomous(){

}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Competition.drivercontrol(usercontrol);
  Competition.autonomous(Autonomous);


  
}