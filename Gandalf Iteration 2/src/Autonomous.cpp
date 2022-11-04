#include "vex.h"
#include "robot-config.h"

const float rev_to_meters = 2.894;

void timeOut(int timeSeconds)
{
    left_all.setTimeout(timeSeconds, sec);
    right_all.setTimeout(timeSeconds, sec);
}

void move_forward(double disMeters, double velPct, int timeout)
{
    timeOut(timeout);
    right_all.spinFor(fwd, double(disMeters), rev, double(velPct), rpm, false);
    left_all.spinFor(fwd, double(disMeters), rev, double(velPct), rpm, true);
    timeOut(0);
}


void turn_left(double degrees, double velPct, int timeout)
{
    timeOut(timeout);
    degrees = degrees / 360;
    degrees = degrees * 0.270* 3.1415 * rev_to_meters;
    right_all.spinFor(fwd, double(degrees), rev, double(velPct), rpm, false);
    left_all.spinFor(reverse, double(degrees), rev, double(velPct), rpm, true);
    timeOut(0);
}

void inertial_turn(double degrees)
{
  int end_function = 0;
  inertial_sensor.resetRotation(); //try without just this, maybe inertial sensor resets
  double target_rotation = (inertial_sensor.rotation(deg)+degrees);
  ///////////////////////////////////
  while(1==1)
  {
    if (1==1)
  {
  float current = (inertial_sensor.rotation(deg));
  printf("rotation: %f\n",current);
  }
    double current_rotation = inertial_sensor.rotation(deg);
    double error = target_rotation - current_rotation;
    //printf("current rotation: %f   target rotation: %f    error: %f\n",current_rotation,target_rotation,error);
    if (error>90)
    {
    left_all.spin(fwd,45,pct);
    right_all.spin(reverse,45,pct);
    } else if (error<-90){
     left_all.spin(reverse,45,pct);
     right_all.spin(fwd,45,pct);
    }else if (error>30){
    left_all.spin(fwd,error/3,pct);
    right_all.spin(reverse,error/3,pct);
    }else if (error<-30){
    left_all.spin(reverse,fabs(error)/3,pct);
    right_all.spin(fwd,fabs(error)/3,pct);
    }else if (error>5){
    left_all.spin(fwd,error/2,pct);
    right_all.spin(reverse,error/2,pct);
    }else if (error<-5){
    left_all.spin(reverse,fabs(error)/2,pct);
    right_all.spin(fwd,fabs(error)/2,pct);
    }else if (error>0){
    left_all.spin(fwd,2,pct);
    right_all.spin(reverse,2,pct);
    }else if (error<0){
    left_all.spin(reverse,2,pct);
    right_all.spin(fwd,2,pct);
    }
    //printf("Inertial turn ERROR:%f      End_of_function:%d\n",error,end_function);
    if ((error<0.1)&&(error>-0.1)){
      left_back.setBrake(brake);
      left_middle.setBrake(brake);
      right_back.setBrake(brake);
      left_front.setBrake(brake);
      right_front.setBrake(brake);
      right_middle.setBrake(brake);
      left_all.stop();
      right_all.stop();
      vex::task::sleep(250);
      error = target_rotation - current_rotation;
      if ((error<0.1)&&(error>-0.1))
      {
      end_function = 1;
      } 
    }
  if(end_function == 1)
  {
  break;
  }
  
  /////////////////////////////////////////
}
}


void move_forward_PID(int speed, double disMeters) //speed in pct distance in feet
{
  inertial_sensor.resetRotation();
  int end_function = 0;
  const float kP = 0.05;
  const float kD = 0.3;
  int error = 0; //proportional / current
  int last_error = 0;
  int derivative = 0;
  int leftSideVel;    //left side velocity
  int rightSideVel;    //right side velocity

  left_front.setPosition(0,degrees); //resets encoder values
  right_front.setPosition(0,degrees); //resets encoder values

  int leftPosition = left_front.position(degrees); //encoder value for left in rev
  int rightPosition = right_front.position(degrees); //encoder value for right in rev   
  
  while(1)
  {
    if (1==1)
  {
  float current = (inertial_sensor.rotation(deg));
  printf("rotation: %f\n",current);
  }

    leftPosition = left_front.position(degrees); //encoder value for left in rev
    rightPosition = right_front.position(degrees); 
    //printf("LeftPosition:%d  RightPosition:%d\n",leftPosition,rightPosition);
    error = leftPosition - rightPosition; //calculates error
    derivative = error - last_error;
    vex::task::sleep( 20 );
    last_error = error;
    
    




    //printf("error: %i    left position: %i    right position %i    last_error: %i   derivative: %i\n",error,leftPosition,rightPosition,last_error,derivative);
    rightSideVel = speed + (error*kP) + (derivative*kD); //sets right side vel
    leftSideVel = speed - (error*kP) - (derivative*kD);//sets right side vel

    right_all.spin(fwd,rightSideVel,pct); //spins right side
    left_all.spin(fwd,leftSideVel,pct); //spins left side
    

    //printf("move_forward PID: ERROR:%i      End_of_function:%d\n",error,end_function);
    if ((leftPosition > (disMeters*360*2.15))&&(rightPosition>(disMeters*360*2.15)))
    {
      left_back.setBrake(brake);
      left_middle.setBrake(brake);
      right_back.setBrake(brake);
      left_front.setBrake(brake);
      right_front.setBrake(brake);
      right_middle.setBrake(brake);
      left_all.stop();
      right_all.stop();
      vex::task::sleep( 20 );
      end_function = 1;
    }
    
    if(end_function == 1)
    {
      printf("break out of forward");
      break;
      end_function = 0; 
    }
    
  }

}

void move_back_PID(int speed, double disMeters) //speed in pct distance in feet
{
  inertial_sensor.resetRotation();
  int end_function = 0;
  const float kP = 0.05;
  const float kD = 0.3;
  int error = 0; //proportional / current
  int last_error = 0;
  int derivative = 0;
  int leftSideVel;    //left side velocity
  int rightSideVel;    //right side velocity

  left_front.setPosition(0,degrees); //resets encoder values
  right_front.setPosition(0,degrees); //resets encoder values

  int leftPosition = left_front.position(degrees); //encoder value for left in rev
  int rightPosition = right_front.position(degrees); //encoder value for right in rev   
  
  while(1)
  {
    if (1==1)
  {
  float current = (inertial_sensor.rotation(deg));
  printf("rotation: %f\n",current);
  }

    leftPosition = left_front.position(degrees); //encoder value for left in rev
    rightPosition = right_front.position(degrees); 
    //printf("LeftPosition:%d  RightPosition:%d\n",leftPosition,rightPosition);
    error = leftPosition - rightPosition; //calculates error
    derivative = error - last_error;
    vex::task::sleep( 20 );
    last_error = error;
    
    




    //printf("error: %i    left position: %i    right position %i    last_error: %i   derivative: %i\n",error,leftPosition,rightPosition,last_error,derivative);
    rightSideVel = speed + (error*kP) + (derivative*kD); //sets right side vel
    leftSideVel = speed - (error*kP) - (derivative*kD);//sets right side vel

    right_all.spin(reverse,rightSideVel,pct); //spins right side
    left_all.spin(reverse,leftSideVel,pct); //spins left side
    

    //printf("move_forward PID: ERROR:%i      End_of_function:%d\n",error,end_function);
    if ((leftPosition > (disMeters*360*2.15))&&(rightPosition>(disMeters*360*2.15)))
    {
      left_back.setBrake(brake);
      left_middle.setBrake(brake);
      right_back.setBrake(brake);
      left_front.setBrake(brake);
      right_front.setBrake(brake);
      right_middle.setBrake(brake);
      left_all.stop();
      right_all.stop();
      vex::task::sleep( 20 );
      end_function = 1;
    }
    
    if(end_function == 1)
    {
      printf("break out of forward");
      break;
      end_function = 0; 
    }
    
  }

}


