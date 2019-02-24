//To include the functions prototypes
#include "core.h"

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
AllLights* createAllLights(unsigned short int lenght, unsigned short int windowWidth, unsigned short int windowHeight)
{
    int index;

    AllLights *tableOfLights = (AllLights*)malloc(sizeof(AllLights));

    tableOfLights->lenght = lenght;

    tableOfLights->lights = malloc(sizeof(Light) * lenght);

    for(index = 0; index < tableOfLights->lenght; index++)
    {
        tableOfLights->lights[index].x = rand() % windowWidth;
        tableOfLights->lights[index].y = rand() % windowHeight;
        tableOfLights->lights[index].radius = rand() % (MAXIMUM_LIGHT_RADIUS - MINIMUM_LIGHT_RADIUS + 1) + MINIMUM_LIGHT_RADIUS;
    }

    return(tableOfLights);
}

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
AllThieves* createAllThieves(unsigned short int lenght, unsigned short int windowWidth, unsigned short int windowHeight)
{
    int index;

    AllThieves *tableOfThieves = (AllThieves*)malloc(sizeof(AllThieves));

    tableOfThieves->lenght = lenght;

    tableOfThieves->thieves = malloc(sizeof(Thief) * lenght);

    for(index = 0; index < tableOfThieves->lenght; index++)
    {
        tableOfThieves->thieves[index].x = rand() % windowWidth;
        tableOfThieves->thieves[index].y = rand() % windowHeight;
        //Verification x,y =/= light(x,y) + radius to add
    }

    return(tableOfThieves);
}

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
AllMoney* createAllMoney(unsigned short int lenght, unsigned short int windowWidth, unsigned short int windowHeight)
{
    int index;

    AllMoney *tableOfMoney = (AllMoney*)malloc(sizeof(AllMoney));

    tableOfMoney->lenght = lenght;

    tableOfMoney->money = malloc(sizeof(Money) * lenght);

    for(index = 0; index < tableOfMoney->lenght; index++)
    {
        tableOfMoney->money[index].x = rand() % windowWidth;
        tableOfMoney->money[index].y = rand() % windowHeight;
        //Verification x,y =/= thief(x,y) to add
    }

    return(tableOfMoney);
}

/*
* function :
*           free the memory used by a table of "Light"
* 
* param :
*           AllLights *tableOfLights : A pointer on a table of "Light"
*
* return :
*           void
*/
void deleteAllLights(AllLights **tableOfLights)
{
    free((*tableOfLights)->lights);
    free(*tableOfLights);

    *tableOfLights = NULL;
}

/*
* function :
*           free the memory used by a table of "Thief"
* 
* param :
*           AllThieves *tableOfThieves : A pointer on a table of "Thief"
*
* return :
*           void
*/
void deleteAllThieves(AllThieves **tableOfThieves)
{
    free((*tableOfThieves)->thieves);
    free(*tableOfThieves);

    *tableOfThieves = NULL;
}

/*
* function :
*           free the memory used by a table of "Money"
* 
* param :
*           AllMoney *tableOfMoney : A pointer on a table of "Money"
*
* return :
*           void
*/
void deleteAllMoney(AllMoney **tableOfMoney)
{
    free((*tableOfMoney)->money);
    free(*tableOfMoney);

    *tableOfMoney = NULL;
}