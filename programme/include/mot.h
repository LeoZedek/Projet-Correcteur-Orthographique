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
} Mot;

/**
 * \brief Le type DeuxMot qui contient 2 mots. Utiliser pour le renvoie de 2 mots de la fonction decomposerMot.
 *
 */

typedef struct {
	Mot mot1;
	Mot mot2;
} DeuxMots;

/**
 *\fn int estUneLettre(char c)
 *\brief Fonction booléenne qui teste si un charactère est une lettre
 *
 *\param charactere : caractère qui subit le test
 *\return Le boléen qui teste si caractère est une lettre de l'alphabet
 */

int estUneLettre(char charactere);

/**
 *\fn unsigned int longeur(m Mot)
 *\brief Renvoie la longueur d'un mot
 *
 *\param m : est le mot de type Mot
 *\return La longueur du mot
 */

unsigned int longueur(Mot m);

/**
 *\fn int estUnMot(char *chaine)
 *\brief Renvoie si une chaine de caractère est composé seulement de caractère de l'alphabet
 *
 *\param chaine : est la chaine qui subit le test
 *\return Le booleen qui teste si la chaine est composé de lettre de l'alphabet
*/

int estUnMot(char *chaine);

/**
 *\fn Mot creerMot(char *chaine)
 *\brief Renvoie une variable de type Mot creer à partir d'une chaine de caractère
 *\attention précondition : estUnMot(chaine)
 *
 *\param chaine : la chaine utiliser pour construire la variable de type Mot
 *\return La variable de type Mot construit à partir du paramètre d'entrée
*/

Mot creerMot(char *chaine);


/**
 *\fn int sontEgaux(Mot m1, Mot m2)
 *\brief Renvoie le test si deux mot sont identique (insensible à la casse)
 *
 *\param m1 : un des deux mots qui vont être comparer ensemble
 *\param m2 : l'autre des deux mots qui vont être comparer ensemble
 *\return Le resultat du test de similarité des 2 mots
*/

int sontEgaux(Mot m1, Mot m2);

/**
 *\fn char *motEnChaine(Mot m)
 *\brief Transforme une variable de type Mot en une chaine de caractère.
 *
 *\param m : Le Mot qui sera transformé en chaine
 *\return La chaine de caractère correspondant au mot.
*/

char *motEnChaine(Mot m);

/**
 *\fn Mot remplacerLettre(Mot m, int pos, char c);
 *\brief Renvoie une variable de type Mot avec une seule lettre remplacer
 *\attention precondition : pos < longueur(m) et estUneLettre(c) et pos > 0
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique quelle lettre sera modifié
 *\param c : La lettre qui remplacera celle à la position pos
 *\return Une copie du Mot qui sera modifié
*/

Mot remplacerLettre(Mot m, int pos, char c);

/**
 *\fn Mot supprimerLettre(Mot m, int pos);
 *\brief renvoie une variable de type Mot avec une seule lettre supprimer
 *\attention precondition : pos < longueur(m) et pos > 0
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique quelle lettre sera supprimer
 *\return Une copie du Mot qui sera modifié
*/

Mot supprimerLettre(Mot m, int pos);

/**
 *\fn Mot insererLettre(Mot m, int pos, char c);
 *\brief renvoie une variable de type Mot avec une seule lettre inserer
 *\attention precondition : pos < longueur(m) et pos > 0 + 1 et estUneLettre(c)
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique à quelle indice la lettre sera inserer
 *\return Une copie du Mot qui sera modifié
*/

Mot insererLettre(Mot m, int pos, char c);

/**
 *\fn Mot inverserLettre(Mot m, int pos);
 *\brief Renvoie une variable de type Mot avec une deux lettres consécutive inverser.
 *\attention Precondition : pos < longueur(m) - 1 et pos > 0
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique à quelle indice la lettre sera inverser avec la lettre qui la succède.
 *\return Une copie du Mot qui sera modifié
*/

Mot inverserLettre(Mot m, int pos);

/**
 *\fn DeuxMots decomposerMot(Mot m, int pos);
 *\brief Renvoie deux mots issus de la décomposition d'un seul mot.
 *\attention Precondition : pos < longueur(m) - 1 et pos > 0
 *
 *\param m : Le mot qui seras decomposer en deux mots
 *\param pos : La position qui indique à quelle indice la décomposition sera fais.
 *\return Une valeur de type DeuxMots qui contient les deux mots décomposer. Le premier mot est composé des lettre de l'indice 0 à l'indice pos et le seconde des lettres de l'indice pos + 1 à l'indice longueur(m) - 1
*/

DeuxMots decomposerMot(Mot m, int pos);

#endif
