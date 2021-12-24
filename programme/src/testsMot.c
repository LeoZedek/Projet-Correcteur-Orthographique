#include<stdlib.h>
#include<CUnit/Basic.h>
#include"mot.h"
#include"motPrivee.h"
#include"correcteurOrthographique.h"
#define TRUE 1
#define FALSE 0

int init_suite_success(void) { 
  return 0; 
}

int clean_suite_success(void) { 
  return 0; 
}


int sontEgauxMots(MOT_TableauDeMots motsGeneres, MOT_TableauDeMots motsVerifies){
  int i;
  int egaux = TRUE;
  if (MOT_obtenirLongueurTabMots(motsGeneres) != MOT_obtenirLongueurTabMots(motsVerifies)) {
    egaux = FALSE;
  }
  else {
    for (i=0; i < MOT_obtenirLongueurTabMots(motsGeneres); i++){
      if (!MOT_sontEgaux(MOT_obtenirIemeMot(motsGeneres, i), MOT_obtenirIemeMot(motsVerifies, i))) {
        egaux = FALSE;
      }
    }   
  }

  return egaux;
}


void test_MOT_ajouterMot(void){
	MOT_TableauDeMots tabMots = MOT_tableauDeMotsVide();
	MOT_Mot m = MOT_creerMot("papillon");
	MOT_fixerLongueurTabMots(&tabMots, 1);
	tabMots.lesMots[0] = MOT_copierMot(m);
	MOT_TableauDeMots tabMotsTest = MOT_tableauDeMotsVide();
	MOT_ajouterMot(&tabMotsTest,m);
	CU_ASSERT_TRUE(sontEgauxMots(tabMots, tabMotsTest));

	MOT_supprimerMot(&m);
	MOT_supprimerTableauMots(&tabMots);
	MOT_supprimerTableauMots(&tabMotsTest);
}


void test_MOT_estUneLettre(void){
	char lettre = 'a';
	char nonlettre = '&';
	CU_ASSERT_TRUE(MOT_estUneLettre(lettre));
	CU_ASSERT_FALSE(MOT_estUneLettre(nonlettre));
}


void test_MOT_estUnMot(void){
	char mot[] = "papillon";
	char etrange[] = "ji3&jp";
	CU_ASSERT_TRUE(MOT_estUnMot(mot));
	CU_ASSERT_FALSE(MOT_estUnMot(etrange));
}

void test_MOT_sontEgaux(void){
	MOT_Mot mot1 = MOT_creerMot("papillon");
	MOT_Mot mot2 = MOT_creerMot("papillon");
	MOT_Mot mot3 = MOT_creerMot("carottes");

	CU_ASSERT_TRUE(MOT_sontEgaux(mot1, mot2));
	CU_ASSERT_FALSE(MOT_sontEgaux(mot1, mot3));
}


void test_MOT_remplacerLettre(void){
	MOT_Mot mot1 = MOT_creerMot("papillon");
	MOT_Mot mot2 = MOT_creerMot("papellon");
	MOT_Mot mot3 = MOT_remplacerLettre(mot2,3, 'i');
	CU_ASSERT_TRUE(MOT_sontEgaux(mot1, mot3));
}


void test_MOT_supprimerLettre(void){
	MOT_Mot mot1 = MOT_creerMot("papillon");
	MOT_Mot mot2 = MOT_creerMot("papllon");
	MOT_Mot mot3 = MOT_supprimerLettre(mot1,3);
	CU_ASSERT_TRUE(MOT_sontEgaux(mot2, mot3));
}



void test_MOT_insererLettre(void){
	MOT_Mot mot1 = MOT_creerMot("papillon");
	MOT_Mot mot2 = MOT_creerMot("papllon");
	MOT_Mot mot3 = MOT_insererLettre(mot2,3,'i');
	CU_ASSERT_TRUE(MOT_sontEgaux(mot1, mot3));
}


void test_MOT_inverserLettre(void){
	MOT_Mot mot1 = MOT_creerMot("papillon");
	MOT_Mot mot2 = MOT_creerMot("paipllon");
	MOT_Mot mot3 = MOT_inverserLettre(mot2,2);
	CU_ASSERT_TRUE(MOT_sontEgaux(mot1, mot3));
}


void test_MOT_decomposerMot(void){
	MOT_Mot mot = MOT_creerMot("papillon");
	MOT_DeuxMots motsAObtenir;
	motsAObtenir.mot1 = MOT_creerMot("papi");
	motsAObtenir.mot2 = MOT_creerMot("llon");
	MOT_DeuxMots motsATester = MOT_decomposerMot(mot,4);
	CU_ASSERT_TRUE(MOT_sontEgaux(motsAObtenir.mot1,motsATester.mot1) && MOT_sontEgaux(motsAObtenir.mot2,motsATester.mot2));
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : mot", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "a est une lettre et & n'est pas une lettre : ",test_MOT_estUneLettre))
      || (NULL == CU_add_test(pSuite, "ajout d'un mot", test_MOT_ajouterMot)) 
       || (NULL == CU_add_test(pSuite, "papillon est un mot et ji3&jp ne l'est pas ", test_MOT_estUnMot)) 
        || (NULL == CU_add_test(pSuite, "papillon et papillon sont égaux mais papillon et carottes ne le sont pas", test_MOT_sontEgaux)) 
         || (NULL == CU_add_test(pSuite, "remplacement d'une lettre", test_MOT_remplacerLettre)) 
          || (NULL == CU_add_test(pSuite, "suppression d'une lettre", test_MOT_supprimerLettre)) 
           || (NULL == CU_add_test(pSuite, "insertion d'une lettre", test_MOT_insererLettre)) 
            || (NULL == CU_add_test(pSuite, "inversion de deux lettres", test_MOT_inverserLettre)) 
             || (NULL == CU_add_test(pSuite, "décomposition d'un mot en 2 mots", test_MOT_decomposerMot)) 
      ) 
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}

