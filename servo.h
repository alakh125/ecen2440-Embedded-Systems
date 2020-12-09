/*
 * servo.h
 * originally created for parameters by Tyler Davidson, edited to include servo functions
 * Created by Team Spider Roomba
 * Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
 */

//Originally created by Tyler Davidson, Referenced/Modified/Documented
#ifndef SERVO_H_
#define SERVO_H_

#include "pca9685.h"
//   servo name  PCA Channel
#define URL         0  //Upper Right Leg
#define LRL         1  //Lower Right Leg
#define URA         4  //Upper Right Arm
#define LRA         5  //Lower Right Arm
#define ULL         9  //Upper Left  Leg
#define LLL         10 //Lower Left  Leg
#define ULA         13 //Upper Left  Arm
#define LLA         14 //Lower Left  Arm

//The following function was defined by Tyler Davidson elsewhere, then moved here
void standing(void);
//The following functions were written by the teams
void move_forward(void);
void move_backward(void);
void turn_left(void);
void turn_right(void);
void random_movement(void);

#endif
