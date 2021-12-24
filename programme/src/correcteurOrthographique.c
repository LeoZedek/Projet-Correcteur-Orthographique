#include <stdlib.h>
#include <assert.h>
#include "mot.h"
#include "dictionnaire.h"
#include "correcteurOrthographique.h"
#define CO_TailleMax = 1000

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

/*TEMPORAIRE MAIS PEUT ETRE COMPLETER ET ADAPTER !*/

CO_MotsDansPhrase CO_motsEtPositionsVide(){
	CO_MotsDansPhrase motPhrase;
	motPhrase.mots = MOT_tableauDeMotsVide();
	motPhrase.positions = CO_tableauDEntiersVide();
	return motPhrase; 
}

MOT_TableauDeMots CO_obtenirTabMots(CO_MotsDansPhrase motsEtPosition){
	MOT_TableauDeMots tab; 
	tab = motsEtPosition.mots;
	return tab; 
}

CO_TableauPositions CO_obtenirTabPositions(CO_MotsDansPhrase motsEtPosition){
	CO_TableauPositions tmp ; //A changer -> pour la compilation
	return tmp ; //A changer -> pour la compilation
}

void CO_supprimerMotsEtPositions(CO_MotsDansPhrase *motsEtPosition){

}

CO_TableauBooleens CO_sontPresents(MOT_TableauDeMots mots, DICTIONNAIRE_Dictionnaire dictionnaire){
	CO_TableauBooleens tmp ; //A changer -> pour la compilation
	return tmp; //A changer -> pour la compilation
} 

MOT_TableauDeMots CO_proposerMots(MOT_Mot m, DICTIONNAIRE_Dictionnaire dictionnaire){
	MOT_TableauDeMots tmp; //A changer -> pour la compilation
	return tmp ; //A changer -> pour la compilation
}

CO_MotsDansPhrase CO_phraseEnMots(char *phrase){
	CO_MotsDansPhrase tmp ; //A changer -> pour la compilation
	return tmp; //A changer -> pour la compilation
}
