#include <stdlib.h> // For exit()
#include <stdio.h> // For printf()
#include <math.h> // For sin() and cos()
#include "GfxLib.h" // To do simple graphics
#include "ESLib.h" // For valeurAleatoire()

#ifndef M_PI
#define M_PI 3.141592654
#endif

// Default width and height
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
