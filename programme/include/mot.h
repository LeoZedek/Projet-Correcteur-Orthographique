/**
 * \file mot.h
 * \brief Fichier .h des fonctions et structures poubliques du TAD Mot
 * \version 1.0
 * \date 24/12/2021
 *
 */
 
#ifndef __MOT__
#define __MOT__

/**
 * \brief Le type Mot qui represente un mot
 *
 */

typedef struct {
	char *chaine; /**< la chaine de charactère du mot */
	unsigned int longueur; /**< la longueur du mot */
} MOT_Mot ;


/**
 * \brief Le type DeuxMot qui contient 2 mots. Utiliser pour le renvoie de 2 mots de la fonction decomposerMot.
 *
 */
typedef struct {
	MOT_Mot mot1;
	MOT_Mot mot2;
} MOT_DeuxMots;

/**
 * \brief Le Type MOT_TableauDeMots est un pointeur sur un Mot. Cela représente un tableau de mot.
 *
 */

typedef struct {
    MOT_Mot *lesMots;
    int longueur;
} MOT_TableauDeMots;

/**
 *\fn MOT_TableauDeMots MOT_tableauDeMotsVide()
 *\brief Fonction qui permet d'obtenir un tableau de mot vide. Sa longeur est fixé à 0 et le pointeur sera allouer sur CO_TailleMax
 *
 *\return Le tableau vide.
 */

MOT_TableauDeMots MOT_tableauDeMotsVide();

/**
 *\fn int MOT_obtenirLongeurTabMots(MOT_TableauDeMots tableauMots)
 *\brief Fonction qui permet d'obtenir la longeur d'un tableau de mot
 *
 *\param tableauMots : Est le tableau dont la longeur sera retourner
 *\return La longeur du tableau
 */

int MOT_obtenirLongueurTabMots(MOT_TableauDeMots tableauMots);

/**
 *\fn MOT_Mot MOT_obteniriIemeMot(MOT_TableauDeMots tableauMots, int position);
 *\brief Fonction qui permet d'obtenir le mot à une certaine position du tableau
 *
 *\param tableauMots : Est le tableau dont le mot sera extrait
 *\param position : La position du mot extrait
 *\return Le mot extrait
 */

MOT_Mot MOT_obtenirIemeMot(MOT_TableauDeMots tableauMots, int position);


/**
 *\fn void MOT_ajouterMot(MOT_TableauDeMots *tableauMots);
 *\brief Ajoute un mot à la fin du tableau et augmente sa longeur de 1.
 *
 *\param tableauMots : Le pointeur sur le tableau de mot.
 *\param mot : Le mot qui sera ajouté à la fin du tableau
 */

void MOT_ajouterMot(MOT_TableauDeMots *tableauMots, MOT_Mot mot);

/**
 *\fn void MOT_supprimerTableauMots(MOT_TableauDeMots tableau)
 *\brief Permet de désallouer le pointeur du tableau et fixe la longeur à -1. Le tableau n'est plus à vocation d'être utilisé.
 *
 *\param tableau : le tableau qui sera supprimer.
 */


void MOT_supprimerTableauMots(MOT_TableauDeMots *tableau);

/**
 *\fn int MOT_estUneLettre(char charactere)
 *\brief Fonction booléenne qui teste si un charactère est une lettre
 *
 *\param charactere : caractère qui subit le test
 *\return Le boléen qui teste si caractère est une lettre de l'alphabet
 */

int MOT_estUneLettre(char charactere);


/**
 *\fn int MOT_estUnMot(char *chaine)
 *\brief Renvoie si une chaine de caractère est composé seulement de caractère de l'alphabet
 *
 *\param chaine : est la chaine qui subit le test
 *\return Le booleen qui teste si la chaine est composé de lettre de l'alphabet
*/

int MOT_estUnMot(char *chaine);

/**
 *\fn MOT_Mot MOT_creerMot(char *chaine)
 *\brief Renvoie une variable de type Mot creer à partir d'une chaine de caractère
 *\attention précondition : estUnMot(chaine)
 *
 *\param chaine : la chaine utiliser pour construire la variable de type Mot
 *\return La variable de type Mot construit à partir du paramètre d'entrée
*/

MOT_Mot MOT_creerMot(char *chaine);

/**
 *\fn void MOT_supprimerMot(MOT_Mot *mot);
 *\brief Déalloue un mot, plus en particulier, son attribut chaine.
 *
 *\param *mot : Le pointeur sur le mot qui sera déallouer.
*/

void MOT_supprimerMot(MOT_Mot *mot);

/**
 *\fn void MOT_supprimerDeuxMots(MOT_DeuxMots *deuxMots);
 *\brief Déalloue une variable de type MOT_DeuxMots, plus en particulier, c'est 2 attribut Mot.
 *
 *\param *deuxMots : Le pointeur sur la variable à déallouer
 */

void MOT_supprimerDeuxMots(MOT_DeuxMots *deuxMots);

/**
 *\fn int estAvantOrdreAlphabetique(MOT_Mot mot1, MOT_Mot mot2);
 *\brief Renvoie 1 si le mot1 est plus petit par rapport à l'ordre alphabètique 0 sinon.
 *
 *\param mot1 : un des deux mots qui vont être comparer ensemble
 *\param mot2 : l'autre des deux mots qui vont être comparer ensemble
 *\return Le booléen de la comparaison.
*/

int estAvantOrdreAlphabetique(MOT_Mot mot1, MOT_Mot mot2);

/**
 *\fn int sontEgaux(Mot mot1, Mot mot2)
 *\brief Renvoie le test si deux mot sont identique (insensible à la casse)
 *
 *\param mot1 : un des deux mots qui vont être comparer ensemble
 *\param mot2 : l'autre des deux mots qui vont être comparer ensemble
 *\return Le resultat du test de similarité des 2 mots
*/

int MOT_sontEgaux(MOT_Mot mot1, MOT_Mot mot2);

/**
 *\fn MOT_Mot MOT_remplacerLettre(MOT_Mot mot, int position, char lettre);
 *\brief Renvoie une variable de type MOT_Mot avec une seule lettre remplacer
 *\attention precondition : position < longueur(mot) et estUneLettre(lettre) et position > 0
 *
 *\param mot : Le mot qui seras modifié
 *\param position : La position qui indique quelle lettre sera modifié
 *\param lettre : La lettre qui remplacera celle à la position pos
 *\return Une copie du mot qui sera modifié
*/

MOT_Mot MOT_remplacerLettre(MOT_Mot mot, int position, char lettre);


/**
 *\fn MOT_Mot MOT_supprimerLettre(MOT_Mot mot, int position);
 *\brief renvoie une variable de type MOT_Mot avec une seule lettre supprimer
 *\attention precondition : position < longueur(mot) et position > 0
 *
 *\param mot : Le mot qui seras modifié
 *\param position : La position qui indique quelle lettre sera supprimer
 *\return Une copie du mot qui sera modifié
*/
MOT_Mot MOT_supprimerLettre(MOT_Mot mot, int position);


/**
 *\fn MOT_Mot MOT_insererLettre(MOT_Mot mot, int position, char lettre);
 *\brief renvoie une variable de type MOT_Mot avec une seule lettre inserer
 *\attention precondition : position < longueur(mot) et position > 0 + 1 et estUneLettre(lettre)
 *
 *\param mot : Le mot qui seras modifié
 *\param position : La position qui indique à quelle indice la lettre sera inserer
 *\param lettre : La lettre qui sera insérer
 *\return Une copie du MOT_Mot qui sera modifié
*/
MOT_Mot MOT_insererLettre(MOT_Mot mot, int position, char lettre);


/**
 *\fn MOT_Mot inverserLettre(MOT_Mot mot, int position);
 *\brief Renvoie une variable de type MOT_Mot avec une deux lettres consécutive inverser.
 *\attention Precondition : position < longueur(mot) - 1 et position > 0
 *
 *\param mot : Le mot qui seras modifié
 *\param position : La position qui indique à quelle indice la lettre sera inverser avec la lettre qui la succède.
 *\return Une copie du MOT_Mot qui sera modifié
*/
MOT_Mot MOT_inverserLettre(MOT_Mot mot, int position);


/**
 *\fn MOT_DeuxMots MOT_decomposerMot(MOT_Mot mot, int position);
 *\brief Renvoie deux mots issus de la décomposition d'un seul mot.
 *\attention Precondition : position < longueur(mot) - 1 et position > 0
 *
 *\param mot : Le mot qui seras decomposer en deux mots
 *\param position : La position qui indique à quelle indice la décomposition sera fais.
 *\return Une valeur de type MOT_DeuxMots qui contient les deux mots décomposer. Le premier mot est composé des lettre de l'indice 0 à l'indice position et le seconde des lettres de l'indice position + 1 à l'indice longueur(mot) - 1
*/
MOT_DeuxMots MOT_decomposerMot(MOT_Mot mot, int position);

#endif
