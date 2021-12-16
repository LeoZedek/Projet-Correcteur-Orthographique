/**
	* \file correcteurOrthographique.h
	* \brief Implantation du TAD CorrecteurOrthographique
	* \version 1.0
	* \date 03/01/2021
	*
*/


#ifndef __CORRECTEURORTHOGRAPHIQUE__
#define __CORRECTEURORTHOGRAPHIQUE__

/**
 * \brief Le type énumération CORRECTEURORTHOGRAPHIQUE_ALPHABET permet de représenter l'ensemble des caractères de l'alphabet ainsi que le tiret.
 *
 */

enum CORRECTEURORTHOGRAPHIQUE_ALPHABET = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'é', 'è', 'ê', 'ë', 'à', 'â', 'ä', 'ù', 'ü', 'û', 'ô', 'ö', 'ï', 'î', 'ÿ', 'ç', '-'};

/**
 * \fn void sontPresents(int tableauBooleens[], Mot mots[], Dictionnaire d)
 * \brief Fonction de vérification pour voir si une liste de mots est présente dans le dictionnaire ou non.
 *
 * \param tableauBooleens : un pointeur sur un entier
 * \param mots : un pointeur sur un mot
 * \param d : le dictionnaire
 */

void sontPresents(int tableauBooleens[], Mot mots[], Dictionnaire d); 


/**
 * \fn void proposerMots(Mot mots[], Mot m, Dictionnaire d);
 * \brief Fonction proposant une liste de mots corrects pouvant être la correction du mot donné en entrée.
 *
 * \param mots : un pointeur sur un mot
 * \param m : le mot
 * \param d : le dictionnaire
 */

void proposerMots(Mot mots[], Mot m, Dictionnaire d);



#endif
