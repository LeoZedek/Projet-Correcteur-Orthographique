#include<stdlib.h>
#include<CUnit/Basic.h>
#include"mot.h"
#include"dictionnaire.h"
#include"correcteurOrthographique.h"
#define TRUE 1
#define FALSE 0

int init_suite_success(void) { 
  return 0; 
}

int clean_suite_success(void) { 
  return 0; 
}



int estPresentTabMot(MOT_TableauDeMots tab, MOT_Mot m) {
  int longueur = MOT_obtenirLongueurTabMots(tab);
  int i = 0, resultat = FALSE;
  MOT_Mot motDuTab;

  while (!resultat && i < longueur) {
    motDuTab = MOT_obtenirIemeMot(tab, i);
    if (MOT_sontEgaux(m, motDuTab)) {
      resultat = TRUE;
    }
    i++;
  }

  return resultat;
}

int sontEgauxEntiers(CO_TableauDEntiers entierGeneres, CO_TableauDEntiers entierVerifies){
  int i = 0;
  int egaux = TRUE;

  if (CO_obtenirLongueurTabEntiers(entierGeneres) != CO_obtenirLongueurTabEntiers(entierVerifies)) {
    egaux = FALSE;
  }
  else {
    while (egaux && i < CO_obtenirLongueurTabEntiers(entierGeneres)) {
      if (CO_obtenirIemeEntier(entierGeneres, i) != CO_obtenirIemeEntier(entierVerifies, i)) {
        egaux = FALSE;
      }
      i++;
    }   
  }

  return egaux;
}

int sontEgauxMots(MOT_TableauDeMots motsGeneres, MOT_TableauDeMots motsVerifies){
  int i = 0;
  int egaux = TRUE;
  if (MOT_obtenirLongueurTabMots(motsGeneres) != MOT_obtenirLongueurTabMots(motsVerifies)) {
    egaux = FALSE;
  }
  else {
    while (egaux && i < MOT_obtenirLongueurTabMots(motsGeneres)) {
      if (!MOT_sontEgaux(MOT_obtenirIemeMot(motsGeneres, i), MOT_obtenirIemeMot(motsVerifies, i))) {
        egaux = FALSE;
      }

      i++;
    }   
  }

  return egaux;
}

void test_sontPresents(void)
{
  DICTIONNAIRE_Dictionnaire dico = DICTIONNAIRE_dictionnaireVide();

  MOT_Mot m = MOT_creerMot("test");
  DICTIONNAIRE_ajouterMot(&dico, m);

  m = MOT_creerMot("correction");
  DICTIONNAIRE_ajouterMot(&dico, m);

  m = MOT_creerMot("dromadaire");
  DICTIONNAIRE_ajouterMot(&dico, m);

  m = MOT_creerMot("fautes");
  DICTIONNAIRE_ajouterMot(&dico, m);

  MOT_TableauDeMots mots;
  CO_TableauBooleens booleenCorrects, booleenGeneres;

  mots = MOT_tableauDeMotsVide();
  booleenCorrects = CO_tableauDEntiersVide();
  
  m = MOT_creerMot("test");
  MOT_ajouterMot(&mots, m);
  MOT_supprimerMot(&m);

  m = MOT_creerMot("correction");
  MOT_ajouterMot(&mots, m);
  MOT_supprimerMot(&m);

  m = MOT_creerMot("dromadaire");
  MOT_ajouterMot(&mots, m);
  MOT_supprimerMot(&m);

  m = MOT_creerMot("foutes");
  MOT_ajouterMot(&mots, m);
  MOT_supprimerMot(&m);

  CO_ajouterEntier(&booleenCorrects, TRUE);
  CO_ajouterEntier(&booleenCorrects, TRUE);
  CO_ajouterEntier(&booleenCorrects, TRUE);
  CO_ajouterEntier(&booleenCorrects, FALSE);
  
  booleenGeneres = CO_sontPresents(mots, dico);
  
  CU_ASSERT_TRUE(sontEgauxEntiers(booleenGeneres,booleenCorrects));

  MOT_supprimerTableauMots(&mots);
  CO_supprimerTableauEntiers(&booleenCorrects);
  CO_supprimerTableauEntiers(&booleenGeneres);

  DICTIONNAIRE_supprimer(&dico);

}



void test_proposerMots(void){

  DICTIONNAIRE_Dictionnaire dico;
  MOT_TableauDeMots motsGeneres, motsProposes;

  dico = DICTIONNAIRE_dictionnaireVide();
  motsProposes = MOT_tableauDeMotsVide();

  char *chaines[] = {"fia", "fait", "fais", "faim", "frai", "fiai", "fax", "fat", "far", "fui", "foi", "rai", "mai", "lai", "gai", "bai"};
  
  MOT_Mot m, motPropose;
  for (int i = 0; i < 16; i++) {
    m = MOT_creerMot(chaines[i]);
    DICTIONNAIRE_ajouterMot(&dico, m);
    MOT_ajouterMot(&motsProposes, m);
  }
  m = MOT_creerMot("fai");
  motsGeneres = CO_proposerMots(m, dico);

  CU_ASSERT_TRUE(MOT_obtenirLongueurTabMots(motsGeneres) == 16);

  for (int i = 0; i < 16; i++) {
    motPropose = MOT_obtenirIemeMot(motsProposes, i);
    CU_ASSERT_TRUE(estPresentTabMot(motsGeneres, motPropose)); 
  }

  MOT_supprimerTableauMots(&motsProposes);
  MOT_supprimerTableauMots(&motsGeneres);
  DICTIONNAIRE_supprimer(&dico);
}



void test_phraseEnMots(void)
{
  char *phrase = " bonjour  je:#suis,#une#'pizza";

  CO_MotsDansPhrase motsEtPositions;
  motsEtPositions = CO_phraseEnMots(phrase);

  MOT_TableauDeMots motsExacts = MOT_tableauDeMotsVide();
  CO_TableauPositions positionsExactes = CO_tableauDEntiersVide();

  MOT_ajouterMot(&motsExacts, MOT_creerMot("bonjour"));
  MOT_ajouterMot(&motsExacts, MOT_creerMot("je"));
  MOT_ajouterMot(&motsExacts, MOT_creerMot("suis"));
  MOT_ajouterMot(&motsExacts, MOT_creerMot("une"));
  MOT_ajouterMot(&motsExacts, MOT_creerMot("pizza"));

  CO_ajouterEntier(&positionsExactes, 1);
  CO_ajouterEntier(&positionsExactes, 10);
  CO_ajouterEntier(&positionsExactes, 14);
  CO_ajouterEntier(&positionsExactes, 20);
  CO_ajouterEntier(&positionsExactes, 25);


  CU_ASSERT_TRUE(sontEgauxMots(motsEtPositions.mots, motsExacts) && sontEgauxEntiers(motsEtPositions.positions, positionsExactes));

  MOT_supprimerTableauMots(&motsExacts);
  CO_supprimerTableauEntiers(&positionsExactes);
  CO_supprimerMotsEtPositions(&motsEtPositions);
}

void test_ajouterEntier(void)
{
  CO_TableauDEntiers tabExacts = CO_tableauDEntiersVide();
  CO_TableauDEntiers tabTest = CO_tableauDEntiersVide();

  CO_fixerLongueurTabEntiers(&tabExacts, 3);
  int *lesEntiersExacts = CO_obtenirLesEntiers(tabExacts);
  lesEntiersExacts[0] = 1;
  lesEntiersExacts[1] = 2;
  lesEntiersExacts[2] = 3;

  CO_ajouterEntier(&tabTest, 1);
  CO_ajouterEntier(&tabTest, 2);
  CO_ajouterEntier(&tabTest, 3);

  CU_ASSERT_TRUE(sontEgauxEntiers(tabTest, tabExacts));

  CO_supprimerTableauEntiers(&tabTest);
  CO_supprimerTableauEntiers(&tabExacts);

}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : correcteur orthographique", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "mots sont présents", test_sontPresents))
      || (NULL == CU_add_test(pSuite, "proposition de mots", test_proposerMots))
      || (NULL == CU_add_test(pSuite, "découpage d'une phrase en mots", test_phraseEnMots)) 
      || (NULL == CU_add_test(pSuite, "Ajout d'un entier", test_ajouterEntier)) 
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

