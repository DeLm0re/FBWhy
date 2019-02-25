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

    epaisseurDeTrait(1);

    unsigned short int maxRadius;
    short int currentRadius;

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