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
        tableOfLights->lights[index].x = rand() % ((windowWidth-10) - 10 + 1) + 10;
        tableOfLights->lights[index].y = rand() % ((windowHeight-10) -10 + 1) + 10;
        tableOfLights->lights[index].radius = rand() % (MAXIMUM_LIGHT_RADIUS - MINIMUM_LIGHT_RADIUS + 1) + MINIMUM_LIGHT_RADIUS;

        tableOfLights->lights[index].xDirection = rand() % 2;
        if(tableOfLights->lights[index].xDirection == 0)
        {
            tableOfLights->lights[index].xDirection = -1;
        }
        if(tableOfLights->lights[index].xDirection == 1)
        {
            tableOfLights->lights[index].xDirection = 1;
        }

        tableOfLights->lights[index].yDirection = rand() % 2;
        if(tableOfLights->lights[index].yDirection == 0)
        {
            tableOfLights->lights[index].yDirection = -1;
        }
        if(tableOfLights->lights[index].yDirection == 1)
        {
            tableOfLights->lights[index].yDirection = 1;
        }
    }

    return(tableOfLights);
}

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
AllThieves* createAllThieves(unsigned short int lenght)
{
    int index;

    AllThieves *tableOfThieves = (AllThieves*)malloc(sizeof(AllThieves));

    tableOfThieves->lenght = lenght;

    tableOfThieves->thieves = malloc(sizeof(Thief) * lenght);

    for(index = 0; index < tableOfThieves->lenght; index++)
    {
        tableOfThieves->thieves[index].x = 0;
        tableOfThieves->thieves[index].y = 0;
    }

    return(tableOfThieves);
}

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
AllMoney* createAllMoney(unsigned short int lenght)
{
    int index;

    AllMoney *tableOfMoney = (AllMoney*)malloc(sizeof(AllMoney));

    tableOfMoney->lenght = lenght;

    tableOfMoney->money = malloc(sizeof(Money) * lenght);

    for(index = 0; index < tableOfMoney->lenght; index++)
    {
        tableOfMoney->money[index].x = 0;
        tableOfMoney->money[index].y = 0;
    }

    return(tableOfMoney);
}

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
void deleteAllLights(AllLights **tableOfLights)
{
    free((*tableOfLights)->lights);
    free(*tableOfLights);

    *tableOfLights = NULL;
}

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
void deleteAllThieves(AllThieves **tableOfThieves)
{
    free((*tableOfThieves)->thieves);
    free(*tableOfThieves);

    *tableOfThieves = NULL;
}

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
void deleteAllMoney(AllMoney **tableOfMoney)
{
    free((*tableOfMoney)->money);
    free(*tableOfMoney);

    *tableOfMoney = NULL;
}

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
void moveAllLights(AllLights *tableOfLights, unsigned short int windowWidth, unsigned short int windowHeight)
{
    unsigned short int index;

    for(index = 0; index < tableOfLights->lenght; index ++)
    {
        tableOfLights->lights[index].x += tableOfLights->lights[index].xDirection;
        if(tableOfLights->lights[index].x >= windowWidth)
        {
            tableOfLights->lights[index].x --;
            tableOfLights->lights[index].xDirection = -tableOfLights->lights[index].xDirection;
        }
        if(tableOfLights->lights[index].x <= 0)
        {
            tableOfLights->lights[index].x ++;
            tableOfLights->lights[index].xDirection = -tableOfLights->lights[index].xDirection;
        }
        tableOfLights->lights[index].y += tableOfLights->lights[index].yDirection;
        if(tableOfLights->lights[index].y >= windowHeight)
        {
            tableOfLights->lights[index].y --;
            tableOfLights->lights[index].yDirection = -tableOfLights->lights[index].yDirection;
        }
        if(tableOfLights->lights[index].y <= 0)
        {
            tableOfLights->lights[index].y ++;
            tableOfLights->lights[index].yDirection = -tableOfLights->lights[index].yDirection;
        }
    }
}

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
float rescale(float value, float minValue, float maxValue, float newMin, float newMax)
{
	float betweenValue = (maxValue - minValue);

	float newValue = (value - minValue) / betweenValue;

	return(newMin + newValue * (newMax - newMin));
}

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
void positionElements(AllLights *tableOfLights, AllThieves *tableOfThieves, AllMoney *tableOfMoney, unsigned short int windowWidth, unsigned short int windowHeight)
{
    unsigned short int indexThieves;
    unsigned short int indexMoney;

    for(indexThieves = 0; indexThieves < tableOfThieves->lenght; indexThieves++)
    {
        do
        {
            tableOfThieves->thieves[indexThieves].x = rand() % ((windowWidth-10) -10 + 1) + 10;
            tableOfThieves->thieves[indexThieves].y = rand() % ((windowHeight-10) -10 + 1) + 10;

        }while(thiefUnderLights(tableOfThieves, indexThieves, tableOfLights) == true);
    }

    for(indexMoney = 0; indexMoney < tableOfThieves->lenght; indexMoney++)
    {
        do
        {
            tableOfMoney->money[indexMoney].x = rand() % ((windowWidth-10) -10 + 1) + 10;
            tableOfMoney->money[indexMoney].y = rand() % ((windowHeight-10) -10 + 1) + 10;

        }while(moneyOnThieves(tableOfMoney, indexMoney, tableOfThieves) == true);
    }
}

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
bool thiefUnderLights(AllThieves *tableOfThieves, unsigned short int indexThieves, AllLights *tableOfLights)
{
    float distance;
    unsigned short int radiusPow = (MINIMUM_LIGHT_RADIUS/2) * (MINIMUM_LIGHT_RADIUS/2);

    unsigned short int indexLights;

    unsigned short int incrementLights = 0;

    for(indexLights = 0; indexLights < tableOfLights->lenght; indexLights++)
    {
        distance = (tableOfThieves->thieves[indexThieves].x - tableOfLights->lights[indexLights].x)
                    + (tableOfThieves->thieves[indexThieves].y - tableOfLights->lights[indexLights].y);

        if(distance > radiusPow)
        {
            incrementLights++;
        }
    }

    if(incrementLights == tableOfLights->lenght)
    {
        return(false);
    }
    
    return(true);
}

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
bool moneyOnThieves(AllMoney *tableOfMoney, unsigned short int indexMoney, AllThieves *tableOfThieves)
{
    float distance;
    unsigned short int radiusPow = DISTANCE_MONEY_THIEVES * DISTANCE_MONEY_THIEVES;

    unsigned short int indexThieves;

    unsigned short int incrementThieves = 0;

    for(indexThieves = 0; indexThieves  < tableOfThieves ->lenght; indexThieves ++)
    {
        distance = (tableOfMoney->money[indexMoney].x - tableOfThieves->thieves[indexThieves].x)
                    + (tableOfMoney->money[indexMoney].y - tableOfThieves->thieves[indexThieves].y);

        if(distance > radiusPow)
        {
            incrementThieves++;
        }
    }

    if(incrementThieves == tableOfThieves->lenght)
    {
        return(false);
    }
    
    return(true);
}