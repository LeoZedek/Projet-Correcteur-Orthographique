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

struct dictionnaire{
   struct * left, *right;
   char mot[10];
}
*root = NULL;

typedef struct Dictionaire dictionnaire;

void test_Dictionnaire_estPresent(Dictionnaire dictionnaire, Mot mot){

  DICTIONNAIRE_Dictionnaire dico;

  MOT_Mot m = creerMot("test");
  DICTIONNAIRE_ajouterMot(&dico, m);

  MOT_TableauDeMots mots;
  CO_TableauBooleens booleenCorrects, booleenGeneres;

  mots = MOT_tableauDeMotsVide();
  booleenCorrects = CO_tableauDEntiersVide();
  booleenGeneres = CO_tableauDEntiersVide();
  CO_ajouterEntier(&booleenCorrects, FALSE);
  
  booleenGeneres = CO_sontPresents(mots, dico);
  
  CU_ASSERT_TRUE(sontEgauxEntiers(booleenGeneres,booleenCorrects));

  MOT_supprimerTableauMots(mots);
  CO_supprimerTableauEntiers(booleenCorrects);
  CO_supprimerTableauEntiers(booleenGeneres);



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



/*Dictionaire DICTIONNAIRE_obtenirFilsGauche(Dictionnaire dictionnaire);
Dictionaire DICTIONNAIRE_obtenirFilsDroit(Dictionnaire dictionnaire);
//DICTIONNAIRE_Dictionnaire 
//DICTIONNAIRE_dictionnaireVide();

  if estVide(dictionnaire){
      return test_estPresent(CO_obtenirFilsGauche(dictionnaire, mot));
  }
  else {
      return test_estPresent(CO_obtenirFilsDroite(dictionnaire, mot));
  }
 }*/


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
 if ((NULL == CU add test(pSuite, ”Test presence”, test_Dictionnaire_estPresent))
  || (NULL == CU add test(pSuite, ”Test ajouter”, est_DICTIONNAIRE_ajouterMot))) {
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

