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
#include "image.h"

//Definition of PI
#ifndef M_PI
#define M_PI (3.141592654)
#endif

//Definition of the number of sectors we used to draw a circle
#define NUMBER_SECTORS (16)

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
*           Draw an image with type imagePixel on our graphical window
* 
* param :
*           char *name : Relative way to the image we want to draw
*           unsigned short int x : The x cord of the image in our graphical window
*           unsigned short int y : The y cord of the image in our graphical window
*
* return :
*           void
*/
void drawImagePixel(char *name, unsigned short int x, unsigned short int y);

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

/*
* function :
*           Printf all the weights table for a thief in console
* 
* param :
*           AllMoney *tableOfThieves : A pointer on our table of "Thief"
*           unisgned short int : Index on the thief containing the weights table we want to print
*
* return :
*           void
*/
void printWeightsTable(AllThieves *tableOfThieves, unsigned short int index);
