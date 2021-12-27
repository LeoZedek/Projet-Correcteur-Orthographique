#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "correcteurOrthographique.h"
#include "mot.h"
#include "dictionnaire.h"
#include "dictionnairePrive.h"
#include "motPrivee.h"

#define TRUE 1
#define FALSE 0

//CU_initialize_registry() initialiser le registre de tests
//CU_add_suite() ajouter tests au registre
//CU_add_test() ajouter tests a une suite de tests

int init_suite_success(void) {
	return 0;
}

int clean_suite_success(void) { 
	return 0; 
}
int dictionnaire_sontEgaux(DICTIONNAIRE_Dictionnaire dico1, DICTIONNAIRE_Dictionnaire dico2){
	if(!(dico1) && !(dico2)){
		return TRUE;
	}
	else if (!(dico1) && dico2){
		return FALSE;
	}
	else if (dico1 && !(dico2)){
		return FALSE;
	}
	else if (MOT_sontEgaux(DICTIONNAIRE_obtenirMot(dico1),DICTIONNAIRE_obtenirMot(dico2))){
		return ((dictionnaire_sontEgaux(*DICTIONNAIRE_obtenirFilsGauche(&dico1), *DICTIONNAIRE_obtenirFilsGauche(&dico2))) 
			&&(dictionnaire_sontEgaux(*DICTIONNAIRE_obtenirFilsDroit(&dico1),*DICTIONNAIRE_obtenirFilsDroit(&dico2))));
	}
	else{
		return FALSE;
	}

}
void test_simple_rotation_droite(){
	DICTIONNAIRE_Dictionnaire dico, dictionnaireDesire, fg, fd, fgg;
	fgg = DICTIONNAIRE_dictionnaire(MOT_creerMot("chapeau"));
	fg = DICTIONNAIRE_dictionnaire(MOT_creerMot("lapin"));
	DICTIONNAIRE_fixerFilsGauche(&fg, fgg);

	dico =DICTIONNAIRE_dictionnaire(MOT_creerMot("racine"));
	DICTIONNAIRE_fixerFilsGauche(&dico, fg);

	fg = DICTIONNAIRE_dictionnaire(MOT_creerMot("chapeau"));
	fd = DICTIONNAIRE_dictionnaire(MOT_creerMot("racine"));
	dictionnaireDesire = DICTIONNAIRE_dictionnaire(MOT_creerMot("lapin"));
	DICTIONNAIRE_fixerFilsGauche(&dictionnaireDesire, fg);
	DICTIONNAIRE_fixerFilsDroit(&dictionnaireDesire, fd);

	DICTIONNAIRE_simpleRotationDroite(&dico);

	CU_ASSERT_TRUE(dictionnaire_sontEgaux(dico, dictionnaireDesire));

	DICTIONNAIRE_supprimer(&dico);
	DICTIONNAIRE_supprimer(&dictionnaireDesire);
}

void test_simple_rotation_gauche(){
	DICTIONNAIRE_Dictionnaire dico, dictionnaireDesire, fg, fd, fdd;
	fdd = DICTIONNAIRE_dictionnaire(MOT_creerMot("chapeau"));
	fd = DICTIONNAIRE_dictionnaire(MOT_creerMot("lapin"));
	DICTIONNAIRE_fixerFilsDroit(&fd, fdd);

	dico =DICTIONNAIRE_dictionnaire(MOT_creerMot("racine"));
	DICTIONNAIRE_fixerFilsDroit(&dico, fd);

	fd = DICTIONNAIRE_dictionnaire(MOT_creerMot("chapeau"));
	fg = DICTIONNAIRE_dictionnaire(MOT_creerMot("racine"));
	dictionnaireDesire = DICTIONNAIRE_dictionnaire(MOT_creerMot("lapin"));
	DICTIONNAIRE_fixerFilsGauche(&dictionnaireDesire, fg);
	DICTIONNAIRE_fixerFilsDroit(&dictionnaireDesire, fd);

	DICTIONNAIRE_simpleRotationDroite(&dico);

	CU_ASSERT_TRUE(dictionnaire_sontEgaux(dico, dictionnaireDesire));

	DICTIONNAIRE_supprimer(&dico);
	DICTIONNAIRE_supprimer(&dictionnaireDesire);

}

int test_double_rotation_droite(){
	return 0;
}

int test_double_rotation_gauche(){
	return 0;
}

int test_hauteur(){
	int resultat = TRUE;
	DICTIONNAIRE_Dictionnaire dictionnaire,filsgauche,filsdroit,filsgauchegauche;
	if (DICTIONNAIRE_hauteur(DICTIONNAIRE_dictionnaireVide())!=0){
		resultat = FALSE;
	}

	DICTIONNAIRE_dictionnaire(MOT_creerMot("test"));
	if (DICTIONNAIRE_hauteur(dictionnaire)!=1){
		resultat = FALSE;
	}

	filsgauche = DICTIONNAIRE_dictionnaire(MOT_creerMot("filsgauche"));
	DICTIONNAIRE_fixerFilsGauche(&dictionnaire,filsgauche);
	if(DICTIONNAIRE_hauteur(dictionnaire) != 2){
		resultat = FALSE;
	}

	filsgauchegauche = DICTIONNAIRE_dictionnaire(MOT_creerMot("filsgauchegauche"));
	DICTIONNAIRE_fixerFilsGauche(DICTIONNAIRE_obtenirFilsGauche(&dictionnaire),filsgauchegauche);
	if (DICTIONNAIRE_hauteur(dictionnaire)!=3){
		resultat = FALSE;
	}

	filsdroit = DICTIONNAIRE_dictionnaire(MOT_creerMot("filsdroit"));
	DICTIONNAIRE_fixerFilsDroit(&dictionnaire,filsdroit);
	if (DICTIONNAIRE_hauteur(dictionnaire) != 3){
		resultat = FALSE;
	}

	return resultat;
}

int test_reequilibrer(){
	return 0;
}

int test_estPresent(){
	return 0;
}

int test_ajouterMot(){
	return 0;
}

int test_chargerDico(){
	return 0;
}

int test_enregistrerDico(){
	return 0;
}

int test_ajouterFichier(){
	return 0;
}


void tester_max(void){
	CU_ASSERT_EQUAL( max(1,2),2);
	CU_ASSERT_EQUAL( max(2,1),2);
}
void tester_abs(void){
	CU_ASSERT_EQUAL( abs(1),1);
	CU_ASSERT_EQUAL( abs(-1),1);
}

void test_estVide(void) {
    DICTIONNAIRE_Dictionnaire dico = Dictionnaire_dictionnaire();
    CU_ASSERT_TRUE(Dictionnaire_estVide(dico));
}

int main(int argc , char **argv){
	CU_pSuite pSuite = NULL;
	
 	/* initialisation du registre de tests */
	if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error() ;

 	/* ajout d'une suite de test */
	pSuite = CU_add_suite("Tests boite noire ", init_suite_success() , clean_suite_success() ) ;
	if (NULL == pSuite){
	CU_cleanup_registry();
	return CU_get_error();
	}

	/* Ajout des tests à la suite de tests boite noire */
	if ((NULL == CU_add_test(pSuite, "Test max", tester_max))
		||((NULL == CU_add_test(pSuite, "tester abs", tester_abs))
		)) {
			CU_cleanup_registry() ;
			return CU_get_error() ;
	}

	/* Lancement des tests */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf ("\n");
	CU_basic_show_failures (CU_get_failure_list()) ;
	printf ("\n\n");

 /* Nettoyage du registre */
	CU_cleanup_registry() ;
	return CU_get_error() ;
}

