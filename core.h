/*
* Generic headers files :
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

//Definition of our maximum/minimum light radius
#define MAXIMUM_LIGHT_RADIUS (70)
#define MINIMUM_LIGHT_RADIUS (20)

//Type definition of Light
typedef struct Light
{
    unsigned short int x;
    unsigned short int y;
    unsigned short int radius;
    unsigned short int direction;
} Light;

//Type definition of Thief
typedef struct Thief
{
    unsigned short int x;
    unsigned short int y;
} Thief;

//Type definition of Money
typedef struct Money
{
    unsigned short int x;
    unsigned short int y;
} Money;

//Type definition of AllLights
typedef struct AllLights
{
    unsigned short int lenght;
    Light *lights;
} AllLights;

//Type definition of AllLights
typedef struct AllThieves
{
    unsigned short int lenght;
    Thief *thieves;
} AllThieves;

//Type definition of AllLights
typedef struct AllMoney
{
    unsigned short int lenght;
    Money *money;
} AllMoney;

/*
* function :
*           Allocate and initialize the memory and create a pointer on a table of "Light"
* 
* param :
*           unsigned short int lenght : The lenght of our table we want to allocate
*           unisgned short int windowWidth : The width of our graphical window
*           unsigned short int windowHeight : The height of our graphical window
*
* return :
*           AllLights* : A pointer on a table of "Light"
*/
AllLights* createAllLights(unsigned short int lenght, unsigned short int windowWidth, unsigned short int windowHeight);

/*
* function :
*           Allocate and initialize the memory and create a pointer on a table of "Thief"
* 
* param :
*           unsigned short int lenght : The lenght of our table we want to allocate
*           unisgned short int windowWidth : The width of our graphical window
*           unsigned short int windowHeight : The height of our graphical window
*
* return :
*           AllThieves* : A pointer on a table of "Thief"
*/
AllThieves* createAllThieves(unsigned short int lenght, unsigned short int windowWidth, unsigned short int windowHeight);

/*
* function :
*           Allocate and initialize the memory and create a pointer on a table of "Money"
* 
* param :
*           unsigned short int lenght : The lenght of our table we want to allocate
*           unisgned short int windowWidth : The width of our graphical window
*           unsigned short int windowHeight : The height of our graphical window
*
* return :
*           AllMoney* : A pointer on a table of "Money"
*/
AllMoney* createAllMoney(unsigned short int lenght, unsigned short int windowWidth, unsigned short int windowHeight);

/*
* function :
*           Free the memory used by a table of "Light"
* 
* param :
*           AllLights *tableOfLights : A pointer on a table of "Light"
*
* return :
*           void
*/
void deleteAllLights(AllLights **tableOfLights);

/*
* function :
*           Free the memory used by a table of "Thief"
* 
* param :
*           AllThieves *tableOfThieves : A pointer on a table of "Thief"
*
* return :
*           void
*/
void deleteAllThieves(AllThieves **tableOfThieves);

/*
* function :
*           Free the memory used by a table of "Money"
* 
* param :
*           AllMoney *tableOfMoney : A pointer on a table of "Money"
*
* return :
*           void
*/
void deleteAllMoney(AllMoney **tableOfMoney);

/*
* function :
*           Move by one pixel, all the lights in a random direction
* 
* param :
*           AllLights *tableOfLights : A pointer on a table of "Light"
*           unsigned short int speed : The light speed
*           unsigned short int windowWidth : The width of our graphical window
*           unsigned short int windowheight : The height of our graphical window
*
* return :
*           void
*/
void moveAllLights(AllLights *tableOfLights, unsigned short int speed, unsigned short int windowWidth, unsigned short int windowHeight);