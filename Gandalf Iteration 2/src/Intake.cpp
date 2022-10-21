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

void run_intake_toggle()
{
  int intake_state = 1; // 0 = stop / 1 = run / 2 = reverse
  bool intake_run_current = false;
  bool intake_run_last = false;

  bool intake_reverse_current = false;
  bool intake_reverse_last = false;
  if (1==1)
  {
  intake_run_current = controller1.ButtonR1.pressing();
    intake_reverse_current = controller1.ButtonR2.pressing();
    //if intake is running stop
    if(intake_run_current == true && intake_run_last == false && intake_state == 1)
    intake_state = 0;
    //if intake is not running run
    if(intake_run_current == true && intake_run_last == false && intake_state != 1) 
    intake_state = 1;
    //if intake is reverse stop
    if(intake_reverse_current == true && intake_reverse_last == false && intake_state == 2)
    intake_state = 0;
    //if intake is not reverse reverse
    if(intake_reverse_current == true && intake_reverse_last == false && intake_state != 2)
    intake_state = 2;

    if(1==1)
    {
    intake_run_last = intake_run_current;
    intake_reverse_last = intake_reverse_current;
    }
    
    printf("intake_state: %i  ",intake_state);
    printf("intake_run_current:  %i ",intake_run_current);
    printf("intake_run_last:  %i ",intake_run_last);
    printf("intake_reverse_current:  %i ",intake_reverse_current);
    printf("intake_reverse_last: %i  ",intake_reverse_last);
    printf("\n");
}
}