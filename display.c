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
*           unsigned short int radius : The radius of our circle
*
* return :
*           void
*/
void drawCircle(unsigned short int xCenter, unsigned short int yCenter, unsigned short int radius)
{
    short int x, y;
    
    unsigned short int distancePow2;

    unsigned short int radiusPow2 = radius * radius;

    for(y = yCenter - radius; y <= yCenter + radius; y++)
    {
        for(x = xCenter - radius; x <= xCenter + radius; x++)
        {
            if( (y >= 0) || (y < WindowHeight) || (x >= 0) || (x < WindowWidth) )
            {
                distancePow2 = (y - yCenter)*(y - yCenter) + (x - xCenter)*(x - xCenter);
                    
                if(distancePow2 <= radiusPow2)
                {
                    point(x, y);
                }
            }
        }
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

	for(index = 0; index < myLights->lenght; index++)
	{
		couleurCourante(255, 255, 255);
		drawCircle(myLights->lights[index].x, myLights->lights[index].y, myLights->lights[index].radius);
	}
}