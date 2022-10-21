#include "vex.h"
#include "robot-config.h"

const int PCT_TO_RPM = 6;
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
  double target_rotation = (inertial_sensor.rotation(deg)+degrees);
  while(1)
  {
    double current_rotation = inertial_sensor.rotation(deg);
    double error = target_rotation - current_rotation;
    if (error>90)
    {
    left_all.spin(fwd,30,pct);
    right_all.spin(reverse,30,pct);
    } else if (error<-90){
    left_all.spin(reverse,30,pct);
    right_all.spin(fwd,30,pct);
    }else if (error>30){
    left_all.spin(fwd,error/2,pct);
    right_all.spin(reverse,error/2,pct);
    }else if (error<-30){
    left_all.spin(reverse,error/2,pct);
    right_all.spin(fwd,error/2,pct);
    }else{
    left_all.spin(fwd,error,pct);
    right_all.spin(reverse,error,pct);
    }
    if (error<1){
      vex::task::sleep( 200 );
      if (error<1)
      break;
    }
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
