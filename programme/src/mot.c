#include"mot.h"
#include"correcteurOrthographique.h"
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#define Taille_Max_Tableau 10000
#define Taille_Max_Mot 500
#define TRUE 1
#define FALSE 0

MOT_TableauDeMots MOT_tableauDeMotsVide() {

	MOT_TableauDeMots tabVide;

	tabVide.lesMots = (MOT_Mot*)malloc(sizeof(MOT_Mot) * Taille_Max_Tableau);
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

	assert(MOT_obtenirLongueurTabMots(*tableauMots) < Taille_Max_Tableau);

	int longueur = MOT_obtenirLongueurTabMots(*tableauMots);
	MOT_Mot *lesMots = MOT_obtenirLesMots(*tableauMots);

	lesMots[longueur] = m;
	MOT_fixerLongueurTabMots(tableauMots, longueur + 1);

}

void MOT_supprimerMot(MOT_Mot *m) {
	MOT_fixerLongueurMot(m, -1);
	free((*m).chaine);
}

void MOT_supprimerTableauMots(MOT_TableauDeMots *tableau) {

	MOT_Mot motASupprimer;

	for (int i = 0; i < MOT_obtenirLongueurTabMots(*tableau); i++) {
		motASupprimer = MOT_obtenirIemeMot(*tableau, i);
		MOT_supprimerMot(&motASupprimer);
	}

	MOT_fixerLongueurTabMots(tableau, -1);
	free((*tableau).lesMots);
}

int MOT_estUneLettre(char c) {
	
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || (c == '-');
}

MOT_Mot MOT_creerMot(char *chaine) {
	assert(MOT_estUnMot(chaine) && strlen(chaine) < Taille_Max_Mot);

	MOT_Mot mot;

	mot.chaine = (char*)malloc(sizeof(char) * Taille_Max_Mot);
	strcpy(mot.chaine, chaine);
	MOT_fixerLongueurMot(&mot, strlen(chaine));

	return mot;
}

unsigned int MOT_longueurMot(MOT_Mot mot) {
	return mot.longueur;
}

char *MOT_motEnChaine(MOT_Mot m) {
	return m.chaine;
}

int MOT_sontEgaux(MOT_Mot m1, MOT_Mot m2) {
	int egaux = TRUE;

	if (MOT_longueurMot(m1) != MOT_longueurMot(m2)) {
		egaux = FALSE;
	}

	else {

		char *chaine1 = MOT_motEnChaine(m1);
		char *chaine2 = MOT_motEnChaine(m2);

		for (int i = 0; i < MOT_longueurMot(m1); i++) {

			if (chaine1[i] != chaine2[i]) {

				egaux = FALSE;
			}
		}
	}

	return egaux;
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

void MOT_fixerLongueurMot(MOT_Mot *m, unsigned int nvLongueur) {
	(*m).longueur = nvLongueur;
}


MOT_Mot MOT_remplacerLettre(MOT_Mot m, int pos, char c) {

	assert(pos < MOT_longueurMot(m) && pos >= 0 && MOT_estUneLettre(c));

	MOT_Mot nvMot;
	char *chaine = MOT_motEnChaine(m);

	chaine[pos] = c;
	nvMot = MOT_creerMot(chaine);

	return nvMot;
}

MOT_Mot MOT_supprimerLettre(MOT_Mot m, int pos) {

	assert(pos < MOT_longueurMot(m) && pos >= 0);

	MOT_Mot nvMot;
	char *chaine = MOT_motEnChaine(m);
	char nvChaine[Taille_Max_Mot];
	strcpy(nvChaine, chaine);

	for (int i = pos; i < MOT_longueurMot(m); i++) {
		nvChaine[i] = chaine[i + 1];
	}

	nvMot = MOT_creerMot(nvChaine);

	return nvMot;
}

MOT_Mot MOT_insererLettre(MOT_Mot m, int pos, char c) {

	assert(0 <= pos && pos <= MOT_longueurMot(m) && MOT_estUneLettre(c));

	MOT_Mot nvMot;
	char *chaine = MOT_motEnChaine(m);
	char nvChaine[Taille_Max_Mot];
	strcpy(nvChaine, chaine);

	for (int i = pos + 1; i <= MOT_longueurMot(m) + 1; i++) {
		nvChaine[i] = chaine[i - 1];
	}

	nvChaine[pos] = c;
	nvMot = MOT_creerMot(nvChaine);

	return nvMot;
}

MOT_Mot MOT_inverserLettre(MOT_Mot m, int pos) {

	assert(0 <= pos && pos < MOT_longueurMot(m) - 1);

	MOT_Mot nvMot;
	char *chaine = MOT_motEnChaine(m);
	char nvChaine[Taille_Max_Mot];
	strcpy(nvChaine, chaine);

	nvChaine[pos] = chaine[pos + 1];
	nvChaine[pos + 1] = chaine[pos];

	nvMot = MOT_creerMot(nvChaine);

	return nvMot;
}

MOT_DeuxMots MOT_decomposerMot(MOT_Mot m, int pos) {

	assert(0 < pos && pos < MOT_longueurMot(m));

	MOT_DeuxMots nvMots;
	char *chaine = MOT_motEnChaine(m);
	char nvChaine[Taille_Max_Mot];

	strcpy(nvChaine, chaine);
	nvChaine[pos] = '\0';
	nvMots.mot1 = MOT_creerMot(nvChaine);

	for (int i = pos; i <= MOT_longueurMot(m); ++i) {
		nvChaine[i - pos] = chaine[i];

	}

	nvMots.mot2 = MOT_creerMot(nvChaine);

	return nvMots;
}

//Ce qu'il reste à faire : tout mettre en allocation dynamique et mettre les free (supprimer) dans les tests.