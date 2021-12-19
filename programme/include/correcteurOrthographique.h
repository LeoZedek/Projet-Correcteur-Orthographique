/**
	* \file correcteurOrthographique.h
	* \brief Implantation du TAD CorrecteurOrthographique
	* \version 1.0
	* \date 03/01/2021
	*
*/

#include "mot.h"
#include "dictionnaire.h"
#ifndef __CORRECTEURORTHOGRAPHIQUE__
#define __CORRECTEURORTHOGRAPHIQUE__

/**
 * \brief La constante CO_TailleMax définie la taille maximale des tableaux utilisés.
 *
 */
 
const int CO_TailleMax = 1000;


/**
 * \brief Le type CO_TableauBooleens permet de représenter un tableau de booléens.
 *
 */
 
typedef int* CO_TableauBooleens;

/**
 * \brief Le type CO_TableauPositions permet de représenter un tableau d'entiers qui correspond à des positions.
 *
 */


typedef int* CO_TableauPositions;

/**
 * \brief Le type structure CO_MotsDansPhrase permet de renvoyer un tableau de mots ainsi que leur position dans la phrase.
 *
 */
 
typedef struct {
	MOT_TableauDeMots mots;
	CO_TableauPositions positions;
} CO_MotsDansPhrase;

/**
 * \fn CO_TableauBooleens sontPresents(Mot mots[], Dictionnaire dictionnaire)
 * \brief Fonction de vérification pour voir si une liste de mots est présente dans le dictionnaire ou non.
 *
 * \param tableauBooleens : un pointeur sur un entier
 * \param mots : un pointeur sur un mot
 * \param dictionnaire : le dictionnaire
 * \return CO_TableauBooleens, c'est-à-dire les booléens précisant si les mots sont présents ou non dans le dictionnaire.
 */

CO_TableauBooleens CO_sontPresents(MOT_TableauDeMots mots, DICTIONNAIRE_Dictionnaire dictionnaire); 

/**
 * \fn MOT_TableauDeMots proposerMots(Mot m, Dictionnaire dictionnaire)
 * \brief Fonction proposant une liste de mots corrects pouvant être la correction du mot donné en entrée.
 *
 * \param m : le mot
 * \param dictionnaire : le dictionnaire
 * \return MOT_TableauDeMots, c'est-à-dire les mots pouvant être une correction de celui pris en entrée.
 */

MOT_TableauDeMots CO_proposerMots(MOT_Mot m, DICTIONNAIRE_Dictionnaire dictionnaire);


/**
 * \fn CO_MotsDansPhrase CO_phraseEnMots(char phrase[])
 * \brief Fonction qui, à partir d'une phrase, nous renvoie une liste de mots accompagnés de leur position dans la phrase.
 * \param phrase[] : la phrase que l'on souhaite décomposée en plusieurs mots.
 * \return CO_MotsDansPhrase, c'est-à-dire les mots d'une phrase mais de façon séparée avec de leur position dans la phrase.
 */

CO_MotsDansPhrase CO_phraseEnMots(char phrase[]);

#endif
