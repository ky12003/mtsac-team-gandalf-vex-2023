#include "vex.h"
#include "robot-config.h"
#include "Pneumatics.h"

void fly_wheel_one_forward(int speed)
{
  fly_wheel_one.spin(fwd, speed, pct);
}

void fly_wheel_two_forward(int speed)
{
  fly_wheel_two.spin(fwd, speed, pct);
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

void wait_shoot() //runs fly wheel, shoots, then stops flywheel
{
  fly_wheel_one_forward(100);
  fly_wheel_two_forward(100);
  int left_speed = 0;
  int right_speed = 0;
  bool waiting = true;
  while(waiting == true)
  {
    left_speed = intake_1.velocity(rpm);
    right_speed = intake_2.velocity(rpm);
    if ((left_speed>550)&&(right_speed>550))
    {
      extend_feeder();
      vex::task::sleep( 1000 );
      retract_feeder();
      vex::task::sleep( 1000 );
      waiting = false;
    }
  }
  fly_wheel_one.setBrake(coast);
  fly_wheel_two.setBrake(coast);
}