//Les fichiers d'en-tête
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
//Cet include permet de manipuler des fichiers BMP
#include "BmpLib.h"
//Cet include est nécessaire pour le graphique
#include "GfxLib.h"
#include "core.h"

//Définition du type struct pixel
typedef struct pixel {
	short int rouge;
	short int vert;
	short int bleu;
}pixel;

//Déclaration du type struct imagePixel
typedef struct imagePixel{
	int largeur;
	int hauteur;
	pixel **pixels;
}imagePixel;

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
imagePixel* creerImagePixel(int hauteur, int largeur, unsigned char valeur);

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
void alloueImagePixel(imagePixel **image, unsigned char valeur);

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
void libereImagePixel(imagePixel **image);

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
imagePixel* conversionDonneesImageRGB(DonneesImageRGB *pImageRGB);

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
DonneesImageRGB* conversionImagePixel(imagePixel *pImagePixel);
