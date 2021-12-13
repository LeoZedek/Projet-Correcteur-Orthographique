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
 *\fn int estUneLettre(char c)
 *\brief fonction booléenne qui teste si un charactère est une lettre
 *
 *\param charactere : caractère qui subit le test
 *\return Le boléen qui teste si caractère est une lettre de l'alphabet
 */

int estUneLettre(char charactere);

/**
 *\fn unsigned int longeur(m Mot)
 *\brief renvoie la longueur d'un mot
 *
 *\param m : est le mot de type Mot
 *\return la longueur du mot
 */

unsigned int longueur(m : Mot);

/**
 *\fn int estUnMot(char *chaine)
 *\brief renvoie si une chaine de caractère est composé seulement de caractère de l'alphabet
 *
 *\param chaine : est la chaine qui subit le test
 *\return le booleen qui teste si la chaine est composé de lettre de l'alphabet
*/

int estUnMot(char *chaine);

/**
 *\fn Mot creerMot(char *chaine)
 *\brief renvoie une variable de type Mot creer à partir d'une chaine de caractère
 *\attention précondition : estUnMot(chaine)
 *
 *\param chaine : la chaine utiliser pour construire la variable de type Mot
 *\return la variable de type Mot construit à partir du paramètre d'entrée
*/

Mot creerMot(char *chaine);


/**
 *\fn int sontEgaux(Mot m1, Mot m2)
 *\brief renvoie le test si deux mot sont identique (insensible à la casse)
 *
 *\param m1 : un des deux mots qui vont être comparer ensemble
 *\param m2 : l'autre des deux mots qui vont être comparer ensemble
 *\return le resultat du test de similarité des 2 mots
*/

int sontEgaux(Mot m1, Mot m2);

/**
 *\fn Mot remplacerLettre(m : Mot, pos : int, c : char);
 *\brief renvoie une variable de type Mot avec une seule lettre remplacer
 *\attention precondition : pos < longueur(m) et estUneLettre(c)
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique quelle lettre sera modifié
 *\param c : La lettre qui remplacera celle à la position pos
 *\return Une copie du Mot qui sera modifié
*/

Mot remplacerLettre(m : Mot, pos : int, c : char);

/**
 *\fn Mot supprimerLettre(m : Mot, pos : int);
 *\brief renvoie une variable de type Mot avec une seule lettre supprimer
 *\attention precondition : pos < longueur(m)
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique quelle lettre sera supprimer
 *\return Une copie du Mot qui sera modifié
*/

Mot supprimerLettre(m : Mot, pos : int);

/**
 *\fn Mot insererLettre(m : Mot, pos : int, c : char);
 *\brief renvoie une variable de type Mot avec une seule lettre inserer
 *\attention precondition : pos < longueur(m) + 1 et estUneLettre(c)
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique à quelle indice la lettre sera inserer
 *\return Une copie du Mot qui sera modifié
*/

Mot insererLettre(m : Mot, pos : int, c : char);

/**
 *\fn Mot insererLettre(m : Mot, pos : int, c : char);
 *\brief renvoie une variable de type Mot avec une seule lettre inserer
 *\attention precondition : pos < longueur(m) + 1 et estUneLettre(c)
 *
 *\param m : Le mot qui seras modifié
 *\param pos : La position qui indique à quelle indice la lettre sera inserer
 *\return Une copie du Mot qui sera modifié
*/

#endif
