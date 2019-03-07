//Les fichiers d'en-tête
#include "image.h"

/* @function
 * 			imagePixel* creerImagePixel(int hauteur, int largeur, unsigned char valeur)
 * 
 * @brief
 * 			Fonction qui creer une image de type imagePixel
 * 
 * @param
 * 			int hauteur : La hauteur de l'image à créer
 * 			int largeur : La largeur de l'image à créer
 * 			unsigned char valeur : La valeur de fond de l'image à créer (appliquée à RGB)
 * 
 * @return
 * 			imagePixel* : Un pointeur vers l'image de type imagePixel que l'on a créer
 * */
imagePixel* creerImagePixel(int hauteur, int largeur, unsigned char valeur)
{
	//Déclaration de notre imagePixel
	imagePixel *uneImagePixel;
	
	//Allocation de cette imagePixel
	uneImagePixel = (imagePixel*)malloc(sizeof(*uneImagePixel));
	
	uneImagePixel->largeur = largeur;
	uneImagePixel->hauteur = hauteur;
	
	alloueImagePixel(&uneImagePixel, valeur);
	
	//On retourne le pointeur de notre imagePixel
	return(uneImagePixel);	
}

/* @function
 * 			void alloueImagePixel(imagePixel **image, unsigned char valeur)
 * 
 * @brief
 * 			Fonction qui initialise les valeurs RGB d'une image sur le point d'être créer
 * 
 * @param
 * 			imagePixel **image : Un double pointeur vers l'image de type imagePixel dont nous souhaitons initialiser les valeurs RGB
 * 			unsigned char valeur : La valeur RGB de l'initialisation
 * 
 * @return
 * 			void
 * */
void alloueImagePixel(imagePixel **image, unsigned char valeur)
{
	//Déclaration des compteurs pour les boucles for
	int i;
	int j;
	
	//Allocation 1D
	(*image)->pixels = malloc(sizeof(pixel*) * (*image)->hauteur);
	
	//On intialise les pointeurs à NULL
	for(i = 0; i < (*image)->hauteur; i++)
	{
		(*image)->pixels[i] = NULL;
	}
	
	for(j = 0; j < (*image)->hauteur; j++)
	{
		//Allocation 2D
		(*image)->pixels[j] = malloc(sizeof(pixel) * (*image)->largeur);
	}
	
	//On initialise les valeurs à la valeur passée en parametre
	for(i = 0; i < (*image)->hauteur; i++)
	{
		for(j = 0; j < (*image)->largeur; j++)
		{
			(*image)->pixels[i][j].rouge = valeur;
			(*image)->pixels[i][j].vert = valeur;
			(*image)->pixels[i][j].bleu = valeur;
		}
	}
}

/* @function
 * 			void libereImagePixel(imagePixel **image)
 * 
 * @brief
 * 			Fonction qui libère une image de type imagePixel
 * 
 * @param
 * 			imagePixel **image : Un double pointeur vers l'image de type imagePixel que l'on veut libérer
 * 
 * @return
 * 			void
 * */
void libereImagePixel(imagePixel **image)
{
	//Déclaration d'un compteur pour la boucle for
	int j;
	
	for(j = 0; j < (*image)->hauteur; j++)
	{
		//Free 2D
		free((*image)->pixels[j]);
	}
	
	//Free 1D
	free((*image)->pixels);
	
	//Free de l'imagePixel
	free((*image));
}

/* @function
 * 			imagePixel* conversionDonneesImageRGB(DonneesImageRGB *pImageRGB)
 * 
 * @brief
 * 			Fonction qui convertie une image de type DonneesImageRGB en image de type imagePixel
 * 
 * @param
 * 			DonneesImageRGB *pImageRGB : Un pointeur vers l'image de type DonneesImageRGB que l'on veut convertir
 * 
 * @return
 * 			imagePixel* : Un pointeur vers l'image convertie de type imagePixel
 * */
imagePixel* conversionDonneesImageRGB(DonneesImageRGB *pImageRGB)
{
	//Déclaration des variables pour les boucles for
	int i;
	int j;
	
	//Déclaration et initialisation d'un compteur pour les traitements
	int compteur = 0;
	
	//Déclaration des dimensions
	int hauteur = pImageRGB->hauteurImage;
	int largeur = pImageRGB->largeurImage;
	
	//Création d'une imagePixel
	imagePixel *retour = creerImagePixel(hauteur, largeur, 0);
	
	//Copie des dimensions
	retour->largeur = largeur;
	retour->hauteur = hauteur;
	
	//Copie des valeurs
	for(i = 0; i < hauteur; i++)
	{
		for(j = 0; j < largeur; j++)
		{
			(retour->pixels[i][j]).bleu = pImageRGB->donneesRGB[compteur];
			(retour->pixels[i][j]).vert = pImageRGB->donneesRGB[compteur+1];
			(retour->pixels[i][j]).rouge = pImageRGB->donneesRGB[compteur+2];
			compteur = compteur + 3;
		}
	}
	
	libereDonneesImageRGB(&pImageRGB);
	
	//On retourne le pointeur
	return(retour);
}

/* @function
 * 			DonneesImageRGB* conversionImagePixel(imagePixel *pImagePixel)
 * 
 * @brief
 * 			Fonction qui convertie une image de type imagePixel en image de type DonneesImageRGB
 * 
 * @param
 * 			imagePixel *pImagePixel : Un pointeur vers l'image de type imagePixel que l'on veut convertir
 * 
 * @return
 * 			DonneesImageRGB* : Un pointeur vers l'image convertie de type DonneesImageRGB
 * */
DonneesImageRGB* conversionImagePixel(imagePixel *pImagePixel)
{
	//Déclaration des variables pour les boucles for
	int i;
	int j;
		
	//Déclaration et initialisation d'un compteur pour les traitements
	int compteur = 0;
	
	//Déclaration des dimensions
	int hauteur = pImagePixel->hauteur;
	int largeur = pImagePixel->largeur;
	int taille = largeur * hauteur;
	
	//Allocation et initialisation du futur pointeur à retourner
	DonneesImageRGB *retour = (DonneesImageRGB*)malloc(sizeof(DonneesImageRGB));
	retour->donneesRGB = (unsigned char*)malloc(sizeof(*(retour->donneesRGB)) * taille * 3);
	retour->largeurImage = largeur;
	retour->hauteurImage = hauteur;
	
	//Copie des valeurs
	for(i = (hauteur-1); i >= 0; i--)
	{
		for(j = 0; j < largeur; j++)
		{
			retour->donneesRGB[compteur] = (pImagePixel->pixels[i][j]).bleu;
			retour->donneesRGB[compteur+1] = (pImagePixel->pixels[i][j]).vert;
			retour->donneesRGB[compteur+2] = (pImagePixel->pixels[i][j]).rouge;
			compteur = compteur + 3;
		}
	}
	
	libereImagePixel(&pImagePixel);
	
	//On retourne le pointeur
	return(retour);
}
