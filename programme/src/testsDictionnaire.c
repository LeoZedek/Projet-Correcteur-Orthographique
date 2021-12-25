#include <stdio.h>
#include<stdlib.h>
#include<CUnit/Basic.h>
#include "correcteurOrthographique.h"
#include "mot.h"
#include "dictionnaire.h"

#define TRUE 1
#define FALSE 0

//CU initialize registry() initialiser le registre de tests
//CU add suite() ajouter tests au registre
//CU add test() ajouter tests a une suite de tests

int init_suite_success(void) { 
  return 0; 
}

int clean_suite_success(void) { 
  return 0; 
}

struct dict{
   struct dict* left, *right;
   char mot[10];
}


void tester_max(void){
   CU_ASSERT_EQUAL( max(1,2),2);
   CU_ASSERT_EQUAL( max(2,1),2);
}
void tester_abs(void){
   CU_ASSERT_EQUAL( abs(1),1);
   CU_ASSERT_EQUAL( abs(-1),1);
}

void test_Dictionnaire_estPresent(Dictionnaire dictionnaire, Mot mot){

   char *chaineAtester = "salut" ;
   char *chaineDico = "salutation";

   if (CU_ASSERT_FALSE(DICTIONNAIRE_estVide(dictionnaire))){
		return 0 ;
	}
   else{
		
		if (CU_ASSERT_EQUAL(chaineAtester, chaineDico)){
			return 1;
		}
		else{
			
			if (strcmp(chaineAtester, chaineDico)<0){
				return test_DICTIONNAIRE_estPresent(*DICTIONNAIRE_obtenirFilsGauche(&dictionnaire), mot) ;
			}
			else{
				return test_DICTIONNAIRE_estPresent(*DICTIONNAIRE_obtenirFilsDroit(&dictionnaire), mot) ;
			}
		}
	}


void  test_DICTIONNAIRE_ajouterMot(DICTIONNAIRE_Dictionnaire *dictionnaire, Mot mot);
	MOT_TableauDeMots tabMots = MOT_tableauDeMotsVide();
	MOT_Mot mot = MOT_creerMot("arbre");
	MOT_fixerLongueurTabMots(&tabMots, 1);
	tabMots.lesMots[0] = mot;
	MOT_TableauDeMots tabMotsTest = MOT_tableauDeMotsVide();
	MOT_ajouterMot(&tabMotsTest,mot);
	CU_ASSERT_TRUE(sontEgauxMots(tabMots, tabMotsTest));
	MOT_supprimerTableauMots(tabMots);
}



 int main(int argc , char∗∗ argv){
 CU_pSuite pSuite = NULL;
 
 /* initialisation du registre de tests */
 if (CUE_SUCCESS != CU initialize registry())
 return CU get error () ;

 /* ajout d'une suite de test */
 pSuite = CU add suite(”Tests boite noire ”, init suite success , clean suite success ) ;
 if (NULL == pSuite) {
 CU cleanup registry () ;
 return CU get error () ;
 }

 /* Ajout des tests à la suite de tests boite noire */
 if ((NULL == CU add test(pSuite, ”Test max”, tester_max))
  ||((NULL == CU add test(pSuite, ”tester abs”, tester_abs))
  || (NULL == CU add test(pSuite, ”Test presence”, test_Dictionnaire_estPresent))
  || (NULL == CU add test(pSuite, ”Test ajouter”, est_DICTIONNAIRE_ajouterMot))
  ) {
   CU cleanup registry () ;
   return CU get error () ;
}

 /* Lancement des tests */
 CU basic set mode(CU BRM VERBOSE);
 CU basic run tests () ;
 printf (”\n”);
  CU basic show failures ( CU get failure list ()) ;
 printf (”\n\n”);

 /* Nettoyage du registre */
 CU cleanup registry () ;
 return CU get error () ;
 }

