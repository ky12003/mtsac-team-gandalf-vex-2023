#include "vex.h"
#include "robot-config.h"

void fly_wheel_one_forward()
{
  fly_wheel_one.spin(fwd, 100, pct);
}

void fly_wheel_two_forward()
{
  fly_wheel_two.spin(fwd, 100, pct);
}

void fly_wheel_one_reverse()
{
  fly_wheel_one.spin(reverse, 100, pct);
}

void fly_wheel_two_reverse()
{
  fly_wheel_two.spin(reverse, 100, pct);
}


bool fly_toggle = false;
bool fly_stopper = false;
void fly_wheel_toggle()
{
  if(controller1.ButtonX.pressing()){
    if(!fly_stopper){
      fly_toggle = !fly_toggle;
      fly_stopper = true;
    }
  }else{
    fly_stopper = false;
  }

  if(fly_toggle)
  {
    fly_wheel_one.spin(fwd,100,pct);
    fly_wheel_two.spin(fwd,100,pct);
  } else{
   fly_wheel_one.stop();
   fly_wheel_two.stop();
  }
}