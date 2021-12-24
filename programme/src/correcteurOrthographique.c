#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "mot.h"
#include "dictionnaire.h"
#include "correcteurOrthographique.h"
#define CO_TailleMax = 1000

/*----------------------------------PARTIE PRIVEE-----------------------------------------------*/

CO_TableauDEntiers CO_tableauDEntiersVide(){
	CO_TableauDEntiers tab;
	tab.lesEntiers = NULL;
	tab.longueur = 0;
	return tab;
}

int CO_obtenirLongueurTabEntiers(CO_TableauDEntiers tableauEntiers){
	return tableauEntiers.longueur;
}

void CO_fixerLongueurTabEntiers(CO_TableauDEntiers *pointeurTableauEntiers, int nouvelleLongueur){
	(*pointeurTableauEntiers).longueur = nouvelleLongueur;
}


int CO_obtenirIemeEntier(CO_TableauDEntiers tableauEntiers, int position)
//position>=0 et position <= longueur tableau
{
	return tableauEntiers.lesEntiers[position];
}

int *CO_obtenirLesEntiers(CO_TableauDEntiers tableauEntiers){
	return tableauEntiers.lesEntiers;
}

void CO_ajouterEntier(CO_TableauDEntiers *tableauEntiers, int entierAAjouter){
	CO_fixerLongueurTabEntiers(tableauEntiers, CO_obtenirLongueurTabEntiers(*tableauEntiers)+1);
	(*tableauEntiers).lesEntiers[CO_obtenirLongueurTabEntiers(*tableauEntiers)] = entierAAjouter;
}

void CO_supprimerTableauEntiers(CO_TableauDEntiers *tableau){
	free((*tableau).lesEntiers);
	CO_fixerLongueurTabEntiers(tableau, -1);
}

CO_MotsDansPhrase CO_motsEtPositionsVide(){
	CO_MotsDansPhrase motPhrase;
	motPhrase.mots = MOT_tableauDeMotsVide();
	motPhrase.positions = CO_tableauDEntiersVide();
	return motPhrase; 
}

MOT_TableauDeMots CO_obtenirTabMots(CO_MotsDansPhrase motsEtPosition){
	MOT_TableauDeMots tabMots; 
	tabMots = motsEtPosition.mots;
	return tabMots; 
}

CO_TableauPositions CO_obtenirTabPositions(CO_MotsDansPhrase motsEtPosition){
	CO_TableauPositions tabPos; 
	tabPos = motsEtPosition.positions;
	return tabPos;
}

void CO_supprimerMotsEtPositions(CO_MotsDansPhrase *motsEtPosition){
	MOT_TableauDeMots tabMots = CO_obtenirTabMots(*motsEtPosition); 
	CO_TableauPositions tabPos = CO_obtenirTabPositions(*motsEtPosition);
	MOT_supprimerTableauMots(*tabMots);
	CO_supprimerTableauEntiers(*tabPos);
}


/*----------------------------------PARTIE PUBLIQUE---------------------------------------------*/

CO_TableauBooleens CO_sontPresents(MOT_TableauDeMots mots, DICTIONNAIRE_Dictionnaire dictionnaire){
	CO_TableauBooleens tabBool = CO_tableauDEntiersVide();
	int i;
	MOT_Mot mot;
	int longueur = MOT_obtenirLongueurTabMots(mots);
	for (i = 0; i<longueur; i++){
	mot = MOT_obtenirIemeMot(mots, i);
		if (DICTIONNAIRE_estPresent(dictionnaire, mot)){
			CO_ajouterEntier(&tabBool,1);
		}
		else{
			CO_ajouterEntier(&tabBool,0);
		}
	}
	return tabBool; 
} 

MOT_TableauDeMots CO_proposerMots(MOT_Mot m, DICTIONNAIRE_Dictionnaire dictionnaire){
	MOT_TableauDeMots resultatMots; 
	MOT_Mot motCorrige;
	MOT_DeuxMots motCorriges;
	char tiret;
	for (char lettre = 'a'; lettre <= 'z'; lettre++){
		for (int i=0 ; i< MOT_longueurMot(m); i++){
			motCorrige = MOT_remplacerLettre(m, i, lettre);
			if (DICTIONNAIRE_estPresent(dictionnaire, motCorrige))
				MOT_ajouterMot(&resultatMots, motCorrige);
		}
		for (int i=0 ; i< MOT_longueurMot(m)+1; i++){
			motCorrige = MOT_insererLettre(m, i, lettre);
			if (DICTIONNAIRE_estPresent(dictionnaire, motCorrige))
				MOT_ajouterMot(&resultatMots, motCorrige);
		}
	
	}
	tiret = '-';
	for (int i=0 ; i< MOT_longueurMot(m); i++){
			motCorrige = MOT_remplacerLettre(m, i, tiret);
			if (DICTIONNAIRE_estPresent(dictionnaire, motCorrige))
				MOT_ajouterMot(&resultatMots, motCorrige);
		}
	for (int i=0 ; i< MOT_longueurMot(m)+1; i++){
			motCorrige = MOT_insererLettre(m, i, tiret);
			if (DICTIONNAIRE_estPresent(dictionnaire, motCorrige))
				MOT_ajouterMot(&resultatMots, motCorrige);
		}
		
	for (int i=0 ; i< MOT_longueurMot(m); i++){
			motCorrige = MOT_supprimerLettre(m, i);
			if (DICTIONNAIRE_estPresent(dictionnaire, motCorrige))
				MOT_ajouterMot(&resultatMots, motCorrige);
		}
	for (int i=1 ; i< MOT_longueurMot(m)-1; i++){
			motCorriges = MOT_decomposerMot(m, i);
			if (DICTIONNAIRE_estPresent(dictionnaire, motCorriges.mot1))
				MOT_ajouterMot(&resultatMots, motCorriges.mot1);
			if (DICTIONNAIRE_estPresent(dictionnaire, motCorriges.mot2))
				MOT_ajouterMot(&resultatMots, motCorriges.mot2);
		}
	return resultatMots; 
}

CO_MotsDansPhrase CO_phraseEnMots(char *phrase){
	int i;
	int pos = 0;
	int longueurPhrase = strlen(phrase);
	char temp[longueurPhrase];
	MOT_Mot mot;
	CO_MotsDansPhrase motsPhrase;
	motsPhrase = CO_motsEtPositionsVide();
	MOT_TableauDeMots tabMots = CO_obtenirTabMots(motsPhrase);
	CO_TableauPositions tabPos = CO_obtenirTabPositions(motsPhrase);
	for (i=0; i<longueurPhrase; i++){
		if (MOT_estUneLettre(phrase[i])){
			temp[i-pos] = phrase[i];
		}	
		else {
			temp[i-pos+1] = '\0';
			pos = i + 1;
			mot = MOT_creerMot(temp); 
			MOT_ajouterMot(&tabMots, mot);
			CO_ajouterEntier(&tabPos, pos);
		}
		
	}
	return motsPhrase; 
}
