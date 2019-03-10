#include <stdlib.h>		// For exit()
#include <stdio.h>		// For printf()
#include <math.h>		// For sin() and cos()
#include <strings.h>	// For bzero()
#include <stdbool.h>
#include "GfxLib.h"		// To do simple graphics
#include "ESLib.h"		// For valeurAleatoire()

#ifndef M_PI
#define M_PI 3.141592654
#endif

// To draw a circle
void circle(float xCenter, float yCenter, float radius)
{
	const int Steps = 16; // Number of sectors to draw a circle
	const double AngularSteps = 2.*M_PI/Steps;
	int index;

	for (index = 0; index < Steps; ++index) // For each sector
	{
		const double angle = 2.*M_PI*index/Steps; // Compute the starting angle
		triangle(xCenter, yCenter,
                xCenter+radius*cos(angle), yCenter+radius*sin(angle),
			     xCenter+radius*cos(angle+AngularSteps), yCenter+radius*sin(angle+AngularSteps));
	}
}

// Default width and height
#define WindowWidth 1200
#define WindowHeight 600

typedef enum {GoingUp = 0, Stable = 1, GoingDown = 2} State;
typedef enum {GoUp = 0, NoActivity = 1, GoDown = 2} Action;
const State automaton[3][3] = {{GoingUp, GoingUp, Stable},
	{GoingUp, Stable, GoingDown},
	{Stable, GoingDown, GoingDown}};

float Utility[3][3];
int position[WindowWidth];
State currentState;
int currentAbscissa; // Between 0 included and WindowWidth excluded

void initialize(void)
{
	State y;
	currentAbscissa = 1;
	currentState = Stable;
	for (y = GoingUp; y <= GoingDown; ++y)
	{
		Action x;
		for (x = GoUp; x <= GoDown; ++x)
			Utility[y][x] = 1.f;
	}
	bzero(position, sizeof(position));
	position[0] = position[1] = WindowHeight/4*(1+2*valeurAleatoire());
}

Action chooseAction(void)
{
	const float randomValue = valeurAleatoire()*(Utility[currentState][GoUp]+
											Utility[currentState][NoActivity]+
											Utility[currentState][GoDown]);
	Action returnValue = GoDown;

	if (randomValue < Utility[currentState][GoUp])
		returnValue = GoUp;
	else if (randomValue < Utility[currentState][GoUp]+Utility[currentState][NoActivity])
		returnValue = NoActivity;

	return returnValue;
}

bool animation;
int angle;
int middle;

float reward(void)
{
	const float deltaTemp = abs(position[currentAbscissa]-middle)-abs(position[currentAbscissa-1]-middle);
	float returnValue = 1.f;

	if (deltaTemp > 0.f)		// If the temperature increases
		returnValue = .5f;		// less pleasant
	else if (deltaTemp < 0.f)	// If the temperature decreases
		returnValue = 2.f;		// more pleasant

	return returnValue;
}

float ModificationStep = 0.f;
float Factor = .25f;

void updateUtility(State nextState, Action action)
{
	const float maxUtility = fmaxf(Utility[nextState][GoUp],
								   fmaxf(Utility[nextState][NoActivity], Utility[nextState][GoDown]));
	Utility[currentState][action] = (1.f-ModificationStep)*Utility[currentState][action]+ModificationStep*(reward()+Factor*maxUtility);
}

void update(Action action)
{
	State newState = automaton[currentState][action];
	++currentAbscissa;	// Update the abscissa
	switch (newState)	// Update height
	{
		case GoingUp:
			position[currentAbscissa] = position[currentAbscissa-1]+1;
			break;
		case Stable:
			position[currentAbscissa] = position[currentAbscissa-1];
			break;
		case GoingDown:
			position[currentAbscissa] = position[currentAbscissa-1]-1;
			break;
	}
	updateUtility(newState, action);	// Update utility function
	currentState = newState;			// Update state
}

void drawTrajectory(void)
{
	int index;

	epaisseurDeTrait(2);
	couleurCourante(255, 255, 255);
	for (index = 0; index < WindowWidth; ++index)
		point(index, position[index]);
}

void drawBackground(void)
{
	int index;

	epaisseurDeTrait(1.414);
	for (index = 0; index < WindowHeight; ++index)
	{
		int color = abs(index-middle);
		if (color > 255)
			color = 255;
		couleurCourante(color, 0, 255-color);
		ligne(0, index, WindowWidth-1, index);
	}
	couleurCourante(0, 0, 0);
	ligne(0, middle, WindowWidth-1, middle);
}

void drawUtility(void)
{
	const int drawStep = 20;
	State y;
	couleurCourante(0, 255, 0);
	for (y = GoingUp; y <= GoingDown; ++y)
	{
		Action x;
		for (x = GoUp; x <= GoDown; ++x)
		{
			circle(2*drawStep*(1+x), WindowHeight-2*drawStep*(1+y), drawStep/2*Utility[y][x]);
		}
	}
}

int main(int argc, char *argv[])
{
	initialiseGfx(argc, argv);

	prepareFenetreGraphique(argv[argc-1], WindowWidth, WindowHeight);
	lanceBoucleEvenements();

	return 0;
}


void gestionEvenement(EvenementGfx event)
{
	switch (event)
	{
		case Initialisation:
			demandeTemporisation(20);
			initialize();
			ModificationStep = 0.f;
			animation = false;
			middle = WindowHeight/2;
			angle = 0;
			break;

		case Temporisation:
			if (animation)
			{
				angle = (angle+1)%(360*16);
				middle = WindowHeight/2*(1+sin((angle>>3)*M_PI/180.)/2);
			}
			update(chooseAction());
			if (currentAbscissa == WindowWidth-1)
			{
				currentAbscissa = 1;
				position[0] = position[1] = position[WindowWidth-1];
			}
			rafraichisFenetre();
			break;

		case Affichage:
			effaceFenetre (0, 0, 0);
			drawBackground();
			drawUtility();
			drawTrajectory();
			epaisseurDeTrait(2);
			couleurCourante(255, 255, 255);
			afficheChaine("0..3 : step ; a : animate ; r : reset", 16, 5, 5);
			break;

		case Clavier:
			switch (caractereClavier())
			{
				case 'Q':
				case 'q':
					exit(0);
					break;

				case '0':
					ModificationStep = 0.f;
					break;

				case '1':
					ModificationStep = .1f;
					break;

				case '2':
					ModificationStep = .2f;
					break;

				case '3':
					ModificationStep = .3f;
					break;

				case '4':
					Factor = .25f;
					break;

				case '5':
					Factor = .5f;
					break;

				case '6':
					Factor = .75f;
					break;

				case 'R':
				case 'r':
					initialize();
					break;

				case 'A':
				case 'a':
					animation = !animation;
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
