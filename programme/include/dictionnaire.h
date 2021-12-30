/**
 * \file dictionnaire.h
 * \brief Implantation du TAD dictionnaire
 * \version 1.0
 * \date 03/01/2022
 *
 */

#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__
#include"mot.h"

/**
 * \brief Le type noeuds est représenté par un mot (type MOT_Mot défini dans le fichier mot.h) et de deux pointeurs filsGauche et filsDroit qui représentent la suite de l'arbre que constitue le dictionnaire.
 *
 */
typedef struct DICTIONNAIRE_Noeuds{
	MOT_Mot mot ;
	struct DICTIONNAIRE_Noeuds *filsGauche ;
	struct DICTIONNAIRE_Noeuds *filsDroit ;
	int hauteur;
} DICTIONNAIRE_Noeuds ;


/**
 * \brief Le type Dictionnaire qui représente un dictionnaire à partir d'un noeud.
 * 
 */
typedef DICTIONNAIRE_Noeuds *DICTIONNAIRE_Dictionnaire;

/**
 *\fn int DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaireVide();
 *\brief Renvoie un Dictionnaire vide. Ce sera un pointeur vers NULL. 
 *
 *\return Le dictionnaire vide.
*/

DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaireVide();

/**
 *\fn int DICTIONNAIRE_estVide(DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief renvoie le booléen vrai (1) si le dictionnaire est vide. 
 *
 *\param dictionnaire : Le dictionnaire qui sera testé
 *\return Un booléen vrai si le dictionnaire est vide
*/
int DICTIONNAIRE_estVide(DICTIONNAIRE_Dictionnaire dictionnaire) ;


/**
 *\fn int DICTIONNAIRE_estPresent(DICTIONNAIRE_Dictionnaire dictionnaire, MOT_Mot mot)
 *\brief Teste si un mot est présent dans un dictionnaire.
 *
 *\param dictionnaire : Le dictionnaire dans lequel on vérifie si le mot est présent
 *\param mot : Le mot dont on veut vérifier la présence dans le dictionnaire
 *\return Un booleen : 1 (Vrai) si le mot est présent dans le dictionnaire
*/
int DICTIONNAIRE_estPresent(DICTIONNAIRE_Dictionnaire dictionnaire, MOT_Mot mot) ;

/**
 *\fn void DICTIONNAIRE_ajouterMot(DICTIONNAIRE_Dictionnaire *dictionnaire, MOT_Mot mot)
 *\brief Ajoute un mot au dictionnaire.
 *\attention precondition : non(DICTIONNAIRE_estPresent(dictionnaire,mot))
 *
 *\param *dictionnaire : Le pointeur vers le dictionnaire dans lequel on insère le mot
 *\param mot : Le mot que l'on insère
 *\return Ne renvoie rien mais modifie l'état du dictionnaire
*/
void DICTIONNAIRE_ajouterMot(DICTIONNAIRE_Dictionnaire *dictionnaire, MOT_Mot mot);


/**
 *\fn void DICTIONNAIRE_ajouterFichier(DICTIONNAIRE_Dictionnaire *dictionnaire, char *nomFichier)
 *\brief ajoute le contenu d'un fichier dans le dictionnaire.
 *\attention precondition : Le fichier doit être accessible en lecture et nomFichier != ""
 *
 *\param *dictionnaire : Le pointeur vers lequelle on insère les mots du fichier
 *\param nomFichier : Le nom du fichier qui contient tous les mots à insérer
 *\return Ne renvoie rien, modifie juste le contenue du dictionnaire
*/
void DICTIONNAIRE_ajouterFichier(DICTIONNAIRE_Dictionnaire *dictionnaire, char *nomFichier);


/**
 *\fn DICTIONNAIRE_Dictionnaire DICTIONNAIRE_chargerDictionnaire(char nomDictionnaire)
 *\brief Charge le dictionnaire du nom chaine 
 *\attention precondition : Le fichier doit être accessible en lecture et nomDictionnaire != ""
 *
 *\param nomDuDictionnaire : Le nom du fichier du dictionnaire à charger
 *\return Retourne le dictionnaire créé
*/
DICTIONNAIRE_Dictionnaire DICTIONNAIRE_chargerDictionnaire(char *nomDictionnaire);


/**
 *\fn void DICTIONNAIRE_enregistrerDictionnaire(char *nomFichierDictionnaire,DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief Enregistre le dictionnaire en paramètre dans un fichier dont le nom est passé en paramètre
 *\attention precondition : Le fichier doit être accessible en écriture et nomFichierDictionnaire != ""
 *
 *\param nomFichierDictionnaire : Le nom du fichier dans lequel on enregistre le dictionnaire
 *\param dictionnaire : Le dictionnaire que l'on enregistre dans le fichier
 *\return void
*/
void DICTIONNAIRE_enregistrerDictionnaire(char *nomFichierDictionnaire,DICTIONNAIRE_Dictionnaire dictionnaire);

/**
 *\fn void DICTIONNAIRE_supprimer(DICTIONNAIRE_Dictionnaire *dictionnaire)
 *\brief Supprime et désalloue entièrement un dictionnaire.
 *
 *\param *dictionnaire : Le pointeur sur le dictionnaire qui sera supprimé.
*/
void DICTIONNAIRE_supprimer(DICTIONNAIRE_Dictionnaire *dictionnaire);

/**
 *\fn void DICTIONNAIRE_afficherArbre(DICTIONNAIRE_Dictionnaire dictionnaire)
 *\brief Affiche un dictionnaire.
 *
 *\param dictionnaire : Le dictionnaire à afficher
*/
void DICTIONNAIRE_afficherArbre(DICTIONNAIRE_Dictionnaire dictionnaire);
#endif
