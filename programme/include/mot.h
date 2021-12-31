/**
 * \file mot.h
 * \brief Fichier .h des fonctions et structures publiques du TAD Mot
 * \version 1.0
 * \date 24/12/2021
 *
 */
 
#ifndef __MOT__
#define __MOT__

/**
 * \brief Le type Mot qui représente un mot
 *
 */

typedef struct {
	char *chaine; /**< la chaîne de caractères du mot */
	unsigned int longueur; /**< la longueur du mot */
} MOT_Mot ;


/**
 * \brief Le type DeuxMot qui contient 2 mots. Utilisé pour le renvoie de 2 mots de la fonction decomposerMot.
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
 *\brief Fonction qui permet d'obtenir un tableau de mots vide. Sa longueur est fixée à 0 et le pointeur sera alloué sur CO_TailleMax.
 *
 *\return Le tableau vide.
 */

MOT_TableauDeMots MOT_tableauDeMotsVide();

/**
 *\fn int MOT_obtenirLongueurTabMots(MOT_TableauDeMots tableauMots)
 *\brief Fonction qui permet d'obtenir la longueur d'un tableau de mots.
 *
 *\param tableauMots : Est le tableau dont la longueur sera retournée
 *\return La longueur du tableau
 */

int MOT_obtenirLongueurTabMots(MOT_TableauDeMots tableauMots);

/**
 *\fn void MOT_fixerLongueurTabMots(MOT_TableauDeMots *tableauMots, int nouvelleLongueur)
 *\brief Fonction qui permet de fixer la longueur d'un tableau de mots.
 *
 *\param pointeurTableauMots : Est le pointeur du tableau dont la longueur sera modifée
 *\param nouvelleLongueur : La nouvelle longueur du tableau
 *
 */

void MOT_fixerLongueurTabMots(MOT_TableauDeMots *pointeurTableauMots, int nouvelleLongeur);

/**
 *\fn MOT_Mot MOT_obtenirIemeMot(MOT_TableauDeMots tableauMots, int position)
 *\brief Fonction qui permet d'obtenir le mot à une certaine position du tableau.
 *
 *\param tableauMots : Tableau dont le mot sera extrait
 *\param position : Position du mot extrait
 *\return Le mot extrait
 */

MOT_Mot MOT_obtenirIemeMot(MOT_TableauDeMots tableauMots, int position);


/**
 *\fn void MOT_ajouterMot(MOT_TableauDeMots *tableauMots);
 *\brief Ajoute un mot à la fin du tableau et augmente sa longueur de 1.
 *
 *\param tableauMots : Le pointeur sur le tableau de mot.
 *\param mot : Le mot qui sera ajouté à la fin du tableau.
 */

void MOT_ajouterMot(MOT_TableauDeMots *tableauMots, MOT_Mot mot);

/**
 *\fn void MOT_supprimerTableauMots(MOT_TableauDeMots tableau)
 *\brief Permet de désallouer le pointeur du tableau et fixe la longueur à -1. Le tableau n'est plus à vocation d'être utilisé.
 *
 *\param tableau : Le tableau qui sera supprimé.
 */


void MOT_supprimerTableauMots(MOT_TableauDeMots *tableau);

/**
 *\fn int MOT_estUneLettre(char charactere)
 *\brief Fonction booléenne qui teste si un caractère est une lettre.
 *
 *\param charactere : caractère qui subit le test
 *\return Le booléen qui teste si le caractère est une lettre de l'alphabet
 */

int MOT_estUneLettre(char charactere);


/**
 *\fn int MOT_estUnMot(char *chaine)
 *\brief Renvoie VRAI si la chaîne de caractère est composée seulement de caractères de l'alphabet.
 *
 *\param chaine : La chaîne qui subit le test
 *\return Le booléen qui teste si la chaîne est composée de lettres de l'alphabet
*/

int MOT_estUnMot(char *chaine);

/**
 *\fn MOT_Mot MOT_creerMot(char *chaine)
 *\brief Renvoie une variable de type Mot créée à partir d'une chaîne de caractères.
 *\attention précondition : estUnMot(chaine)
 *
 *\param chaine : la chaîne utilisée pour construire la variable de type Mot
 *\return La variable de type Mot construite à partir du paramètre d'entrée
*/

MOT_Mot MOT_creerMot(char *chaine);

/**
 *\fn void MOT_supprimerMot(MOT_Mot *mot);
 *\brief Désalloue un mot, plus en particulier, son attribut chaîne.
 *
 *\param *mot : Le pointeur sur le mot qui sera désalloué.
*/

void MOT_supprimerMot(MOT_Mot *mot);

/**
 *\fn void MOT_supprimerDeuxMots(MOT_DeuxMots *deuxMots);
 *\brief Désalloue une variable de type MOT_DeuxMots, plus en particulier, ses 2 attributs Mot.
 *
 *\param *deuxMots : Le pointeur sur la variable à désallouer
 */

void MOT_supprimerDeuxMots(MOT_DeuxMots *deuxMots);

/**
 *\fn unsigned int MOT_longueurMot(MOT_Mot mot)
 *\brief Renvoie la longueur d'un mot.
 *
 *\param mot : est le mot de type Mot
 *\return La longueur du mot
 */

int MOT_longueurMot(MOT_Mot mot);

/**
 *\fn int estAvantOrdreAlphabetique(MOT_Mot mot1, MOT_Mot mot2);
 *\brief Renvoie 1 si le mot1 est plus petit que le mot2 par rapport à l'ordre alphabètique, 0 sinon.
 *
 *\param mot1 : mot1 qui va être comparé avec le mot2
 *\param mot2 : mot2 qui va être comparé avec le mot1
 *\return Le booléen de la comparaison.
*/

int estAvantOrdreAlphabetique(MOT_Mot mot1, MOT_Mot mot2);

/**
 *\fn int sontEgaux(Mot mot1, Mot mot2)
 *\brief Renvoie le test si deux mot sont identiques (insensible à la casse)
 *
 *\param mot1 : mot1 qui va être comparé avec le mot2.
 *\param mot2 : mot2 qui va être comparé avec le mot1.
 *\return Le resultat du test de similarité des 2 mots.
*/

int MOT_sontEgaux(MOT_Mot mot1, MOT_Mot mot2);

/**
 *\fn char *MOT_motEnChaine(MOT_Mot mot)
 *\brief Transforme une variable de type Mot en une chaîne de caractères.
 *
 *\param mot : Le Mot qui sera transformé en chaîne.
 *\return La chaine de caractères correspondant au mot.
*/

char *MOT_motEnChaine(MOT_Mot mot);

/**
 *\fn MOT_Mot MOT_remplacerLettre(MOT_Mot mot, int position, char lettre);
 *\brief Renvoie une variable de type MOT_Mot avec une seule de ses lettres remplacée
 *\attention precondition : position < longueur(mot) et estUneLettre(lettre) et position > 0
 *
 *\param mot : Le mot qui sera modifié
 *\param position : La position qui indique quelle lettre sera modifiée
 *\param lettre : La lettre qui remplacera celle à la position pos
 *\return Une copie du mot qui sera modifié
*/

MOT_Mot MOT_remplacerLettre(MOT_Mot mot, int position, char lettre);


/**
 *\fn MOT_Mot MOT_supprimerLettre(MOT_Mot mot, int position);
 *\brief Renvoie une variable de type MOT_Mot avec une seule de ses lettres supprimée
 *\attention precondition : position < longueur(mot) et position > 0
 *
 *\param mot : Le mot qui sera modifié
 *\param position : La position qui indique quelle lettre sera supprimée
 *\return Une copie du mot qui sera modifié
*/
MOT_Mot MOT_supprimerLettre(MOT_Mot mot, int position);


/**
 *\fn MOT_Mot MOT_insererLettre(MOT_Mot mot, int position, char lettre);
 *\brief Renvoie une variable de type MOT_Mot avec une seule de ses lettres insérée
 *\attention precondition : position < longueur(mot) et position > 0 + 1 et estUneLettre(lettre)
 *
 *\param mot : Le mot qui sera modifié
 *\param position : La position qui indique à quelle indice la lettre sera inserée
 *\param lettre : La lettre qui sera insérée
 *\return Une copie du MOT_Mot qui sera modifié
*/
MOT_Mot MOT_insererLettre(MOT_Mot mot, int position, char lettre);


/**
 *\fn MOT_Mot inverserLettre(MOT_Mot mot, int position);
 *\brief Renvoie une variable de type MOT_Mot avec deux de ses lettres consécutives inversées.
 *\attention Precondition : position < longueur(mot) - 1 et position > 0
 *
 *\param mot : Le mot qui sera modifié
 *\param position : La position qui indique à quelle indice la lettre sera inversée avec la lettre qui la succède.
 *\return Une copie du MOT_Mot qui sera modifié
*/
MOT_Mot MOT_inverserLettre(MOT_Mot mot, int position);


/**
 *\fn MOT_DeuxMots MOT_decomposerMot(MOT_Mot mot, int position);
 *\brief Renvoie deux mots issus de la décomposition d'un seul mot.
 *\attention Precondition : position < longueur(mot) - 1 et position > 0
 *
 *\param mot : Le mot qui sera decomposé en deux mots
 *\param position : La position qui indique à quelle indice la décomposition sera faite.
 *\return Une variable de type MOT_DeuxMots qui contient les deux mots issus de la décomposition. Le premier mot est composé des lettres de l'indice 0 à l'indice position et le second, des lettres de l'indice position + 1 à l'indice longueur(mot) - 1
*/
MOT_DeuxMots MOT_decomposerMot(MOT_Mot mot, int position);

/**
 *\fn void MOT_enleverSautDeLigne(char *chaine);
 *\brief Enleve le caractère saut de ligne d'un mot(il faut qu'il soit forcément à l'avant-dernière position). Utilisé pour gerer la lecture des fichiers textes.
 *\attention Precondition : strlen(chaine) >= 2
 *
 *\param *chaine : La chaîne de caractères dont on enlèvera le saut de ligne.
*/

void MOT_enleverSautDeLigne(char *chaine);

#endif
