/**
 * \file dictionnairePrive.h
 * \brief Fichier .h des fonctions privée du TAD Dictionnaire
 * \version 1.0
 * \date 24/12/2021
 *
 */

#ifndef __DICTIONNAIRE_PRIVE__
#define __DICTIONNAIRE_PRIVE__

/**
 *\fn int max(int a, int b)
 *\brief Renvoie le maximum des nombres a et de b
 *
 *\param a : entier
 *\param b : entier
 *\return entier
*/
int max(int a, int b);

/**
 *\fn int abs(int a)
 *\brief Renvoie la valeur absolue du nombres a
 *
 *\param a : entier
 *\return entier positif
*/
int abs(int a);
DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaire();
int DICTIONNAIRE_estVide(DICTIONNAIRE_Dictionnaire dictionnaire);
DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);
DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire);
MOT_Mot DICTIONNAIRE_obtenirMot(DICTIONNAIRE_Dictionnaire dictionnaire);
void DICTIONNAIRE_fixerMot(DICTIONNAIRE_Dictionnaire *dictionnaire,MOT_Mot mot);
void DICTIONNAIRE_fixerFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsGauche);
void DICTIONNAIRE_fixerFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsDroit);
void DICTIONNAIRE_simpleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire);
void DICTIONNAIRE_simpleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);
void DICTIONNAIRE_doubleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire);
void DICTIONNAIRE_doubleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);
int DICTIONNAIRE_hauteur(DICTIONNAIRE_Dictionnaire dictionnaire);
void DICTIONNAIRE_reequilibrer(DICTIONNAIRE_Dictionnaire *dictionnaire);

#endif