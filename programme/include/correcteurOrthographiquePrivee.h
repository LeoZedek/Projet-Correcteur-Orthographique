/**
	* \file correcteurOrthographiquePrivee.h
	* \brief Implantation du TAD CorrecteurOrthographique partie privée
	* \version 1.0
	* \date 03/01/2021
	*
*/

#ifndef __CORRECTEURORTHOGRAPHIQUEPRIVEE__
#define __CORRECTEURORTHOGRAPHIQUEPRIVEE__
#include "mot.h"
#include "dictionnaire.h"


/**
 *\fn CO_TableauDEntiers CO_tableauDEntiersVide();
 *\brief Fonction qui permet de construire un tableau vide. Sa longueur est fixée à 0 et le pointeur sera alloué avec la taille CO_TailleMax
 *
 *\return Un tableau d'entiers vide
 */

CO_TableauDEntiers CO_tableauDEntiersVide();


/**
 *\fn void CO_fixerLongueurTabEntiers(CO_TableauDEntiers *pointeurTableauEntiers, int nouvelleLongueur);
 *\brief Fonction qui permet de fixer la longueur d'un tableau d'entiers
 *
 *\param pointeurTableauEntiers : Est le pointeur du tableau dont la longueur sera modifé
 *\param nouvelleLongueur : La nouvelle longueur du tableau
 *
 */

void CO_fixerLongueurTabEntiers(CO_TableauDEntiers *pointeurTableauEntiers, int nouvelleLongueur);


/**
 *\fn int *CO_obtenirLesEntiers(CO_TableauDEntiers tableauEntiers);
 *\brief Permet d'obtenir le pointeur sur le premier entier du tableau
 *
 *\param tableauEntiers : Le tableau d'entier
 *\return Le pointeur sur le premier entier du tableau
 */

int *CO_obtenirLesEntiers(CO_TableauDEntiers tableauEntiers);

/**
 *\fn void MOT_ajouterEntier(CO_TableauDEntiers *tableauEntiers, int entierAAjouter);
 *\brief Ajoute un entier à la fin du tableau et augmente sa longueur de 1.
 *
 *\param tableauEntiers : Le pointeur sur le tableau d'entier.
 *\param m : L'entier qui sera ajouté à la fin du tableau
 */

void CO_ajouterEntier(CO_TableauDEntiers *tableauEntiers, int entierAAjouter);



/**
 * \fn CO_MotsDansPhrase CO_motsEtPositionsVide();
 * \brief Fonction qui créer une variable de type CO_MotsDansPhrase avec des tableaux vide.
 *
 * \return La structure avec des tableaux vides.
 */

CO_MotsDansPhrase CO_motsEtPositionsVide();



#endif
