//To include the functions prototypes
#include "display.h"

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
void drawBorders()
{
    epaisseurDeTrait(1);
    couleurCourante(255, 255, 255);
    ligne(0,0,largeurFenetre(),0);
	ligne(0,0,0,hauteurFenetre());
	ligne(0,hauteurFenetre(),largeurFenetre(),hauteurFenetre());
	ligne(largeurFenetre(),0,largeurFenetre(),hauteurFenetre());
}

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
void drawCircle(unsigned short int xCenter, unsigned short int yCenter, float radius)
{
    const int Steps = NUMBER_SECTORS;

	const double AngularSteps = 2.*M_PI/Steps;

	int index;

	for (index = 0; index < Steps; ++index)
	{
		const double angle = 2.*M_PI*index/Steps;

		triangle(xCenter, yCenter,
                xCenter+radius*cos(angle), yCenter+radius*sin(angle),
			     xCenter+radius*cos(angle+AngularSteps), yCenter+radius*sin(angle+AngularSteps));
	}
}

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
void drawAllLights(AllLights *myLights)
{
    unsigned short int index;

    unsigned short int maxRadius;
    unsigned short int currentRadius;

    epaisseurDeTrait(1);

	for(index = 0; index < myLights->lenght; index++)
	{
        maxRadius = myLights->lights[index].radius;

        for(currentRadius = maxRadius; currentRadius >= (MINIMUM_LIGHT_RADIUS/2); currentRadius--)
        {
            couleurCourante(
                    rescale(currentRadius, maxRadius, 0, 0, 255),
                    rescale(currentRadius, maxRadius, 0, 0, 255),
                    rescale(currentRadius, maxRadius, 0, 0, 255)
                    );

            drawCircle(myLights->lights[index].x, myLights->lights[index].y, currentRadius);
        }

        couleurCourante(255, 255, 255);
        drawCircle(myLights->lights[index].x, myLights->lights[index].y, (MINIMUM_LIGHT_RADIUS/2));
	}
}

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
void drawAllThieves(AllThieves *myThieves)
{
    unsigned short int index;

    epaisseurDeTrait(3);

	for(index = 0; index < myThieves->lenght; index++)
	{
        couleurCourante(255, 0, 0);
        point(myThieves->thieves[index].x, myThieves->thieves[index].y);
	}
}

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
void drawAllMoney(AllMoney *myMoney)
{
    unsigned short int index;

    epaisseurDeTrait(3);

	for(index = 0; index < myMoney->lenght; index++)
	{
        couleurCourante(255, 255, 0);
        point(myMoney->money[index].x, myMoney->money[index].y);
	}
}