/**
 * \file dictionnairePrive.h
 * \brief Fichier .h des fonctions privée du TAD Dictionnaire
 * \version 1.0
 * \date 24/12/2021
 *
 */

#ifndef __DICTIONNAIRE_PRIVE__
#define __DICTIONNAIRE_PRIVE__

/**
 *\fn int max(int a, int b)
 *\brief Renvoie le maximum des nombres a et de b
 *
 *\param a : entier
 *\param b : entier
 *\return entier
*/
int max(int a, int b);

/**
 *\fn int abs(int a)
 *\brief Renvoie la valeur absolue du nombres a
 *
 *\param a : entier
 *\return entier positif
*/
int abs(int a);

/**
 *\fn DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaire(MOT_Mot mot)
 *\brief Crée un Dictionnaire
 *
 *\param mot : MOT_Mot
 *\return dictionnaire
*/
DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaire(MOT_Mot mot);

/**
 *\fn int DICTIONNAIRE_estVide(DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief verifie si le dictionnaire est vide
 *
 *\param dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return booléen (unsigned int)
*/

int DICTIONNAIRE_estVide(DICTIONNAIRE_Dictionnaire dictionnaire);

/**
 *\fn DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief obtenir fils  de gauche dictionnaire
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return booléen (unsigned int) si vrai 1, sinon 0 
*/
DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief obtenir fils droit de dictionnaire
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return dictionnaire
*/

DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn MOT_Mot DICTIONNAIRE_obtenirMot(DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief obtenir un mot de dictionnaire
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return MOT_Mot
*/
MOT_Mot DICTIONNAIRE_obtenirMot(DICTIONNAIRE_Dictionnaire dictionnaire);

/**
 *\fn DICTIONNAIRE_fixerMot(DICTIONNAIRE_Dictionnaire *dictionnaire,MOT_Mot mot)
 *\brief Insère un mot dans un dictionnaire
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\param mot : MOT_Mot
 *\return dictionnaire
*/
void DICTIONNAIRE_fixerMot(DICTIONNAIRE_Dictionnaire *dictionnaire,MOT_Mot mot);

/**
 *\fn void DICTIONNAIRE_fixerFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsGauche)
 *\brief fixer fils Gauche dans le Dictionnaire
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\param filsGauche : DICTIONNAIRE_Dictionnaire
 *\return dictionnaire
*/
void DICTIONNAIRE_fixerFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsGauche);

/**
 *\fn  void DICTIONNAIRE_fixerFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsDroit)
 *\brief fixer fils Droit dans le Dictionnaire
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\param filsDroit : DICTIONNAIRE_dictionnaire
 *\return dictionnaire
*/
void DICTIONNAIRE_fixerFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsDroit);

/**
 *\fn void DICTIONNAIRE_simpleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief faire une simple rotation à droite
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return dictionnaire
*/
void DICTIONNAIRE_simpleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn void DICTIONNAIRE_simpleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief faire une simple rotation à gauche
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return dictionnaire
*/
void DICTIONNAIRE_simpleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn void DICTIONNAIRE_doubleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief faire une double rotation à droite
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return dictionnaire
*/
void DICTIONNAIRE_doubleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn void DICTIONNAIRE_doubleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief  faire une double rotation à gauche
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return dictionnaire
*/
void DICTIONNAIRE_doubleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn int DICTIONNAIRE_hauteur(DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief calculer la hauteur de dictionnaire
 *
 *\param dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return entier
*/
int DICTIONNAIRE_hauteur(DICTIONNAIRE_Dictionnaire dictionnaire);

/**
 *\fn void DICTIONNAIRE_reequilibrer(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief reequilibrer l'arbre dictionnaire
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return dictionnaire
*/
void DICTIONNAIRE_reequilibrer(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn int DICTIONNAIRE_estPresent(DICTIONNAIRE_Dictionnaire dictionnaire, MOT_Mot mot)
 *\brief Vérifier la présence d'un mot dans un dictionnaire
 *
 *\param dictionnaire : DICTIONNAIRE_Dictionnaire
 *\param mot : MOT_Mot
 *\return booléen
*/
int DICTIONNAIRE_estPresent(DICTIONNAIRE_Dictionnaire dictionnaire, MOT_Mot mot);

/**
 *\fn void DICTIONNAIRE_ajouterFichier(DICTIONNAIRE_Dictionnaire *dictionnaire, char *nomFichier)
 *\brief Rempli le dictionnaire à partir d'un fichier contenant des mots
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
 *\param *nomFichier : char
*/
void DICTIONNAIRE_ajouterFichier(DICTIONNAIRE_Dictionnaire *dictionnaire, char *nomFichier);

/**
 *\fn DICTIONNAIRE_Dictionnaire DICTIONNAIRE_chargerDictionnaire(char *nomDictionnaire)
 *\brief Charger un dictionnaire depuis un fichier texte
 *
 *\param *nomdictionnaire : char
 *\return dictionnaire
*/
DICTIONNAIRE_Dictionnaire DICTIONNAIRE_chargerDictionnaire(char *nomDictionnaire);

/**
 *\fn void DICTIONNAIRE_enregistrerDictionnaire(char *nomFichierDictionnaire,DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief enregistrer un dictionnaire depuis un fichier texte
 *
 *\param *nomFichierdictionnaire : char
 *\param dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return un fichier
*/
void DICTIONNAIRE_enregistrerDictionnaire(char *nomFichierDictionnaire,DICTIONNAIRE_Dictionnaire dictionnaire);

/**
 *\fn void DICTIONNAIRE_supprimer(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief supprimer un dictionnaire 
 *
 *\param *dictionnaire : DICTIONNAIRE_Dictionnaire
*/
void DICTIONNAIRE_supprimer(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn void DICTIONNAIRE_afficherArbre(DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief afficher un arbre d'un dictionnaire
 *
 *\param dictionnaire : DICTIONNAIRE_Dictionnaire
 *\return arbre
*/
void DICTIONNAIRE_afficherArbre(DICTIONNAIRE_Dictionnaire dictionnaire);
#endif
