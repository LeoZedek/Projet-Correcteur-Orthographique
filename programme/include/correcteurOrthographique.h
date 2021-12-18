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
 * \brief Le type énumération CORRECTEURORTHOGRAPHIQUE_ALPHABET permet de représenter l'ensemble des caractères de l'alphabet ainsi que le tiret.
 *
 */

enum CO_ALPHABET = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'é', 'è', 'ê', 'ë', 'à', 'â', 'ä', 'ù', 'ü', 'û', 'ô', 'ö', 'ï', 'î', 'ÿ', 'ç', '-'};


/**
 * \brief La constante CORRECTEURORTHOGRAPHIQUE_TailleMax définie la taille maximale du tableau de booléens.
 *
 */
 
const CO_TailleMax = 1000;


/**
 * \brief Le type CORRECTEURORTHOGRAPHIQUE_TableauBooleens permet de représenter un tableau de booléens.
 *
 */
 
typedef int CO_TableauBooleens[CO_TailleMax];


/**
 * \fn void sontPresents(int tableauBooleens[], Mot mots[], Dictionnaire d)
 * \brief Fonction de vérification pour voir si une liste de mots est présente dans le dictionnaire ou non.
 *
 * \param tableauBooleens : un pointeur sur un entier
 * \param mots : un pointeur sur un mot
 * \param d : le dictionnaire
 */

CO_TableauBooleens CO_sontPresents(MOT_TableauDeMots mots[], DICTIONNAIRE_Dictionnaire dictionnaire); 



/**
 * \fn void proposerMots(Mot mots[], Mot m, Dictionnaire d);
 * \brief Fonction proposant une liste de mots corrects pouvant être la correction du mot donné en entrée.
 *
 * \param mots : un pointeur sur un mot
 * \param m : le mot
 * \param d : le dictionnaire
 */

MOT_TableauDeMots CO_proposerMots(MOT_Mot m, DICTIONNAIRE_Dictionnaire dictionnaire);



#endif
