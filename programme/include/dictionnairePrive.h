/**
 * \file dictionnairePrive.h
 * \brief Fichier .h des fonctions privées du TAD Dictionnaire
 * \version 1.0
 * \date 24/12/2021
 *
 */

#ifndef __DICTIONNAIRE_PRIVE__
#define __DICTIONNAIRE_PRIVE__

/**
 *\fn int max(int a, int b)
 *\brief Renvoie le maximum entre a et b.
 *
 *\param a : entier
 *\param b : entier
 *\return entier
*/
int max(int a, int b);

/**
 *\fn int abs(int a)
 *\brief Renvoie la valeur absolue du nombre a.
 *
 *\param a : entier
 *\return entier positif
*/
int abs(int a);

/**
 *\fn DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaire(MOT_Mot mot)
 *\brief Crée un Dictionnaire ayant pour valeur le mot mot et pour fils droit et gauche des dictionnaires vides.
 *
 *\param mot : MOT_Mot
 *\return dictionnaire
*/
DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaire(MOT_Mot mot);

/**
 *\fn int DICTIONNAIRE_estVide(DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief Verifie si le dictionnaire est vide.
 *
 *\param dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return booléen (int) si vrai 1, sinon 0
*/
int DICTIONNAIRE_estVide(DICTIONNAIRE_Dictionnaire dictionnaire);

/**
 *\fn DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief Obtenir le fils gauche du dictionnaire.
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return *dictionnaire 
*/
DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief Obtenir le fils droit du dictionnaire.
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return *dictionnaire
*/
DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn MOT_Mot DICTIONNAIRE_obtenirMot(DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief Obtenir le mot du noeud racine de dictionnaire.
 *
 *\param *dictionnaire : le pointeur sur le DICTIONNAIRE_Dictionnaire dans lequel on agit
 *\return MOT_Mot
*/
MOT_Mot DICTIONNAIRE_obtenirMot(DICTIONNAIRE_Dictionnaire dictionnaire);

/**
 *\fn DICTIONNAIRE_fixerMot(DICTIONNAIRE_Dictionnaire *dictionnaire,MOT_Mot mot)
 *\brief Insère un mot dans un dictionnaire.
 *
 *\param *dictionnaire : le pointeur sur le DICTIONNAIRE_Dictionnaire dans lequel on agit
 *\param mot : MOT_Mot
 *\return dictionnaire
*/
void DICTIONNAIRE_fixerMot(DICTIONNAIRE_Dictionnaire *dictionnaire,MOT_Mot mot);

/**
 *\fn void DICTIONNAIRE_fixerFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsGauche)
 *\brief Fixer fils Gauche dans le Dictionnaire.
 *
 *\param *dictionnaire : le pointeur sur le DICTIONNAIRE_Dictionnaire dans lequel on agit
 *\param filsGauche : DICTIONNAIRE_Dictionnaire
 *\return dictionnaire
*/
void DICTIONNAIRE_fixerFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsGauche);

/**
 *\fn  void DICTIONNAIRE_fixerFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsDroit)
 *\brief Fixer fils Droit dans le Dictionnaire.
 *
 *\param *dictionnaire : le pointeur sur le DICTIONNAIRE_Dictionnaire dans lequel on agit
 *\param filsDroit : DICTIONNAIRE_dictionnaire
 *\return dictionnaire
*/
void DICTIONNAIRE_fixerFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsDroit);

/**
 *\fn void DICTIONNAIRE_simpleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief Faire une simple rotation à droite.
 *\attention precondition : le dictionnaire ne doit pas être vide, tout comme son fils gauche.
 *
 *\param *dictionnaire : le pointeur sur le DICTIONNAIRE_Dictionnaire dans lequel on agit
 *\return dictionnaire
*/
void DICTIONNAIRE_simpleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn void DICTIONNAIRE_simpleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief Faire une simple rotation à gauche.
 *\attention precondition : le dictionnaire ne doit pas être vide, tout comme son fils droit.
 *
 *\param *dictionnaire : le pointeur sur le DICTIONNAIRE_Dictionnaire dans lequel on agit
 *\return dictionnaire
*/
void DICTIONNAIRE_simpleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn void DICTIONNAIRE_doubleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief Faire une double rotation à droite.
 *\attention precondition : le dictionnaire ne doit pas être vide, tout comme son fils gauche ainsi que le fils droit du même fils gauche.
 *
 *\param *dictionnaire : le pointeur sur le DICTIONNAIRE_Dictionnaire dans lequel on agit
 *\return dictionnaire
*/
void DICTIONNAIRE_doubleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn void DICTIONNAIRE_doubleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief  Faire une double rotation à gauche.
 *\attention precondition : le dictionnaire ne doit pas être vide, tout comme son fils droit ainsi que le fils gauche du même fils droit.
 *
 *\param *dictionnaire : le pointeur sur le DICTIONNAIRE_Dictionnaire dans lequel on agit
 *\return dictionnaire
*/
void DICTIONNAIRE_doubleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn int DICTIONNAIRE_hauteur(DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief Calcule la hauteur du dictionnaire.
 *
 *\param dictionnaire : le DICTIONNAIRE_Dictionnaire dont on souhaite calculer la hauteur
 *\return entier
*/
int DICTIONNAIRE_hauteur(DICTIONNAIRE_Dictionnaire dictionnaire);

int DICTIONNAIRE_obtenirhauteur(DICTIONNAIRE_Dictionnaire dictionnaire);

void DICTIONNAIRE_fixerhauteur(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn void DICTIONNAIRE_reequilibrer(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief Rééquilibre l'arbre dictionnaire.
 *\attention precondition : le dictionnaire ne doit pas être vide, et la différence de hauteur entre le fils gauche et le fils droit doit être égale à 2.
 *
 *\param *dictionnaire : le pointeur sur le DICTIONNAIRE_Dictionnaire dans lequel on insère
 *\return dictionnaire
*/
void DICTIONNAIRE_reequilibrer(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn int DICTIONNAIRE_estPresent(DICTIONNAIRE_Dictionnaire dictionnaire, MOT_Mot mot)
 *\brief Vérifie la présence d'un mot dans un dictionnaire.
 *
 *\param dictionnaire : DICTIONNAIRE_Dictionnaire
 *\param mot : MOT_Mot
 *\return booléen
*/
int DICTIONNAIRE_estPresent(DICTIONNAIRE_Dictionnaire dictionnaire, MOT_Mot mot);


/**
 *\fn void DICTIONNAIRE_afficherArbre(DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief Affiche l'arbre d'un dictionnaire.
 *
 *\param dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return arbre
*/
void DICTIONNAIRE_afficherArbre(DICTIONNAIRE_Dictionnaire dictionnaire);



#endif
