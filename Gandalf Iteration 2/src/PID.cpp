#include "vex.h"
#include "robot-config.h"

void auto_straight(int speed)
{
  const float kP = 0.2;
  const float kI = 0;
  const float kD = 0;
  int error = 0;; //proportional / current
  int total_error = 0; //integral
  int delta_error =0; //derivative
  int last_error = 0; //last error used to calculate change in error
  

  int leftSideVel = 10; //master side
  int rightSideVel;     //slave side

  int leftPosition = left_front.position(degrees); //encoder value for left in rev
  int rightPosition = right_front.position(degrees); //encoder value for right in rev
  
  left_front.setPosition(0,degrees); //resets encoder values
  right_front.setPosition(0,degrees); //resets encoder values

  while(1)
  {
    leftPosition = left_front.position(degrees); //encoder value for left in rev
    rightPosition = right_front.position(degrees); 
    printf("%d %d\n",leftPosition,rightPosition);
    error = leftPosition - rightPosition; //calculates error
    total_error = total_error + error; //calculates total error
    delta_error = error - last_error; //calculates derivative of error

    rightSideVel = speed + (error*kP) + (total_error*kI) + (delta_error*kD); //sets right side vel
    leftSideVel = speed - (error*kP) - (total_error*kI) - (delta_error*kD); //sets right side vel

    left_all.spin(fwd,leftSideVel,pct); //spins left side
    right_all.spin(fwd,rightSideVel,pct); //spins right side
    last_error = error; //sets last error

    //printf("error:%f      total_error:%f          delta_error:%f\n",error,total_error,delta_error);
    
    
    vex::task::sleep(20);
    
  }


}