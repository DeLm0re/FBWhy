/*
* Generic headers files :
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

/*
* Custom headers files :
*/
//To include graphical functions
#include "GfxLib.h"
//To include valeurAleatoire() function
#include "ESLib.h"
//To include the display functions of our program
#include "display.h"

//Definition of the frame rate in milliseconds (FPmS)
#define FRAME_RATE (10)
#define FRAME_RATE_DEBUG (10000)

//Definition of the number of lights
#define NUMBER_OF_LIGHTS (10)

//Definition of the number of thieves
#define NUMBER_OF_THIEVES (8)

//Definition of the number of money
#define NUMBER_OF_MONEY (8)

AllLights *myLights = NULL;
AllThieves *myThieves = NULL;
AllMoney *myMoney = NULL;

/*
Automaton theAutomaton = {
							{GoingUp, GoingUpRight, GoingUpRight, Stable, Stable, Stable, GoingUpLeft, GoingUpLeft, GoingUp},
						  	{GoingUp, GoingUpRight, GoingRight, GoingRight, Stable, Stable, Stable, GoingUp, GoingUpRight},
						  	{GoingUpRight, GoingUpRight, GoingRight, GoingDownRight, GoingDownRight, Stable, Stable, Stable, GoingRight},
							{Stable, GoingRight, GoingRight, GoingDownRight, GoingDown, GoingDown, Stable, Stable, GoingDownRight},
							{Stable, Stable, GoingDownRight, GoingDownRight, GoingDown, GoingDownLeft, GoingDownLeft, Stable, GoingDown},
							{Stable, Stable, Stable, GoingDown, GoingDown, GoingDownLeft, GoingLeft, GoingLeft, GoingDownLeft},
							{GoingUpLeft, Stable, Stable, Stable, GoingDownLeft, GoingDownLeft, GoingLeft, GoingUpLeft, GoingLeft},
							{GoingUp, GoingUp, Stable, Stable, Stable, GoingLeft, GoingLeft, GoingUpLeft, GoingUpLeft},
							{GoingUp, GoingUpRight, GoingRight, GoingDownRight, GoingDown, GoingDownLeft, GoingLeft, GoingUpLeft, Stable}
						};
*/

Automaton theAutomaton = {
							{GoingUp, GoingRight, Stable, GoingLeft, GoingUp},
						  	{GoingUp, GoingRight, GoingDown, Stable, GoingRight},
							{Stable, GoingRight, GoingDown, GoingLeft, GoingDown},
							{GoingUp, Stable, GoingDown, GoingLeft, GoingLeft},
							{GoingUp, GoingRight, GoingDown, GoingLeft, Stable}
						};

int main(int argc, char *argv[])
{
	initialiseGfx(argc, argv);

	srand(time(NULL));

	prepareFenetreGraphique("FBWhy", WindowWidth, WindowHeight);
	lanceBoucleEvenements();

	return 0;
}

void gestionEvenement(EvenementGfx event)
{
	static unsigned short int etape;

	static bool moveLights;

	switch (event)
	{
		case Initialisation:
			etape = 0;
			moveLights = true;

			demandeTemporisation(FRAME_RATE);
			//demandeTemporisation(FRAME_RATE_DEBUG);
			break;

		case Temporisation:
			if(etape > 0)
			{
				if(moveLights == true)
				{
					moveAllLights(myLights, largeurFenetre(), hauteurFenetre());
					updateAllThieves(theAutomaton, myThieves, myLights, myMoney);
				}
				else
				{
					updateAllThieves(theAutomaton, myThieves, myLights, myMoney);
				}
			}
			rafraichisFenetre();
			break;

		case Affichage:

			if(etape == 0)
			{
				effaceFenetre (0, 0, 0);
				drawBorders();
				myLights = createAllLights(NUMBER_OF_LIGHTS, largeurFenetre(), hauteurFenetre());
				myMoney = createAllMoney(NUMBER_OF_MONEY);
				myThieves = createAllThieves(NUMBER_OF_THIEVES);
				positionElements(myLights, myThieves, myMoney, largeurFenetre(), hauteurFenetre());

				/*
				printf("Distance sum lights %f \n", myThieves->thieves[0].currentLightsDistance);
				printf("Index nearest money %u \n", myThieves->thieves[0].nearestMoney);
				printf("Distance nearest money %f \n", myThieves->thieves[0].currentMoneyDistance);
				*/

				etape++;
			}

			if(etape == 1)
			{
				effaceFenetre (0, 0, 0);
				drawAllLights(myLights);
				drawAllThieves(myThieves);
				drawAllMoney(myMoney);
				drawBorders();
			}
			break;

		case Clavier:
			switch (caractereClavier())
			{
				case 'Q':
				case 'q':
					deleteAllLights(&myLights);
					deleteAllMoney(&myMoney);
					deleteAllThieves(&myThieves);
					termineBoucleEvenements();
					break;

				case 'R':
				case 'r':
					deleteAllLights(&myLights);
					deleteAllMoney(&myMoney);
					deleteAllThieves(&myThieves);
					etape = 0;
					rafraichisFenetre();
					break;

				case 'M':
				case 'm':
					if(moveLights == true)
					{
						moveLights = false;
					}
					else
					{
						moveLights = true;
					}
					break;
			}
			break;

		case ClavierSpecial:
			break;
		case BoutonSouris:
			break;
		case Souris:
			break;
		case Inactivite:
			break;
		case Redimensionnement:
			break;
	}
}
