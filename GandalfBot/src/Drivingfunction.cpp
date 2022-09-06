#include "vex.h"
#include "Drivingfunction.h"


bool doNoobToggle = false;
bool buttonNoobToggle = false;
double toggleNoobMode(){
  if(controller1.ButtonY.pressing()){
    if(!buttonNoobToggle){
      buttonNoobToggle = true;
      doNoobToggle = !doNoobToggle;
    }
  } else {
    buttonNoobToggle = false;
  }

  if(doNoobToggle){
    return 0.1;
  }else{
    return 1;
  }
}

//Drive
void tankdrive(){
  double speedValue = toggleNoobMode();
  if(abs(controller1.Axis3.value())>5||abs(controller1.Axis2.value())){
  leftDrive.spin(fwd, controller1.Axis3.value()*speedValue, pct);
  rightDrive.spin(fwd, controller1.Axis3.value()*speedValue, pct);

  }
  else{
    leftDrive.stop(coast);
    rightDrive.stop(coast);
  }
}
//Individual wheel control
void arcadedrive(){
  double speedValue = toggleNoobMode();
  if(abs(controller1.Axis3.value())>5 || abs(controller1.Axis1.value())){
    rightDrive.spin(fwd, controller1.Axis3.value()*speedValue+controller1.Axis1.value()*speedValue, pct);
    leftDrive.spin(fwd, controller1.Axis3.value()*speedValue-controller1.Axis1.value()*speedValue, pct);
  }
  else{

    leftDrive.stop(coast);
    rightDrive.stop(coast);
  }
}