#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

#include"mot.h"
#include"motPrivee.h"

#define Taille_Max_Tableau 10000
#define TRUE 1
#define FALSE 0

//////////////PARTIE PRIVÉÉ////////////////////////////////////

void MOT_fixerLongueurTabMots(MOT_TableauDeMots *pointeurTableauMots, int nouvelleLongeur) {
	(*pointeurTableauMots).longueur = nouvelleLongeur;
}

MOT_Mot *MOT_obtenirLesMots(MOT_TableauDeMots tableauMots) {
	return tableauMots.lesMots;
}

MOT_Mot MOT_copierMot(MOT_Mot m) {
	MOT_Mot copie;
	char *chaine = MOT_motEnChaine(m);

	copie = MOT_creerMot(chaine);

	return copie;
}

void MOT_fixerIemeMot(MOT_TableauDeMots *tableau, MOT_Mot m, int i) {

	assert(i < MOT_obtenirLongueurTabMots(*tableau));

	MOT_Mot *lesMots = MOT_obtenirLesMots(*tableau);

	lesMots[i] = MOT_copierMot(m);
}

unsigned int MOT_longueurMot(MOT_Mot mot) {
	return mot.longueur;
}

void MOT_fixerLongueurMot(MOT_Mot *m, int nvLongueur) {
	(*m).longueur = nvLongueur;
}

//////////////FIN PARTIE PRIVÉÉ////////////////////////////////

//////////////PARTIE PUBLIC////////////////////////////////////


MOT_TableauDeMots MOT_tableauDeMotsVide() {

	MOT_TableauDeMots tabVide;

	tabVide.lesMots = (MOT_Mot*)malloc(sizeof(MOT_Mot) * Taille_Max_Tableau);
	MOT_fixerLongueurTabMots(&tabVide, 0);
	return tabVide;
}

int MOT_obtenirLongueurTabMots(MOT_TableauDeMots tableauMots) {
	return tableauMots.longueur;
}

MOT_Mot MOT_obtenirIemeMot(MOT_TableauDeMots tableauMots, int position) {
	assert(position < MOT_obtenirLongueurTabMots(tableauMots) && position >= 0);

	MOT_Mot* lesMots = MOT_obtenirLesMots(tableauMots);
	return lesMots[position];
}

void MOT_ajouterMot(MOT_TableauDeMots *tableauMots, MOT_Mot m) {

	assert(MOT_obtenirLongueurTabMots(*tableauMots) < Taille_Max_Tableau);

	int longueur = MOT_obtenirLongueurTabMots(*tableauMots);

	MOT_fixerLongueurTabMots(tableauMots, longueur + 1);
	MOT_fixerIemeMot(tableauMots, m, longueur);
}

void MOT_supprimerMot(MOT_Mot *m) {
	char *chaineASupprimer = MOT_motEnChaine(*m);
	MOT_fixerLongueurMot(m, -1);
	free(chaineASupprimer);
}

void MOT_supprimerDeuxMots(MOT_DeuxMots *deuxMots) {
	MOT_Mot motASupprimer = (*deuxMots).mot1;
	MOT_supprimerMot(&motASupprimer);

	motASupprimer = (*deuxMots).mot2;
	MOT_supprimerMot(&motASupprimer);
}

void MOT_supprimerTableauMots(MOT_TableauDeMots *tableau) {

	MOT_Mot motASupprimer, *lesMots;

	for (int i = 0; i < MOT_obtenirLongueurTabMots(*tableau); i++) {
		motASupprimer = MOT_obtenirIemeMot(*tableau, i);
		MOT_supprimerMot(&motASupprimer);
	}

	lesMots = MOT_obtenirLesMots(*tableau);
	MOT_fixerLongueurTabMots(tableau, -1);
	free(lesMots);
}

int MOT_estUneLettre(char c) {
	
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || (c == '-');
}

MOT_Mot MOT_creerMot(char *s) {
	assert(MOT_estUnMot(s));

	int longueurS = strlen(s);
	MOT_Mot mot;
	char *chaineMot;

	mot.chaine = (char*)malloc(sizeof(char) * (longueurS + 1));

	chaineMot = MOT_motEnChaine(mot);

	for (int i = 0; i < longueurS; i++) {
		chaineMot[i] = tolower(s[i]);
	}
	chaineMot[longueurS] = '\0';

	MOT_fixerLongueurMot(&mot, strlen(s));

	return mot;
}

int MOT_sontEgaux(MOT_Mot m1, MOT_Mot m2) {
	int i = 0, egaux = TRUE;

	if (MOT_longueurMot(m1) != MOT_longueurMot(m2)) {
		egaux = FALSE;
	}

	else {

		char *chaine1 = MOT_motEnChaine(m1);
		char *chaine2 = MOT_motEnChaine(m2);

		while (egaux && i < MOT_longueurMot(m1)) {

			if (chaine1[i] != chaine2[i]) {

				egaux = FALSE;
			}

			i++;
		}
	}

	return egaux;
}

int estAvantOrdreAlphabetique(MOT_Mot mot1, MOT_Mot mot2) {

	char *chaineMot1 = MOT_motEnChaine(mot1);
	char *chaineMot2 = MOT_motEnChaine(mot2);

	return (strcmp(chaineMot1, chaineMot2) < 0);

}

int MOT_estUnMot(char *chaine) {
	int estUnMot = TRUE;

	if (chaine == NULL || strlen(chaine) == 0) {
		estUnMot = FALSE;
	}

	else {
		for (int i = 0; i < strlen(chaine); i++) {
			if (!MOT_estUneLettre(chaine[i])) {
				estUnMot = FALSE;
			}
		}
	}
	return estUnMot;
}

char *MOT_motEnChaine(MOT_Mot m) {
	return m.chaine;
}

MOT_Mot MOT_remplacerLettre(MOT_Mot m, int pos, char c) {

	assert(pos < MOT_longueurMot(m) && pos >= 0 && MOT_estUneLettre(c));

	MOT_Mot nvMot;
	char *chaine = MOT_motEnChaine(m);
	char *nvChaine = (char*)malloc(sizeof(char) * (MOT_longueurMot(m) + 1));

	strcpy(nvChaine, chaine);
	nvChaine[pos] = c;
	nvMot = MOT_creerMot(nvChaine);

	free(nvChaine);
	return nvMot;
}

MOT_Mot MOT_supprimerLettre(MOT_Mot m, int pos) {

	assert(pos < MOT_longueurMot(m) && pos >= 0);

	MOT_Mot nvMot;
	char *chaine = MOT_motEnChaine(m);
	char *nvChaine = (char*)malloc(sizeof(char) * (MOT_longueurMot(m)));

	for (int i = 0; i < pos; i++) {
		nvChaine[i] = chaine[i];
	}

	for (int i = pos + 1; i < MOT_longueurMot(m) + 1; i++) {
		nvChaine[i - 1] = chaine[i];
	}

	nvMot = MOT_creerMot(nvChaine);

	free(nvChaine);
	return nvMot;
}

MOT_Mot MOT_insererLettre(MOT_Mot m, int pos, char c) {

	assert(0 <= pos && pos <= MOT_longueurMot(m) && MOT_estUneLettre(c));

	MOT_Mot nvMot;
	char *chaine = MOT_motEnChaine(m);
	char *nvChaine = (char*)malloc(sizeof(char) * (MOT_longueurMot(m) + 2));

	strcpy(nvChaine, chaine);

	for (int i = pos + 1; i <= MOT_longueurMot(m) + 1; i++) {
		nvChaine[i] = chaine[i - 1];
	}

	nvChaine[pos] = c;
	nvMot = MOT_creerMot(nvChaine);

	free(nvChaine);
	return nvMot;
}

MOT_Mot MOT_inverserLettre(MOT_Mot m, int pos) {

	assert(0 <= pos && pos < MOT_longueurMot(m) - 1);

	MOT_Mot nvMot;
	char *chaine = MOT_motEnChaine(m);
	char *nvChaine = (char*)malloc(sizeof(char) * (MOT_longueurMot(m) + 1));

	strcpy(nvChaine, chaine);

	nvChaine[pos] = chaine[pos + 1];
	nvChaine[pos + 1] = chaine[pos];

	nvMot = MOT_creerMot(nvChaine);

	free(nvChaine);
	return nvMot;
}

MOT_DeuxMots MOT_decomposerMot(MOT_Mot m, int pos) {

	assert(0 < pos && pos < MOT_longueurMot(m));

	MOT_DeuxMots nvMots;
	char *chaine = MOT_motEnChaine(m);
	char *nvChaine = (char*)malloc(sizeof(char) * (pos + 1));

	for (int i = 0; i < pos; i++) {
		nvChaine[i] = chaine[i];
	}

	nvChaine[pos] = '\0';
	nvMots.mot1 = MOT_creerMot(nvChaine);
	free(nvChaine);

	nvChaine = (char*)malloc(sizeof(char) * (MOT_longueurMot(m) - pos + 1));

	for (int i = pos; i <= MOT_longueurMot(m); ++i) {
		nvChaine[i - pos] = chaine[i];

	}

	nvMots.mot2 = MOT_creerMot(nvChaine);

	free(nvChaine);
	return nvMots;
}

void MOT_enleverSautDeLigne(char *chaine) {
	assert(strlen(chaine) >= 2);

	chaine[strlen(chaine) - 1] = '\0';
}