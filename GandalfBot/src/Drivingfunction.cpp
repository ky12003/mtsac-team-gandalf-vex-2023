#include "vex.h"
#include "Drivingfunction.h"


// OPTIONS:
// 0: 100% speed (default, set with X button)
// 1: 75% speed (set with Y button)
// 2: 50% speed (set with A button)
// 3: 25% speed (set with B button)
double speedToggleOption() {
  if (controller1.ButtonX.pressing()) {
    // 100% speed
    return 1;
  } 
  else if (controller1.ButtonY.pressing()) {
    // 75% speed
    return 0.75;
  } 
  else if (controller1.ButtonA.pressing()) {
    // 50% speed
    return 0.5;
  } 
  else if (controller1.ButtonB.pressing()) {
    // 25% speed
    return 0.25;
  } 
  else {
    // don't update option
    return -1;
  }
}

double toggleOption = 1;
bool buttonNoobToggle = false;
double toggleSpeedMode(){
  double tempOption = speedToggleOption();
  if(tempOption != -1){
    if(!buttonNoobToggle){
      buttonNoobToggle = true;
      toggleOption = tempOption;
    }
  } else {
    buttonNoobToggle = false;
  }

  return toggleOption;
}

//Drive
void tankdrive(){
  double speedValue = toggleSpeedMode();
  if(abs(controller1.Axis3.value())>5||abs(controller1.Axis2.value())>5)
  {
  leftDrive.spin(fwd, controller1.Axis3.value()*speedValue, pct);
  rightDrive.spin(fwd, controller1.Axis2.value()*speedValue, pct);
  }
  else
  {
    leftDrive.stop(coast);
    rightDrive.stop(coast);
  }
}
//Individual wheel control
void arcadedrive(){
  double speedValue = toggleSpeedMode();
  if(abs(controller1.Axis3.value())>5 || abs(controller1.Axis1.value()) > 5)
  {
    rightDrive.spin(fwd, (controller1.Axis3.value()*speedValue) - (controller1.Axis1.value()*speedValue), pct);
    leftDrive.spin(fwd, (controller1.Axis3.value()*speedValue) + (controller1.Axis1.value()*speedValue), pct);
  }
  else
  {
    leftDrive.stop(coast);
    rightDrive.stop(coast);
  }
}