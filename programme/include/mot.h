/**
 * \file mot.h
 * \brief Implantation du TAD Mot
 * \version 1.0
 * \date 11/12/2021
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
} MOT_Mot;


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
 *\fn void MOT_fixerLongeurTabMots(MOT_TableauDeMots *tableauMots, int nouvelleLongeur)
 *\brief Fonction qui permet de fixer la longeur d'un tableau de mots
 *
 *\param pointeurTableauMots : Est le poiteur du tableau dont la longeur sera modifé
 *\param nouvelleLongeur : La nouvelle longeur du tableau
 *
 */

void MOT_fixerLongueurTabMots(MOT_TableauDeMots *pointeurTableauMots, int nouvelleLongeur);

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
 *\fn MOT_Mot *MOT_obtenirLesMots(MOT_TableauDeMots tableauMots);
 *\brief Permet d'obtenir le pointeur sur le premier mot du tableau
 *
 *\param tableauMots : Le tableau de mot
 *\return Le pointeur sur le premier mot du tableau
 */

MOT_Mot *MOT_obtenirLesMots(MOT_TableauDeMots tableauMots);

/**
 *\fn void MOT_ajouterMot(MOT_TableauDeMots *tableauMots);
 *\brief Ajoute un mot à la fin du tableau et augmente sa longeur de 1.
 *
 *\param tableauMots : Le pointeur sur le tableau de mot.
 *\param m : Le mot qui sera ajouté à la fin du tableau
 */

void MOT_ajouterMot(MOT_TableauDeMots *tableauMots, MOT_Mot m);

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
 *\fn unsigned int MOT_longeurMot(MOT_Mot mot)
 *\brief Renvoie la longueur d'un mot
 *
 *\param mot : est le mot de type Mot
 *\return La longueur du mot
 */

unsigned int MOT_longueurMot(MOT_Mot mot);

/**
 *\fn int MOT_estUnMot(char *chaine)
 *\brief Renvoie si une chaine de caractère est composé seulement de caractère de l'alphabet
 *
 *\param chaine : est la chaine qui subit le test
 *\return Le booleen qui teste si la chaine est composé de lettre de l'alphabet
*/

int MOT_estUnMot(char *chaine);

/**
 *\fn int MOT_fixerLongeurMot(MOT_Mot *m, unsigned int longeur)
 *\brief fixe la longeur d'un mot
 *
 *\param m : le poiteur du mot
 *\param longeur : la nouvelle longeur du mot
*/

void MOT_fixerLongueurMot(MOT_Mot *m, unsigned int longeur);

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
 *\fn int sontEgaux(Mot m1, Mot m2)
 *\brief Renvoie le test si deux mot sont identique (insensible à la casse)
 *
 *\param m1 : un des deux mots qui vont être comparer ensemble
 *\param m2 : l'autre des deux mots qui vont être comparer ensemble
 *\return Le resultat du test de similarité des 2 mots
*/
int MOT_sontEgaux(MOT_Mot m1, MOT_Mot m2);


/**
 *\fn char *MOT_motEnChaine(MOT_Mot m)
 *\brief Transforme une variable de type Mot en une chaine de caractère.
 *
 *\param m : Le Mot qui sera transformé en chaine
 *\return La chaine de caractère correspondant au mot.
*/
char *MOT_motEnChaine(MOT_Mot m);


/**
 *\fn MOT_Mot MOT_remplacerLettre(MOT_Mot m, int pos, char c);
 *\brief Renvoie une variable de type MOT_Mot avec une seule lettre remplacer
 *\attention precondition : pos < longueur(m) et estUneLettre(c) et pos > 0
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique quelle lettre sera modifié
 *\param c : La lettre qui remplacera celle à la position pos
 *\return Une copie du mot qui sera modifié
*/
MOT_Mot MOT_remplacerLettre(MOT_Mot m, int pos, char c);


/**
 *\fn MOT_Mot MOT_supprimerLettre(MOT_Mot m, int pos);
 *\brief renvoie une variable de type MOT_Mot avec une seule lettre supprimer
 *\attention precondition : pos < longueur(m) et pos > 0
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique quelle lettre sera supprimer
 *\return Une copie du mot qui sera modifié
*/
MOT_Mot MOT_supprimerLettre(MOT_Mot m, int pos);


/**
 *\fn MOT_Mot MOT_insererLettre(MOT_Mot m, int pos, char c);
 *\brief renvoie une variable de type MOT_Mot avec une seule lettre inserer
 *\attention precondition : pos < longueur(m) et pos > 0 + 1 et estUneLettre(c)
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique à quelle indice la lettre sera inserer
 *\return Une copie du MOT_Mot qui sera modifié
*/
MOT_Mot MOT_insererLettre(MOT_Mot m, int pos, char c);


/**
 *\fn MOT_Mot inverserLettre(MOT_Mot m, int pos);
 *\brief Renvoie une variable de type MOT_Mot avec une deux lettres consécutive inverser.
 *\attention Precondition : pos < longueur(m) - 1 et pos > 0
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique à quelle indice la lettre sera inverser avec la lettre qui la succède.
 *\return Une copie du MOT_Mot qui sera modifié
*/
MOT_Mot MOT_inverserLettre(MOT_Mot m, int pos);


/**
 *\fn MOT_DeuxMots MOT_decomposerMot(MOT_Mot m, int pos);
 *\brief Renvoie deux mots issus de la décomposition d'un seul mot.
 *\attention Precondition : pos < longueur(m) - 1 et pos > 0
 *
 *\param m : Le mot qui seras decomposer en deux mots
 *\param pos : La position qui indique à quelle indice la décomposition sera fais.
 *\return Une valeur de type MOT_DeuxMots qui contient les deux mots décomposer. Le premier mot est composé des lettre de l'indice 0 à l'indice pos et le seconde des lettres de l'indice pos + 1 à l'indice longueur(m) - 1
*/
MOT_DeuxMots MOT_decomposerMot(MOT_Mot m, int pos);

#endif
