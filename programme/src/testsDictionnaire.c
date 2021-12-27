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
	DICTIONNAIRE_Dictionnaire dico, dictionnaireDesire, fg, fd, fgg, fdg, fdd, fgd;
	//Création du dictionnaire qui va être testé
	fgg = DICTIONNAIRE_dictionnaire(MOT_creerMot("chapeau"));
	fdg = DICTIONNAIRE_dictionnaire(MOT_creerMot("arbre"));
	fg = DICTIONNAIRE_dictionnaire(MOT_creerMot("lapin"));
	DICTIONNAIRE_fixerFilsGauche(&fg, fgg);
	DICTIONNAIRE_fixerFilsDroit(&fg, fdg);

	fd = DICTIONNAIRE_dictionnaire(MOT_creerMot("droite"));
	dico =DICTIONNAIRE_dictionnaire(MOT_creerMot("racine"));
	DICTIONNAIRE_fixerFilsGauche(&dico, fg);
	DICTIONNAIRE_fixerFilsDroit(&dico, fd);

	//Création du dictionnaire désiré en sortie
	fg = DICTIONNAIRE_dictionnaire(MOT_creerMot("chapeau"));

	fd = DICTIONNAIRE_dictionnaire(MOT_creerMot("racine"));
	fdd = DICTIONNAIRE_dictionnaire(MOT_creerMot("droite"));
	fgd = DICTIONNAIRE_dictionnaire(MOT_creerMot("arbre"));
	DICTIONNAIRE_fixerFilsGauche(&fd, fgd);
	DICTIONNAIRE_fixerFilsDroit(&fd, fdd);

	dictionnaireDesire = DICTIONNAIRE_dictionnaire(MOT_creerMot("lapin"));
	DICTIONNAIRE_fixerFilsGauche(&dictionnaireDesire, fg);
	DICTIONNAIRE_fixerFilsDroit(&dictionnaireDesire, fd);

	DICTIONNAIRE_simpleRotationDroite(&dico);

	CU_ASSERT_TRUE(dictionnaire_sontEgaux(dico, dictionnaireDesire));

	DICTIONNAIRE_supprimer(&dico);
	DICTIONNAIRE_supprimer(&dictionnaireDesire);
}

void test_simple_rotation_gauche(){
	DICTIONNAIRE_Dictionnaire dico, dictionnaireDesire, fg, fd, fgd, fdd, fgg, fdg;
	//création du dictionnaire qui va être testé
	fdd = DICTIONNAIRE_dictionnaire(MOT_creerMot("droite"));
	fgd = DICTIONNAIRE_dictionnaire(MOT_creerMot("arbre"));
	fd = DICTIONNAIRE_dictionnaire(MOT_creerMot("racine"));
	DICTIONNAIRE_fixerFilsDroit(&fd, fdd);
	DICTIONNAIRE_fixerFilsGauche(&fd, fgd);

	fg = DICTIONNAIRE_dictionnaire(MOT_creerMot("chapeau"));

	dico =DICTIONNAIRE_dictionnaire(MOT_creerMot("lapin"));
	DICTIONNAIRE_fixerFilsDroit(&dico, fd);
	DICTIONNAIRE_fixerFilsGauche(&dico, fg);

	//Création du dictionnaire désiré en sortie
	fd = DICTIONNAIRE_dictionnaire(MOT_creerMot("droite"));

	fg = DICTIONNAIRE_dictionnaire(MOT_creerMot("lapin"));
	fgg = DICTIONNAIRE_dictionnaire(MOT_creerMot("chapeau"));
	fdg = DICTIONNAIRE_dictionnaire(MOT_creerMot("arbre"));
	DICTIONNAIRE_fixerFilsGauche(&fg, fgg);
	DICTIONNAIRE_fixerFilsDroit(&fg, fdg);

	dictionnaireDesire = DICTIONNAIRE_dictionnaire(MOT_creerMot("racine"));
	DICTIONNAIRE_fixerFilsGauche(&dictionnaireDesire, fg);
	DICTIONNAIRE_fixerFilsDroit(&dictionnaireDesire, fd);

	DICTIONNAIRE_simpleRotationDroite(&dico);

	CU_ASSERT_TRUE(dictionnaire_sontEgaux(dico, dictionnaireDesire));

	DICTIONNAIRE_supprimer(&dico);
	DICTIONNAIRE_supprimer(&dictionnaireDesire);

}

void test_double_rotation_droite(){
	DICTIONNAIRE_Dictionnaire dico, dictionnaireDesire, fg, fd, fgg, fdg, fdd, fgd, fgdg, fddg;

	//Création du dictionnaire qui va être testé
	fgg = DICTIONNAIRE_dictionnaire(MOT_creerMot("chapeau"));
	fdg = DICTIONNAIRE_dictionnaire(MOT_creerMot("arbre"));
	fgdg = DICTIONNAIRE_dictionnaire(MOT_creerMot("draps"));
	fddg = DICTIONNAIRE_dictionnaire(MOT_creerMot("lampe"));
	fg = DICTIONNAIRE_dictionnaire(MOT_creerMot("lapin"));
	DICTIONNAIRE_fixerFilsGauche(&fdg, fgdg);
	DICTIONNAIRE_fixerFilsDroit(&fdg, fddg);
	DICTIONNAIRE_fixerFilsGauche(&fg, fgg);
	DICTIONNAIRE_fixerFilsDroit(&fg, fdg);

	fd = DICTIONNAIRE_dictionnaire(MOT_creerMot("droite"));
	dico =DICTIONNAIRE_dictionnaire(MOT_creerMot("racine"));
	DICTIONNAIRE_fixerFilsGauche(&dico, fg);
	DICTIONNAIRE_fixerFilsDroit(&dico, fd);

	//Création du dictionnaire désiré en sortie
	fgg = DICTIONNAIRE_dictionnaire(MOT_creerMot("chapeau"));
	fdg = DICTIONNAIRE_dictionnaire(MOT_creerMot("draps"));
	fg = DICTIONNAIRE_dictionnaire(MOT_creerMot("lapin"));
	DICTIONNAIRE_fixerFilsGauche(&fg, fgg);
	DICTIONNAIRE_fixerFilsDroit(&fg, fdg);

	fd = DICTIONNAIRE_dictionnaire(MOT_creerMot("racine"));
	fdd = DICTIONNAIRE_dictionnaire(MOT_creerMot("droite"));
	fgd = DICTIONNAIRE_dictionnaire(MOT_creerMot("lampe"));
	DICTIONNAIRE_fixerFilsGauche(&fd, fgd);
	DICTIONNAIRE_fixerFilsDroit(&fd, fdd);

	dictionnaireDesire = DICTIONNAIRE_dictionnaire(MOT_creerMot("arbre"));
	DICTIONNAIRE_fixerFilsGauche(&dictionnaireDesire, fg);
	DICTIONNAIRE_fixerFilsDroit(&dictionnaireDesire, fd);

	DICTIONNAIRE_simpleRotationDroite(&dico);

	CU_ASSERT_TRUE(dictionnaire_sontEgaux(dico, dictionnaireDesire));

	DICTIONNAIRE_supprimer(&dico);
	DICTIONNAIRE_supprimer(&dictionnaireDesire);
}

int test_double_rotation_gauche(){
	return 0;
}

void test_hauteur(){
	DICTIONNAIRE_Dictionnaire dictionnaire,filsgauche,filsdroit,filsgauchegauche;
	CU_ASSERT_TRUE(DICTIONNAIRE_hauteur(DICTIONNAIRE_dictionnaireVide())==0)

	DICTIONNAIRE_dictionnaire(MOT_creerMot("test"));
	CU_ASSERT_TRUE(DICTIONNAIRE_hauteur(dictionnaire)==1)

	filsgauche = DICTIONNAIRE_dictionnaire(MOT_creerMot("filsgauche"));
	DICTIONNAIRE_fixerFilsGauche(&dictionnaire,filsgauche);
	CU_ASSERT_TRUE(DICTIONNAIRE_hauteur(dictionnaire) == 2)

	filsgauchegauche = DICTIONNAIRE_dictionnaire(MOT_creerMot("filsgauchegauche"));
	DICTIONNAIRE_fixerFilsGauche(DICTIONNAIRE_obtenirFilsGauche(&dictionnaire),filsgauchegauche);
	CU_ASSERT_TRUE(DICTIONNAIRE_hauteur(dictionnaire)==3)

	filsdroit = DICTIONNAIRE_dictionnaire(MOT_creerMot("filsdroit"));
	DICTIONNAIRE_fixerFilsDroit(&dictionnaire,filsdroit);
	CU_ASSERT_TRUE(DICTIONNAIRE_hauteur(dictionnaire) == 3);
}

int test_reequilibrer(){
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
    DICTIONNAIRE_Dictionnaire dico = DICTIONNAIRE_dictionnaireVide();
    CU_ASSERT_TRUE(DICTIONNAIRE_estVide(dico));
}

void test_estPresent(void) {
    DICTIONNAIRE_Dictionnaire d = DICTIONNAIRE_dictionnaireVide();
    MOT_Mot mot1 = MOT_creerMot("Salut");
    MOT_Mot mot2 = MOT_creerMot("Salutation");

	CU_ASSERT_FALSE(DICTIONNAIRE_estPresent(d,mot1));
	CU_ASSERT_FALSE(DICTIONNAIRE_estPresent(d,mot2));


    DICTIONNAIRE_ajouterMot(&d, mot1);
    CU_ASSERT_TRUE(DICTIONNAIRE_estPresent(d, mot1));
    CU_ASSERT_FALSE(DICTIONNAIRE_estPresent(d, mot2));

    DICTIONNAIRE_ajouterMot(&d, mot2);
	CU_ASSERT_TRUE(DICTIONNAIRE_estPresent(d,mot1));
	CU_ASSERT_TRUE(DICTIONNAIRE_estPresent(d,mot2));
}

int main(int argc , char **argv){
	CU_pSuite pSuite = NULL;
	
 	/* initialisation du registre de tests */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error() ;

 	/* ajout d'une suite de test */
	pSuite = CU_add_suite("Tests boite noire ", init_suite_success, clean_suite_success) ;
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

