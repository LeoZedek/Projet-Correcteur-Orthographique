/**
 * \file dictionnaire.h
 * \brief Implantation du TAD dictionnaire
 * \version 1.0
 * \date 03/01/2022
 *
 */
#include"mot.h"
#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__

/**
 * \brief Le type noeuds est représenté par un mot (type mot définie dans le fichier mot.h) et de deux pointeur filsGauche et filsDroit qui représente la suite de l'arbre que constitue le dictionnaire
 *
 */
typedef struct {
	Mot mot ;
	Noeuds *filsGauche ;
	Noeuds *filsDroit ;
} Noeuds ;


/**
 * \brief Le type  Dictionaire qui représentent un dictionnaire à partir d'un noeuds
 * 
 */
typedef *Noeuds Dictionaire;


/**
 *\fn int DICTIONNAIRE_estVide(Dictionnaire dictionnaire)
 *\brief renvoie le booleen vrai (1) si le dictionnaire est vide 
 *
 *\param dictionnaire : Le dictionnaire qui serra teste
 *\return Un boolen vrai si le dictionnaire est vide
*/
int DICTIONNAIRE_estVide(Dictionnaire dictionnaire) ;


/**
 *\fn int DICTIONNAIRE_estPresent(Dictionaire dictionnaire, Mot mot)
 *\brief Test si un mot est présent dans un dictionnaire
 *
 *\param dictionnaire : Le dictionnaire dans lequelle on vérifi si le mot est présent
 *\param mot : Le mot que dont on veut vérifier la présence dans le dictionnaire
 *\return Un booleen : 1 (Vrai) si le mot est présent dans le dictionnaire
*/
int DICTIONNAIRE_estPresent(Dictionaire dictionnaire, Mot mot) ;


/**
 *\fn Dictionaire DICTIONNAIRE_obtenirFilsGauche(Dictionnaire dictionnaire)
 *\brief Renvoie le fils gauche du dictionnaire "dictionnaire"
 *
 *\param dictionnaire : Le dictionnaire en question (racine 'actuel' de l'arbre')
 *\return Le sous arbre gauche de la racine du dictionnaire passé en paramètre
*/
Dictionaire DICTIONNAIRE_obtenirFilsGauche(Dictionnaire dictionnaire) ;


/**
 *\fn Dictionaire DICTIONNAIRE_obtenirFilsDroit(Dictionnaire dictionnaire)
 *\brief Renvoie le fils droit du dictionnaire "dictionnaire"
 *
 *\param dictionnaire : Le dictionnaire en question (racine 'actuel' de l'arbre')
 *\return Le sous arbre droit de la racine du dictionnaire passé en paramètre
*/
Dictionaire DICTIONNAIRE_obtenirFilsDroit(Dictionnaire dictionnaire) ;


/**
 *\fn void DICTIONNAIRE_ajouterMot(Dictionaire *dictionnaire, Mot mot)
 *\brief Ajoute un mot au dictionnaire
 *\attention precondition : non(DICTIONNAIRE_estPresent(dictionnaire,mot))
 *
 *\param *dictionnaire : Le pointeur vers le dictionnaire dans lequelle on insère le mot
 *\param mot : Le mot que l'on insère
 *\return Ne renvoye rien mais modifie l'etat du dicctionnaire
*/
void DICTIONNAIRE_ajouterMot(Dictionaire *dictionnaire, Mot mot);


/**
 *\fn void DICTIONNAIRE_ajouterFichier(Dictionaire *dictionnaire, fichier)
 *\brief ajoute le contenue d'un fichier dans le dictionnaire
 *\attention precondition : Le fichier doit être accessible en lecture
 *
 *\param *dictionnaire : Le pointeur vers lequelle on insère les mots du fichier
 *\param nomFichier : Le nom du fichier qui contient tous les mots à insérer
 *\return Ne renvoie rien, modifie juste le contenue du dictionnaire
*/
void DICTIONNAIRE_ajouterFichier(Dictionaire *dictionnaire, char nomFichier);


/**
 *\fn Dictionaire DICTIONNAIRE_chargerDictionnaire(char nomDuDictionnaire)
 *\brief Charge le dictionnaire du nom chaine 
 *\attention precondition : Le fichier doit être accessible en lecture
 *
 *\param nomDuDictionnaire : Le nom du fichier du dictionnaire à charger
 *\return Retourne le dictionnaire créé
*/
Dictionaire DICTIONNAIRE_chargerDictionnaire(char chaine);


/**
 *\fn void DICTIONNAIRE_enregistrerDictionnaire(Dictionaire dictionnaire)
 *\brief Enregistre le dictionnaire en paramètre dans un fichier dont il renvoie le nom
 *\attention precondition : Le fichier doit être accessible en lecture
 *
 *\param dictionnaire : Le dictionnaire que l'on enregistre dans le fichier
 *\return Le nom du fichier enregistré
*/
char *DICTIONNAIRE_enregistrerDictionnaire(Dictionaire dictionnaire);

#endif
