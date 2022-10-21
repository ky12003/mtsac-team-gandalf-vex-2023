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
  double target_rotation = (inertial_sensor.rotation(deg)+degrees);
  ///////////////////////////////////
  while(1==1)
  {
    double current_rotation = inertial_sensor.rotation(deg);
    double error = target_rotation - current_rotation;
    if (error>90)
    {
    left_all.spin(fwd,30,pct);
    right_all.spin(reverse,30,pct);
    } else if (error<-90){
    // left_all.spin(reverse,20,pct);
    // right_all.spin(fwd,20,pct);
    // }else if (error>30){
    // left_all.spin(fwd,error/4.5,pct);
    // right_all.spin(reverse,error/4.5,pct);
    // }else if (error<-30){
    // left_all.spin(reverse,error/4.5,pct);
    // right_all.spin(fwd,error/4.5,pct);
    }else{
    left_all.spin(fwd,error/3,pct);
    right_all.spin(reverse,error/3,pct);
    }
    printf("Inertial turn ERROR:%f      End_of_function:%d\n",error,end_function);
    if ((error<0.5)&&(error>-0.5)){
      vex::wait( 1 ,seconds);
      if ((error<0.5)&&(error>-0.5))
      left_back.setBrake(brake);
      left_middle.setBrake(brake);
      right_back.setBrake(brake);
      left_front.setBrake(brake);
      right_front.setBrake(brake);
      right_middle.setBrake(brake);
      left_all.stop();
      right_all.stop();
      end_function = 1;
      }
  
  if(end_function == 1)
  break;
  }
  /////////////////////////////////////////
}



void move_forward_PID(int speed, double disMeters) //speed in pct distance in feet
{
  double target_rotation = (inertial_sensor.rotation(deg));
  int end_rotation_check = 0;
  int end_function = 0;
  const float kP = 0.1;
  int error = 0; //proportional / current

  int leftSideVel;    //left side velocity
  int rightSideVel;    //right side velocity

  left_front.setPosition(0,degrees); //resets encoder values
  right_front.setPosition(0,degrees); //resets encoder values

  int leftPosition = left_front.position(degrees); //encoder value for left in rev
  int rightPosition = right_front.position(degrees); //encoder value for right in rev   
  
  while(1)
  {
    leftPosition = left_front.position(degrees); //encoder value for left in rev
    rightPosition = right_front.position(degrees); 
    printf("LeftPosition:%d  RightPosition:%d\n",leftPosition,rightPosition);
    error = leftPosition - rightPosition; //calculates error

    rightSideVel = speed + (error*kP); //sets right side vel
    leftSideVel = speed - (error*kP);//sets right side vel

    left_all.spin(fwd,leftSideVel,pct); //spins left side
    right_all.spin(fwd,rightSideVel,pct); //spins right side

    printf("move_forward PID: ERROR:%i      End_of_function:%d\n",error,end_function);
    if ((leftPosition > (disMeters*360*2.15))&&(rightPosition>(disMeters*360*2.15)))
    { 
      ///////////////////////////////////
  while(1==1)
  {
    double current_rotation = inertial_sensor.rotation(deg);
    double rotational_error = target_rotation - current_rotation;
    if (rotational_error>90)
    {
    left_all.spin(fwd,30,pct);
    right_all.spin(reverse,30,pct);
    } else if (rotational_error<-90){
    // left_all.spin(reverse,20,pct);
    // right_all.spin(fwd,20,pct);
    // }else if (error>30){
    // left_all.spin(fwd,error/4.5,pct);
    // right_all.spin(reverse,error/4.5,pct);
    // }else if (error<-30){
    // left_all.spin(reverse,error/4.5,pct);
    // right_all.spin(fwd,error/4.5,pct);
    }else{
    left_all.spin(fwd,rotational_error/3,pct);
    right_all.spin(reverse,rotational_error/3,pct);
    }
    printf("Inertial turn ERROR:%f      End_of_function:%d\n",rotational_error,end_function);
    if ((rotational_error<0.5)&&(rotational_error>-0.5)){
      vex::wait( 1 ,seconds);
      if ((rotational_error<0.5)&&(rotational_error>-0.5))
      left_back.setBrake(brake);
      left_middle.setBrake(brake);
      right_back.setBrake(brake);
      left_front.setBrake(brake);
      right_front.setBrake(brake);
      right_middle.setBrake(brake);
      left_all.stop();
      right_all.stop();
      end_rotation_check = 1;
      }
  
  if(end_rotation_check == 1)
  break;
  }
  /////////////////////////////////////////
      left_back.setBrake(brake);
      left_middle.setBrake(brake);
      right_back.setBrake(brake);
      left_front.setBrake(brake);
      right_front.setBrake(brake);
      right_middle.setBrake(brake);
      left_all.stop();
      right_all.stop();
      end_function = 1;
    }
  

    if(end_function == 1)
     break;
    
  }
}







// void correct_error()
// {
//   double leftEncoder = left_front.position(rev);
//   double rightEncoder = right_front.position(rev);
//   double error = fabs(rightEncoder - leftEncoder); 
//   if (leftEncoder > rightEncoder)
//    {
//       error = fabs(rightEncoder - leftEncoder);
//       right_all.spin(fwd, 100-error,rpm);
//       left_all.spin(fwd,100,rpm);
//   }else if (leftEncoder > rightEncoder)
//    {
//       error = fabs(rightEncoder - leftEncoder);
//       left_all.spin(fwd, 100-error,rpm);
//       right_all.spin(fwd,100,rpm);
//   }

  

//    printf("left rotations: %2f         right rotationsL %2f \n", leftEncoder, rightEncoder);
// }

// //using encoders to ensure straight
// void move_forward_alt(double disMeters, double velPct, int timeout)
// {
//     right_all.spinFor(fwd, double(disMeters)/10, rev, double(velPct), rpm, false);
//     left_all.spinFor(fwd, double(disMeters)/10, rev, double(velPct), rpm, true);
//     //double outSideError = fabs(left_front.position(rev)-right_front.position(rev));
//     //double outSideLeft = left_front.position(rev);
//     //double outSideRight = right_front.position(rev);
//     correct_error();
//     //if(outSideLeft < outSideRight)
//     //{left_all.spin(fwd,100,rpm); right_all.spin(fwd,100*())}
// }

// int left_speed = 50;
// int right_speed = 25;

// void move_forward_alt_test()
// {
//   left_all.spin(fwd,left_speed,rpm);
//   right_all.spin(fwd,right_speed,rpm);
//   if(left_front.position(rev)<right_front.position(rev))
//   {
//     left_speed++; 
//   } else if (left_front.position(rev)>right_front.position(rev))
//   {
//     right_speed++;
//   }
// }
