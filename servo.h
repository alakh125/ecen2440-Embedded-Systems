//Originally created by Tyler Davidson, Referenced/Modified/Documented
#ifndef pwmTIMER_H_
#define pwmTIMER_H_

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

//The following functions were written by the teams
void standing(void);
void move_forward(void);
void move_backward(void);
void move_left(void);
void move_right(void);
void turn_right_90(void);
void turn_left_90(void);
void random_movement(void);