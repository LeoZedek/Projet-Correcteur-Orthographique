/**
	* \file correcteurOrthographique.h
	* \brief Implantation du TAD CorrecteurOrthographique
	* \version 1.0
	* \date 03/01/2021
	*
*/

#ifndef __CORRECTEURORTHOGRAPHIQUE__
#define __CORRECTEURORTHOGRAPHIQUE__
#include "mot.h"
#include "dictionnaire.h"

/**
 * \brief Le type CO_TableauDEntiers permet de représenter un tableau d'entiers.
 *
 */
 
typedef struct {
    int *lesEntiers;
    int longueur;
} CO_TableauDEntiers;
/**
 * \brief Le type CO_TableauPositions permet de représenter un tableau d'entiers qui correspond à des positions.
 *
 */

typedef CO_TableauDEntiers CO_TableauPositions;

/**
 * \brief Le type CO_TableauBooleen permet de représenter un tableau d'entiers qui correspond à des booléens.
 *
 */


typedef CO_TableauDEntiers CO_TableauBooleens;

/**
 * \brief Le type structure CO_MotsDansPhrase permet de renvoyer un tableau de mots ainsi que leur position dans la phrase.
 *
 */

typedef struct {
	MOT_TableauDeMots mots;
	CO_TableauPositions positions;
} CO_MotsDansPhrase;



/**
 *\fn int CO_obtenirLongueurTabEntiers(CO_TableauDEntiers tableauEntiers);
 *\brief Fonction qui permet d'obtenir la longueur d'un tableau d'Entiers
 *
 *\param tableauEntiers : Est le tableau dont la longueur sera retourner
 *\return La longueur du tableau
 */

int CO_obtenirLongueurTabEntiers(CO_TableauDEntiers tableauEntiers);


/**
 *\fn int CO_obteniriIemeEntier(CO_TableauDEntiers tableauEntiers, int position);
 *\brief Procédure qui permet d'obtenir l'entier à une certaine position du tableau
 *
 *\param tableauEntiers : Est le tableau dont l'entier sera extrait
 *\param position : La position de l'entier extrait
 *\return L'entier extrait
 */

int CO_obtenirIemeEntier(CO_TableauDEntiers tableauEntiers, int position);

/**
 *\fn void CO_supprimerTableauEntiers(CO_TableauDEntiers tableau);
 *\brief Permet de désallouer le pointeur du tableau et fixe la longueur à -1. Le tableau n'est plus à vocation d'être utilisé.
 *
 *\param *tableau : Le pointeur sur tableau qui sera supprimer.
 */


void CO_supprimerTableauEntiers(CO_TableauDEntiers *tableau);

/**
 * \fn MOT_TableauDeMots CO_obtenirTabMots(CO_MotsDansPhrase motsEtPosition);
 * \brief Fonction getter pour avoir le tableau de Mots.
 * \param motsEtPosition : La structure dont on prends le tableau de mots.
 */

MOT_TableauDeMots CO_obtenirTabMots(CO_MotsDansPhrase motsEtPosition);

/**
 * \fn CO_TableauPositions CO_obtenirTabPositions(CO_MotsDansPhrase motsEtPosition);
 * \brief Fonction getter pour avoir le tableau de Positions.
 * \param motsEtPosition : La structure dont on prends le tableau de positions.
 */

CO_TableauPositions CO_obtenirTabPositions(CO_MotsDansPhrase motsEtPosition);


/**
 * \fn CO_TableauBooleens sontPresents(Mot mots[], Dictionnaire dictionnaire)
 * \brief Procédure de vérification pour voir si une liste de mots est présente dans le dictionnaire ou non.
 *
 * \param tableauBooleens : un pointeur sur un entier
 * \param mots : un pointeur sur un mot
 * \param dictionnaire : le dictionnaire
 * \return CO_TableauBooleens, c'est-à-dire les booléens précisant si les mots sont présents ou non dans le dictionnaire.
 */
 
/**
 * \fn void CO_supprimerMotsEtPositions(CO_MotsDansPhrase *motsEtPosition);
 * \brief Fonction qui supprime et désalloue la structure CO_MotsDansPhrase.
 * \param *motsEtPosition : Le pointeur sur la structure à désallouer.
 */

void CO_supprimerMotsEtPositions(CO_MotsDansPhrase *motsEtPosition);


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

CO_MotsDansPhrase CO_phraseEnMots(char *phrase);

#endif
