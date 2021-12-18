/**
 * \file dictionnaire.c
 * \brief Implémantation du TAD dictionnaire
 * \version 1.0
 * \date 03/01/2022
 *
 */
#include <string.h>
#include"dictionnaire.h"
#include"mot.h"
/*--------------Fonction Privé--------------------------*/
DICTIONNAIRE_Dictionnaire DICTIONNAIRE_dictionnaire(){
	return NULL ;
}


int DICTIONNAIRE_estVide(DICTIONNAIRE_Dictionnaire dictionnaire){
	return (dictionnaire==NULL);
}

DICTIONNAIRE_Dictionnaire DICTIONNAIRE_obtenirFilsGauche(DICTIONNAIRE_Dictionnaire dictionnaire){

}


DICTIONNAIRE_Dictionnaire DICTIONNAIRE_obtenirFilsDroit(DICTIONNAIRE_Dictionnaire dictionnaire){

}


MOT_Mot DICTIONNAIRE_obtenirMot(DICTIONNAIRE_Dictionnaire dictionnaire){
	assert(!(DICTIONNAIRE_estVide(dictionnaire))) ;
	
}

/*--------------Fonction Publique--------------------------*/

int DICTIONNAIRE_estPresent(DICTIONNAIRE_Dictionnaire dictionnaire, MOT_Mot mot){
	MOT_Mot motDico ;
	char *chaineAtester ;
	char *chaineDico ;
	if DICTIONNAIRE_estVide(dictionnaire){
		return 0 ;
	}
	else{
		motDico = DICTIONNAIRE_obtenirMot(dictionnaire)
		if MOT_sontEgaux(mot,motDico){
			return 1;
		}
		else{
			chaineAtester = mot.chaine //A changer avec la nouvelle fonction
			chaineDico = motDico.chaine //A changer aussi
			if (strcmp(chaineAtester, chaineDico)<0){
				return DICTIONNAIRE_estPresent(DICTIONNAIRE_obtenirFilsGauche(dictionnaire), mot) ;
			}
			else{
				return DICTIONNAIRE_estPresent(DICTIONNAIRE_obtenirFilsDroit(dictionnaire), mot) ;
			}
		}
	}
}




void DICTIONNAIRE_ajouterMot(DICTIONNAIRE_Dictionnaire *dictionnaire, MOT_Mot mot){}


void DICTIONNAIRE_ajouterFichier(DICTIONNAIRE_Dictionnaire *dictionnaire, char nomFichier){}


DICTIONNAIRE_Dictionnaire DICTIONNAIRE_chargerDictionnaire(char chaine){}


char *DICTIONNAIRE_enregistrerDictionnaire(DICTIONNAIRE_Dictionnaire dictionnaire){}
