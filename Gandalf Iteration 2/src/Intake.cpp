#include "vex.h"
#include "robot-config.h"

void run_intake()
{
  intake.spin(fwd, 100, pct);
}

void run_intake_reverse()
{
  intake.spin(reverse, 100, pct);
}

int intake_state = 0;
bool intake_stopper = false;
void intake_toggle()
{
  //forward
  if (controller1.ButtonR1.pressing())
  {
    //vex::task::sleep(150);
    if(intake_stopper == false)
    {
      if(intake_state != 1)
      {
      intake_state = 1;
      intake_stopper = true;
      }
      else if (intake_state ==1)
      intake_state = 0;
      intake_stopper = true;
      printf("stopper is true    ");
      printf("intake stopper: %i        intakestate: %i\n",intake_stopper,intake_state);
    }
  }else if ((controller1.ButtonR1.pressing()==false)&&(controller1.ButtonR2.pressing()==false)){
    printf("stopper is false    ");
    printf("intake stopper: %i        intakestate: %i\n",intake_stopper,intake_state);
    intake_stopper = false;
  }
  //backwards
  if (controller1.ButtonR2.pressing())
  {
    //vex::task::sleep(150);
    if(intake_stopper == false)
    {
      if(intake_state != 2)
      {
      intake_state = 2;
      intake_stopper = true;
      }
      else if (intake_state ==2)
      intake_state = 0;
      intake_stopper = true;
      printf("stopper is true    ");
      printf("intake stopper: %i        intakestate: %i\n",intake_stopper,intake_state);
    }
  }else if ((controller1.ButtonR1.pressing()==false)&&(controller1.ButtonR2.pressing()==false)){
    printf("stopper is false    ");
    printf("intake stopper: %i        intakestate: %i\n",intake_stopper,intake_state);
    intake_stopper = false;
  }








  ////////////////////////////////////////
  if (intake_state == 0)
  {
    intake.stop(brake);
  }
  if (intake_state == 1)
  {
    run_intake();
  }
  if (intake_state == 2)
  {
    run_intake_reverse();
  }
    //printf("intake stopper: %        intakestate: %i\n",intake_stopper,intake_state);

}
