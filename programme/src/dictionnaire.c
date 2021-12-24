/**
 * \file dictionnaire.c
 * \brief Implémantation du TAD dictionnaire
 * \version 1.0
 * \date 03/01/2022
 *
 */
#include <string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include"dictionnaire.h"
#include"mot.h"


#define TAILLEMOTMAX 50


/*------------Signatures------------------------------*/
int max(int a, int b);
int abs(int a);
DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaire();
int DICTIONNAIRE_estVide(DICTIONNAIRE_Dictionnaire dictionnaire);
DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);
DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire);
MOT_Mot DICTIONNAIRE_obtenirMot(DICTIONNAIRE_Dictionnaire dictionnaire);
void DICTIONNAIRE_fixerMot(DICTIONNAIRE_Dictionnaire *dictionnaire,MOT_Mot mot);
void DICTIONNAIRE_fixerFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsGauche);
void DICTIONNAIRE_fixerFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsDroit);
void DICTIONNAIRE_simpleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire);
void DICTIONNAIRE_simpleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);
void DICTIONNAIRE_doubleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire);
void DICTIONNAIRE_doubleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire);
int DICTIONNAIRE_hauteur(DICTIONNAIRE_Dictionnaire dictionnaire);
void DICTIONNAIRE_reequilibrer(DICTIONNAIRE_Dictionnaire *dictionnaire);
int DICTIONNAIRE_estPresent(DICTIONNAIRE_Dictionnaire dictionnaire, MOT_Mot mot);
void DICTIONNAIRE_ajouterMot(DICTIONNAIRE_Dictionnaire *dictionnaire, MOT_Mot mot);
void DICTIONNAIRE_ajouterFichier(DICTIONNAIRE_Dictionnaire *dictionnaire, char *nomFichier);
DICTIONNAIRE_Dictionnaire DICTIONNAIRE_chargerDictionnaire(char chaine);
void DICTIONNAIRE_enregistrerDictionnaire(char *nomFichierDictionnaire,DICTIONNAIRE_Dictionnaire dictionnaire);
void DICTIONNAIRE_enregistrerDicoRec(FILE *fichier,DICTIONNAIRE_Dictionnaire dictionnaire);
void DICTIONNAIRE_supprimer(DICTIONNAIRE_Dictionnaire *dictionnaire);
void DICTIONNAIRE_afficherArbre(DICTIONNAIRE_Dictionnaire dictionnaire);
/*--------------Fonction Privé--------------------------*/
//Qui ne sont ni dans la conception ni dans le .h
int max(int a, int b){
	if (a>b){
		return a;
	}
	else{
		return b;
	}
}

int abs(int a){
	if (a>0){
		return a;
	}
	else{
		return -a;
	}
}

DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaire(MOT_Mot mot){
	DICTIONNAIRE_Dictionnaire dictionnaire ;
	dictionnaire = (DICTIONNAIRE_Dictionnaire)malloc(sizeof(DICTIONNAIRE_Noeuds));
	dictionnaire->mot = mot ;
	dictionnaire->filsGauche = DICTIONNAIRE_dictionnaireVide();
	dictionnaire->filsDroit = DICTIONNAIRE_dictionnaireVide() ;
	return dictionnaire ;
}

void DICTIONNAIRE_fixerMot(DICTIONNAIRE_Dictionnaire *dictionnaire,MOT_Mot mot){
	(*dictionnaire)->mot = mot;
}

DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire){
	assert(!(DICTIONNAIRE_estVide(*dictionnaire))) ;
	return &((*dictionnaire)->filsGauche) ;
}

DICTIONNAIRE_Dictionnaire *DICTIONNAIRE_obtenirFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire){
	assert(!(DICTIONNAIRE_estVide(*dictionnaire))) ;
	return &((*dictionnaire)->filsDroit) ;
}

MOT_Mot DICTIONNAIRE_obtenirMot(DICTIONNAIRE_Dictionnaire dictionnaire){
	assert(!(DICTIONNAIRE_estVide(dictionnaire))) ;
	return dictionnaire->mot ;
}

void DICTIONNAIRE_fixerFilsGauche(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsGauche){
	(*dictionnaire)->filsGauche=filsGauche ;
}

void DICTIONNAIRE_fixerFilsDroit(DICTIONNAIRE_Dictionnaire *dictionnaire, DICTIONNAIRE_Dictionnaire filsDroit){
	(*dictionnaire)->filsDroit = filsDroit ;
}

void DICTIONNAIRE_simpleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire){
	assert(!(DICTIONNAIRE_estVide(*dictionnaire)) 
		&& !(DICTIONNAIRE_estVide(*DICTIONNAIRE_obtenirFilsGauche(dictionnaire))));
	DICTIONNAIRE_Dictionnaire *racine, *filsGauche, *filsDroitGauche;
	racine = dictionnaire ;
	filsGauche = DICTIONNAIRE_obtenirFilsGauche(dictionnaire) ;
	filsDroitGauche = DICTIONNAIRE_obtenirFilsDroit(filsGauche) ;
	DICTIONNAIRE_fixerFilsGauche(racine, *filsDroitGauche) ;
	DICTIONNAIRE_fixerFilsDroit(filsGauche, *racine) ;
	dictionnaire = filsGauche ;
}

void DICTIONNAIRE_simpleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire){
	assert(!(DICTIONNAIRE_estVide(*dictionnaire))
		&& !(DICTIONNAIRE_estVide(*DICTIONNAIRE_obtenirFilsDroit(dictionnaire))));
	
	DICTIONNAIRE_Dictionnaire *racine, *filsDroit, *filsGaucheDroit;
	
	racine = dictionnaire ;
	filsDroit = DICTIONNAIRE_obtenirFilsDroit(dictionnaire) ;
	filsGaucheDroit = DICTIONNAIRE_obtenirFilsGauche(filsDroit) ;
	DICTIONNAIRE_fixerFilsGauche(filsDroit, *racine) ;
	DICTIONNAIRE_fixerFilsDroit(racine, *filsGaucheDroit) ;
	dictionnaire = filsDroit ;
}

void DICTIONNAIRE_doubleRotationDroite(DICTIONNAIRE_Dictionnaire *dictionnaire){
	assert( !(DICTIONNAIRE_estVide(*dictionnaire)) 
		&& !(DICTIONNAIRE_estVide(*DICTIONNAIRE_obtenirFilsGauche(dictionnaire))) 
		&& !(DICTIONNAIRE_estVide(*DICTIONNAIRE_obtenirFilsDroit(DICTIONNAIRE_obtenirFilsGauche(dictionnaire)))) );
	
	DICTIONNAIRE_Dictionnaire *filsGauche;
	
	filsGauche = DICTIONNAIRE_obtenirFilsGauche(dictionnaire);
	DICTIONNAIRE_simpleRotationGauche(filsGauche);
	DICTIONNAIRE_fixerFilsGauche(dictionnaire, *filsGauche);
	DICTIONNAIRE_simpleRotationDroite(dictionnaire);
}

void DICTIONNAIRE_doubleRotationGauche(DICTIONNAIRE_Dictionnaire *dictionnaire){
	assert( !(DICTIONNAIRE_estVide(*dictionnaire)) 
		&& !(DICTIONNAIRE_estVide(*DICTIONNAIRE_obtenirFilsDroit(dictionnaire))) 
		&& !(DICTIONNAIRE_estVide(*DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_obtenirFilsDroit(dictionnaire)))) );
	
	DICTIONNAIRE_Dictionnaire *filsDroit;
	
	filsDroit = DICTIONNAIRE_obtenirFilsDroit(dictionnaire);
	DICTIONNAIRE_simpleRotationDroite(dictionnaire);
	DICTIONNAIRE_fixerFilsDroit(dictionnaire,*filsDroit);
	DICTIONNAIRE_simpleRotationGauche(dictionnaire);
}

int DICTIONNAIRE_hauteur(DICTIONNAIRE_Dictionnaire dictionnaire){
	if (!(dictionnaire)){
		return 0;
	}
	else{
		return max(DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsGauche(&dictionnaire)), DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsDroit(&dictionnaire)));
	}
}

void DICTIONNAIRE_reequilibrer(DICTIONNAIRE_Dictionnaire *dictionnaire){
	assert( !(DICTIONNAIRE_estVide(*dictionnaire)) && (abs(DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsGauche(dictionnaire))-DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsDroit(dictionnaire))) == 2));
	
	if (DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsGauche(dictionnaire)) > DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsDroit(dictionnaire))){
		if (DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_obtenirFilsGauche(dictionnaire))) > DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsDroit(DICTIONNAIRE_obtenirFilsGauche(dictionnaire))) ){
			DICTIONNAIRE_simpleRotationDroite(dictionnaire);
		}
		else{
			DICTIONNAIRE_doubleRotationDroite(dictionnaire);
		}
	}
	else{
		if (DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsDroit(DICTIONNAIRE_obtenirFilsDroit(dictionnaire))) > DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_obtenirFilsDroit(dictionnaire)))){
			DICTIONNAIRE_simpleRotationGauche(dictionnaire);
		}
		else{
			DICTIONNAIRE_doubleRotationGauche(dictionnaire);
		}
	}
}

void DICTIONNAIRE_enregistrerDicoRec(FILE *fichier,DICTIONNAIRE_Dictionnaire dictionnaire){//version "naive"
	MOT_Mot motAsauvegarder;
	char *chaineAsauvegarder = (char *)malloc(TAILLEMOTMAX * sizeof(char));
	DICTIONNAIRE_Dictionnaire filsGauche,filsDroit;
	if(dictionnaire){
		motAsauvegarder = DICTIONNAIRE_obtenirMot(dictionnaire);
		chaineAsauvegarder = MOT_motEnChaine(motAsauvegarder);
		fprintf(fichier,"%s\n",chaineAsauvegarder);
		filsGauche = *DICTIONNAIRE_obtenirFilsGauche(dictionnaire);
		filsDroit = *DICTIONNAIRE_obtenirFilsDroit(dictionnaire);
		if(filsGauche){
			DICTIONNAIRE_enregistrerDicoRec(fichier,filsGauche);
		}
		if(filsDroit){
			DICTIONNAIRE_enregistrerDicoRec(fichier,filsDroit);
		}
	}
	free(chaineAsauvegarder);
}

/*--------------Fonction Publique--------------------------*/
DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaireVide(){
	return NULL ;
}

int DICTIONNAIRE_estVide(DICTIONNAIRE_Dictionnaire dictionnaire){
	return (dictionnaire==NULL);
}

int DICTIONNAIRE_estPresent(DICTIONNAIRE_Dictionnaire dictionnaire, MOT_Mot mot){
	MOT_Mot motDico ;
	char *chaineAtester ;
	char *chaineDico ;
	if (DICTIONNAIRE_estVide(dictionnaire)){
		return 0 ;
	}
	else{
		motDico = DICTIONNAIRE_obtenirMot(dictionnaire);
		if (MOT_sontEgaux(mot,motDico)){
			return 1;
		}
		else{
			chaineAtester = MOT_motEnChaine(mot);
			chaineDico = MOT_motEnChaine(motDico);
			if (strcmp(chaineAtester, chaineDico)<0){
				return DICTIONNAIRE_estPresent(*DICTIONNAIRE_obtenirFilsGauche(&dictionnaire), mot) ;
			}
			else{
				return DICTIONNAIRE_estPresent(*DICTIONNAIRE_obtenirFilsDroit(&dictionnaire), mot) ;
			}
		}
	}
}

void DICTIONNAIRE_ajouterMot(DICTIONNAIRE_Dictionnaire *dictionnaire, MOT_Mot mot){
	DICTIONNAIRE_Dictionnaire *filsGauche, *filsDroit ;
	char *chaineAInserer;
	char *chaineTest;
	MOT_Mot motDico;
	
	if (DICTIONNAIRE_estVide(*dictionnaire)){
		*dictionnaire = DICTIONNAIRE_dictionnaire(mot);
	}
	else{
		chaineAInserer = MOT_motEnChaine(mot) ;
		motDico = DICTIONNAIRE_obtenirMot(*dictionnaire);
		chaineTest = MOT_motEnChaine(motDico) ; 
		if (strcmp(chaineAInserer, chaineTest)<0){
			filsGauche = DICTIONNAIRE_obtenirFilsGauche(dictionnaire);
			DICTIONNAIRE_ajouterMot(filsGauche,mot);
			DICTIONNAIRE_fixerFilsGauche(dictionnaire, *filsGauche);
		}
		else{
			if (strcmp(chaineAInserer,chaineTest)>0){
				filsDroit = DICTIONNAIRE_obtenirFilsDroit(dictionnaire);
				DICTIONNAIRE_ajouterMot(filsDroit, mot);
				DICTIONNAIRE_fixerFilsDroit(dictionnaire,*filsDroit);
			}//else c'est les meme chaine donc pas besoin d'inserer
		}
		if (abs(DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsGauche(dictionnaire))-DICTIONNAIRE_hauteur(*DICTIONNAIRE_obtenirFilsDroit(dictionnaire))) == 2){
			DICTIONNAIRE_reequilibrer(dictionnaire);
		}
	}
}

void DICTIONNAIRE_ajouterFichier(DICTIONNAIRE_Dictionnaire *dictionnaire, char *nomFichier){
	char chaine[TAILLEMOTMAX] = "";
	MOT_Mot mot ;
	FILE* fichier =NULL ;
	fichier = fopen(nomFichier, "r");
	if (fichier){
		while(fgets(chaine,TAILLEMOTMAX,fichier) != NULL){
			MOT_enleverSautDeLigne(chaine);
			mot = MOT_creerMot(chaine);
			DICTIONNAIRE_ajouterMot(dictionnaire, mot);
		}
		fclose(fichier);
	}
	else{
		fprintf(stderr,"le fichier n'existe pas");
		assert(0);
	}
}

DICTIONNAIRE_Dictionnaire DICTIONNAIRE_chargerDictionnaire(char nomDictionnaire){
/* 	FILE *fichierDictionnaire = NULL ;
	char chaine[TAILLEMOTMAX] = "";
	fichierDictionnaire = fopen(nomDictionnaire,"r"); */
	DICTIONNAIRE_Dictionnaire dictionnaire ;
	DICTIONNAIRE_ajouterFichier(&dictionnaire,nomDictionnaire);
/* 	if (!fichierDictionnaire){// Le fichier donnée en paramètre n'existe pas donc on renvoie le dico vide
		dictionnaire = DICTIONNAIRE_dictionnaireVide();
	}
	//cas ou le fichier existe le charger	Question comment est stocker est fichier ? donc comment le charger ?
	else{
		//Version non naive a coder ici
		fclose(fichierDictionnaire);
	} */
	return dictionnaire;
}

void DICTIONNAIRE_enregistrerDictionnaire(char *nomFichierDictionnaire,DICTIONNAIRE_Dictionnaire dictionnaire){
	FILE *fichierDictionnaire = NULL;
	fichierDictionnaire = fopen(nomFichierDictionnaire,"w+");
	assert(fichierDictionnaire);
	DICTIONNAIRE_enregistrerDicoRec(fichierDictionnaire,dictionnaire);
	fclose(nomFichierDictionnaire);
	DICTIONNAIRE_supprimer(dictionnaire);
}

void DICTIONNAIRE_supprimer(DICTIONNAIRE_Dictionnaire *dictionnaire){
	DICTIONNAIRE_Dictionnaire *filsGauche, * filsDroit;
	filsGauche = DICTIONNAIRE_obtenirFilsGauche(dictionnaire);
	filsDroit = DICTIONNAIRE_obtenirFilsDroit(dictionnaire);
	if(filsGauche){
		DICTIONNAIRE_supprimer(filsGauche);
	}
	if (filsDroit){
		DICTIONNAIRE_supprimer(filsDroit);
	}
	free(*dictionnaire);
	*dictionnaire = NULL;
}

void DICTIONNAIRE_afficherArbre(DICTIONNAIRE_Dictionnaire dictionnaire){
	if (!dictionnaire){
		return;
	}
	if (dictionnaire->filsGauche){
		DICTIONNAIRE_afficherArbre(dictionnaire->filsGauche);
	}
	printf("%s\n",MOT_motEnChaine(DICTIONNAIRE_obtenirMot(dictionnaire)));
	if (dictionnaire->filsDroit){
		DICTIONNAIRE_afficherArbre(dictionnaire->filsDroit);
	}
}
