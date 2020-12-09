/*
 * servo.c
 * Created by Team Spider Roomba
 * Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
 */
#include "servo.h"
#include "stdlib.h"
#include "stdio.h"

//uses the servos against each other in opposite directions
//to make Quade stand, without moving or tunring
//Leveraged from Tyler Davidson's IMU_Testbench, all other functions
//  reference this block, but were written by the group
void standing(void){
  servo_write(URL,90-45);
  servo_write(LRL,90-45);
  servo_write(URA,90+45); 
  servo_write(LRA,90+45);
  servo_write(ULL,90+45);
  servo_write(LLL,90+45);
  servo_write(ULA,90-45);
  servo_write(LLA,90-45);
}

//moves right legs forward, keeping left legs straight
void forward_right(void){
  servo_write(ULL,   0);
  servo_write(LLL,   0);
  servo_write(ULA,   0);
  servo_write(LLA,   0);
  servo_write(URL,-360);
  servo_write(LRL,-360);
  servo_write(URA, 360);
  servo_write(LRA, 360);
}

//moves left legs forward, keeping right legs straight
void forward_left(void){
  servo_write(URL,   0);
  servo_write(LRL,   0);
  servo_write(URA,   0);
  servo_write(LRA,   0);
  servo_write(ULL,-360);
  servo_write(LLL,-360);
  servo_write(ULA, 360);
  servo_write(LLA, 360);
}

//moves front and back right side together, then left and right
void move_forward(void){
  forward_right();
  forward_left();
}

//turns Quade right by 90 degrees. Unable to test that this works, but
//seems to work well theoretically
void turn_right(void){
  servo_write(URL,-360);
  servo_write(LLA,-360);
  servo_write(ULL, 360);
  servo_write(LLL, 360);
}

//moves right legs backward, keeping left legs straight
void backward_right(void){
  servo_write(ULL,   0);
  servo_write(LLL,   0);
  servo_write(ULA,   0);
  servo_write(LLA,   0);
  servo_write(URL, 360);
  servo_write(LRL, 360);
  servo_write(URA,-360);
  servo_write(LRA,-360);
}

//moves left legs backward, keeping right legs straight
void backward_left(void){
  servo_write(URL,   0);
  servo_write(LRL,   0);
  servo_write(URA,   0);
  servo_write(LRA,   0);
  servo_write(ULL, 360);
  servo_write(LLL, 360);
  servo_write(ULA,-360);
  servo_write(LLA,-360);
}
void move_backward(void){
  backward_right();
  backward_left();
}

void turn_left(void){
  servo_write(URL,360);
  servo_write(LLA,360);
  servo_write(ULL,-360);
  servo_write(LLL,-360);
}
//run a random movement every time
void random_movement(void) {
  int randmovement = rand() % 10;
  if(randmovement >= 0 && randmovement < 2){
    turn_right();
  }
  else if(randmovement >= 2 && randmovement < 4){
    turn_left();
  }
  else if(randmovement >= 4 && randmovement < 6){
    move_backward();
  }
  else if(randmovement >= 6 && randmovement < 8){
    move_forward();
  }
  else if(randmovement >= 8 && randmovement <= 10){
    standing();
  }
  else{
    standing(); //don't expect rand to ever reach here, just an "in case" default
  }  
}