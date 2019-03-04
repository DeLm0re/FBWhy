/*
* Generic headers files :
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

/*
* Cusom headers files :
*/
//To use the drawing functions
#include "GfxLib.h"
//To use the prototypes in the core
#include "core.h"

//Definition of PI
#ifndef M_PI
#define M_PI (3.141592654)
#endif

//Definition of the number of sectors we used to draw a circle
#define NUMBER_SECTORS (16)

//Default width and height
#define WindowWidth 800
#define WindowHeight 600

/*
* function :
*           Draw the borders in our graphical window
* 
* param :
*           none
*
* return :
*           void
*/
void drawBorders(void);

/*
* function :
*           Draw a circle in graphical window
* 
* param :
*           unsigned short int xCenter : The coordonate x of our circle center
*           unisgned short int yCenter : The coordonate y of our circle center
*           float radius : The radius of our circle
*
* return :
*           void
*/
void drawCircle(unsigned short int xCenter, unsigned short int yCenter, float radius);

/*
* function :
*           Draw all the lights in our graphical window
* 
* param :
*           AllLights *myLights : A pointer on our table containing all the lights
*
* return :
*           void
*/
void drawAllLights(AllLights *myLights);

/*
* function :
*           Draw all the thieves in our graphical window
* 
* param :
*           AllThieves *myThieves : A pointer on our table containing all the thieves
*
* return :
*           void
*/
void drawAllThieves(AllThieves *myThieves);

/*
* function :
*           Draw all the money in our graphical window
* 
* param :
*           AllMoney *myMoney : A pointer on our table containing all the money
*
* return :
*           void
*/
void drawAllMoney(AllMoney *myMoney);