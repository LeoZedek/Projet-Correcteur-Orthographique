#include"mot.h"
#include"correcteurOrthographique.h"
#include<assert.h>
#include<stdlib.h>
#define Taille_Max 10000

MOT_TableauDeMots MOT_tableauDeMotsVide() {

	MOT_TableauDeMots tabVide;

	tabVide.lesMots = (MOT_Mot*)malloc(sizeof(MOT_Mot) * Taille_Max);
	MOT_fixerLongueurTabMots(&tabVide, 0);
	return tabVide;
}

int MOT_obtenirLongueurTabMots(MOT_TableauDeMots tableauMots) {
	return tableauMots.longueur;
}

void MOT_fixerLongueurTabMots(MOT_TableauDeMots *pointeurTableauMots, int nouvelleLongeur) {
	(*pointeurTableauMots).longueur = nouvelleLongeur;
}

MOT_Mot *MOT_obtenirLesMots(MOT_TableauDeMots tableauMots) {
	return tableauMots.lesMots;
}

MOT_Mot MOT_obtenirIemeMot(MOT_TableauDeMots tableauMots, int position) {
	assert(position < MOT_obtenirLongueurTabMots(tableauMots) && position >= 0);

	MOT_Mot* lesMots = MOT_obtenirLesMots(tableauMots);
	return lesMots[position];
}


void MOT_ajouterMot(MOT_TableauDeMots *tableauMots, MOT_Mot m) {

	assert(MOT_obtenirLongueurTabMots(*tableauMots) < Taille_Max);

	int longueur = MOT_obtenirLongueurTabMots(*tableauMots);
	MOT_Mot *lesMots = MOT_obtenirLesMots(*tableauMots);

	lesMots[longueur] = m;
	MOT_fixerLongueurTabMots(tableauMots, longueur + 1);

}

void MOT_supprimerTableauMots(MOT_TableauDeMots *tableau) {
	MOT_fixerLongueurTabMots(tableau, -1);
	free((*tableau).lesMots);
}

int MOT_estUneLettre(char c) {
	
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || (c == '-');
}

unsigned int MOT_longueurMot(MOT_Mot mot) {
	return 1; //A changer -> pour la compilation
}

int MOT_estUnMot(char *chaine) {
	return 1 ; //A changer -> pour la compilation
}

void MOT_fixerLongueurMot(MOT_Mot *m, unsigned int longeur) {

}

MOT_Mot MOT_creerMot(char *chaine) {
	MOT_Mot mot ; //A changer -> pour la compilation
	return mot ; //A changer -> pour la compilation
}

int MOT_sontEgaux(MOT_Mot m1, MOT_Mot m2) {
	return 1; //A changer -> pour la compilation
}

char *MOT_motEnChaine(MOT_Mot m) {
	char *tmp; //A changer -> pour la compilation
	return tmp; //A changer -> pour la compilation
}

MOT_Mot MOT_remplacerLettre(MOT_Mot m, int pos, char c) {
	MOT_Mot mot ; //A changer -> pour la compilation
	return mot ; //A changer -> pour la compilation
}

MOT_Mot MOT_supprimerLettre(MOT_Mot m, int pos) {
	MOT_Mot mot ; //A changer -> pour la compilation
	return mot ; //A changer -> pour la compilation
}

MOT_Mot MOT_insererLettre(MOT_Mot m, int pos, char c) {
	MOT_Mot mot ; //A changer -> pour la compilation
	return mot ; //A changer -> pour la compilation
}

MOT_Mot MOT_inverserLettre(MOT_Mot m, int pos) {
	MOT_Mot mot ; //A changer -> pour la compilation
	return mot ; //A changer -> pour la compilation
}

MOT_DeuxMots MOT_decomposerMot(MOT_Mot m, int pos) {
	MOT_DeuxMots mot ; //A changer -> pour la compilation
	return mot ; //A changer -> pour la compilation
}
