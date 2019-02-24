/*
* Generic headers files :
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
* Custom headers files :
*/
//To include graphical functions
#include "GfxLib.h"
//To include valeurAleatoire() function
#include "ESLib.h"
//To include the core functions of our program
#include "core.h"
//To include the display functions of our program
#include "display.h"

//Default width and height
#define WindowWidth 800
#define WindowHeight 600

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
			demandeTemporisation(-1);
			break;

		case Temporisation:
			rafraichisFenetre();
			break;

		case Affichage:
			effaceFenetre (0, 0, 0);
			epaisseurDeTrait(2);
			couleurCourante(0, 200, 255);
			afficheChaine("1 : 180° ; 7 : 720° ; i : iterate ; r : reset", 16, 5, 5);
			break;

		case Clavier:
			switch (caractereClavier())
			{
				case 'Q':
				case 'q':
					termineBoucleEvenements();
					break;

				case 'R':
				case 'r':
					rafraichisFenetre();
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
