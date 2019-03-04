/*
* Generic headers files :
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

//Definition of our maximum/minimum light radius
#define MAXIMUM_LIGHT_RADIUS (70)
#define MINIMUM_LIGHT_RADIUS (60)

//Definition of the distance between the money and the thieves at the initialization
#define DISTANCE_MONEY_THIEVES (200)

//Type definition of Light
typedef struct Light
{
    unsigned short int x;
    unsigned short int y;
    unsigned short int radius;
    unsigned short int xDirection;
    unsigned short int yDirection;
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
*
* return :
*           AllThieves* : A pointer on a table of "Thief"
*/
AllThieves* createAllThieves(unsigned short int lenght);

/*
* function :
*           Allocate and initialize the memory and create a pointer on a table of "Money"
* 
* param :
*           unsigned short int lenght : The lenght of our table we want to allocate
*
* return :
*           AllMoney* : A pointer on a table of "Money"
*/
AllMoney* createAllMoney(unsigned short int lenght);

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
*           unsigned short int windowWidth : The width of our graphical window
*           unsigned short int windowheight : The height of our graphical window
*
* return :
*           void
*/
void moveAllLights(AllLights *tableOfLights, unsigned short int windowWidth, unsigned short int windowHeight);

/*
* function :
*           Transform a floating value between two values in an other floating value between two other values
*           Proportions are saved
* 
* param :
*           float value : The value to transform
*           float minValue : The first minimum value
*           float maxValue : The first maximum value
*           float newMin : The new minimum value
*           float newMax : The new maximum value
*
* return :
*           void
*/
float rescale(float value, float minValue, float maxValue, float newMin, float newMax);

/*
* function :
*           Calcul all the positions of our elements
*           - Thieves can not be under lights, because they will "die" instantly
*           - Money can not be near thieves, because it's to easy for the learning
* 
* param :
*           AllLights *tableOfLights : A pointer on a table of "Light"
*           AllThieves *tableOfThieves : A pointer on a table of "Thieves"
*           AllMoney *tableOfMoney : A pointer on a table of "Money"
*           unsigned short int windowWidth : The width of our graphical window
*           unsigned short int windowheight : The height of our graphical window
*
* return :
*           void
*/
void positionElements(AllLights *tableOfLights, AllThieves *tableOfThieves, AllMoney *tableOfMoney, unsigned short int windowWidth, unsigned short int windowHeight);

/*
* function :
*           Tell if a thief is to near or under a light
* 
* param :
*           AllThieves *tableOfThieves : A pointer on a table of "Thieves"
*           unsigned short int indexThieves : The index in the table of "Thieves" of our thief we want to analyze
*           AllLights *tableOfLights : A pointer on a table of "Lights"
*
* return :
*           boolean
*           - True, the thief is to near or under a light
*           - False, the thief have a good position
*/
bool thiefUnderLights(AllThieves *tableOfThieves, unsigned short int indexThieves, AllLights *tableOfLights);

/*
* function :
*           Tell if a money is to near with a thief
* 
* param :
*           AllMoney *tableOfMoney : A pointer on a table of "Money"
*           unsigned short int indexMoney : The index in the table of "Money" of our thief we want to analyze
*           AllThieves *tableOfThieves : A pointer on a table of "Thieves"
*
* return :
*           boolean
*           - True, the money is to near with a thief
*           - False, the money have a good position
*/
bool moneyOnThieves(AllMoney *tableOfMoney, unsigned short int indexMoney, AllThieves *tableOfThieves);