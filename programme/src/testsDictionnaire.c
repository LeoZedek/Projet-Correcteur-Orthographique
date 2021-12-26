#include <stdio.h>
#include<stdlib.h>
#include<CUnit/Basic.h>
#include "correcteurOrthographique.h"
#include "mot.h"
#include "dictionnaire.h"
#include "dictionnairePrive.h"

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


void tester_max(void){
	CU_ASSERT_EQUAL( max(1,2),2);
	CU_ASSERT_EQUAL( max(2,1),2);
}
void tester_abs(void){
	CU_ASSERT_EQUAL( abs(1),1);
	CU_ASSERT_EQUAL( abs(-1),1);
}

int test_Dictionnaire_estPresent(DICTIONNAIRE_Dictionnaire dictionnaire, MOT_Mot mot){

   char *chaineAtester = "salut" ;
   char *chaineDico = "salutation";

	CU_ASSERT_FALSE(DICTIONNAIRE_estVide(dictionnaire));
	CU_ASSERT_EQUAL(chaineAtester, chaineDico);
	if (strcmp(chaineAtester, chaineDico)<0){
		return test_DICTIONNAIRE_estPresent( *DICTIONNAIRE_obtenirFilsGauche(&dictionnaire), mot) ;
	}
	else{
		return test_DICTIONNAIRE_estPresent( *DICTIONNAIRE_obtenirFilsDroit(&dictionnaire), mot) ;
	}
}


void  test_DICTIONNAIRE_ajouterMot(DICTIONNAIRE_Dictionnaire *dictionnaire, MOT_Mot mot){
	MOT_TableauDeMots tabMots = MOT_tableauDeMotsVide();
	MOT_Mot mot = MOT_creerMot("arbre");
	MOT_fixerLongueurTabMots(&tabMots, 1);
	tabMots.lesMots[0] = mot;
	MOT_TableauDeMots tabMotsTest = MOT_tableauDeMotsVide();
	MOT_ajouterMot(&tabMotsTest,mot);
	CU_ASSERT_TRUE(sontEgauxMots(tabMots, tabMotsTest));
	MOT_supprimerTableauMots(&tabMots);
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
		|| (NULL == CU_add_test(pSuite, "Test presence", test_Dictionnaire_estPresent))
		|| (NULL == CU_add_test(pSuite, "Test ajouter", test_DICTIONNAIRE_ajouterMot))
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

