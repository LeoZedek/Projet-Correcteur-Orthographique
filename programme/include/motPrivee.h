/**
 * \file motPrivee.h
 * \brief Fichier .h des fonctions privée du TAD Mot
 * \version 1.0
 * \date 24/12/2021
 *
 */

#ifndef __MOT_PRIVEE__
#define __MOT_PRIVEE__

/**
 *\fn void MOT_fixerLongeurTabMots(MOT_TableauDeMots *tableauMots, int nouvelleLongeur)
 *\brief Fonction qui permet de fixer la longeur d'un tableau de mots
 *
 *\param pointeurTableauMots : Est le poiteur du tableau dont la longeur sera modifé
 *\param nouvelleLongeur : La nouvelle longeur du tableau
 *
 */

void MOT_fixerLongueurTabMots(MOT_TableauDeMots *pointeurTableauMots, int nouvelleLongeur);

/**
 *\fn MOT_Mot *MOT_obtenirLesMots(MOT_TableauDeMots tableauMots);
 *\brief Permet d'obtenir le pointeur sur le premier mot du tableau
 *
 *\param tableauMots : Le tableau de mot
 *\return Le pointeur sur le premier mot du tableau
 */

MOT_Mot *MOT_obtenirLesMots(MOT_TableauDeMots tableauMots);

/**
 *\fn MOT_Mot MOT_copierMot(MOT_Mot mot);
 *\brief Copie un mot.
 *
 *\param mot : Le mot qui sera copié.
 *\return Le mot copié, il est égale à celui mis en paramètre mais pas identique.
 */

MOT_Mot MOT_copierMot(MOT_Mot mot);

/**
 *\fn void MOT_fixerIemeMot(MOT_TableauDeMots *tableau, MOT_Mot mot, int i);
 *\brief Fixe un mot à une position donné.
 *\attention Précondition : i < MOT_obtenirLongueurTabMot(*tableau)
 *
 *\param *tableau : Le pointeur sur le tableau de mot qui sera modifié.
 *\param mot : Le mot qui sera fixer à la position i du tableau
 *\param i : La position du Mot dans le tableau.
 */

void MOT_fixerIemeMot(MOT_TableauDeMots *tableau, MOT_Mot mot, int i);

/**
 *\fn unsigned int MOT_longeurMot(MOT_Mot mot)
 *\brief Renvoie la longueur d'un mot
 *
 *\param mot : est le mot de type Mot
 *\return La longueur du mot
 */

unsigned int MOT_longueurMot(MOT_Mot mot);

/**
 *\fn int MOT_fixerLongeurMot(MOT_Mot *mot, int longeur)
 *\brief fixe la longeur d'un mot
 *
 *\param *mot : le poiteur du mot
 *\param longeur : la nouvelle longeur du mot
*/

void MOT_fixerLongueurMot(MOT_Mot *mot, int longeur);

/**
 *\fn char *MOT_motEnChaine(MOT_Mot mot)
 *\brief Transforme une variable de type Mot en une chaine de caractère.
 *
 *\param mot : Le Mot qui sera transformé en chaine
 *\return La chaine de caractère correspondant au mot.
*/

char *MOT_motEnChaine(MOT_Mot mot);



#endif