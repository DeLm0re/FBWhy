/*
* Generic headers files :
*/
#include <stdlib.h>
#include <stdio.h>
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

//Default width and height
#define WindowWidth 800
#define WindowHeight 600

/*
* function :
*           Draw a circle in graphical window
* 
* param :
*           unsigned short int xCenter : The coordonate x of our circle center
*           unisgned short int yCenter : The coordonate y of our circle center
*           unsigned short int radius : The radius of our circle
*
* return :
*           void
*/
void drawCircle(unsigned short int xCenter, unsigned short int yCenter, unsigned short int radius);

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