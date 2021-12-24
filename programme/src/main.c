#include<stdio.h>
#include<string.h>
#include"correcteurOrthographique.h"
#include"dictionnaire.h"
#include"mot.h"

#define TAILLEMAX 10000
void afficherAide(){
	printf("Aide de asispell :\n");
	printf("\t asispell -h : cette aide\n");
	printf("\t asispell -d dico : correction de l'entree standard a l'aide du dictionnaire dico\n");
	printf("\t asispell -d dico -f fic : completer le dictionnaire dico a l'aide des mots du fichier fic (un mot par ligne)\n");
}


char *saisirChaine(char *lpBuffer, size_t nBufSize){//code trouver sur internet permettant de transformer une ligne de l'entrée standard en chaine de caractère
	//source : https://melem.developpez.com/tutoriels/langage-c/initiation-langage-c/?page=es
	size_t nbCar = 0 ;
	int c;
	c = getchar();
	while(nbCar < nBufSize - 1 && c!=EOF && c != '\n'){
		lpBuffer[nbCar]=(char)c;
		nbCar++;
		c = getchar();
	}
	lpBuffer[nbCar]='\0';
	return lpBuffer;
}


int main(int argc, char **argv){	
	char *nomDictionnaire,*nomFichier ;
	char chaineEntree[TAILLEMAX];
	CO_MotsDansPhrase tableauMotDansPhrase;
	DICTIONNAIRE_Dictionnaire dictionnaire;
	MOT_TableauDeMots tableauDeMot ;
	CO_TableauBooleens tableauBool ;
	CO_TableauPositions tableauPositions;
	MOT_TableauDeMots tableauMotCorriger;
	MOT_Mot motAcorriger;
	int logueurTableau, entierCourant,i,j, longueurTableauMotCor,position;
	if (argc>1){//appel avec option
		if (strcmp(argv[1],"-h")==0){//utilisateur demande de l'aide envoie de SOS ! d'un terrien en detresse
			afficherAide();
		}
		else{
			if (strcmp(argv[1],"-d")==0 && argc>=2){//première option est -d ET il y a un nom de fichier (a priori mais c'est une précondition) après
				nomDictionnaire = argv[2];
				fprintf(stderr,"on a le -d\n");
				dictionnaire = DICTIONNAIRE_chargerDictionnaire(nomDictionnaire);//on charge le dictionnaire meme si il est vide
				//Quesaquo du dictionnaire qui n'existe pas et qu'il faut créé (voir dans la lib DICO)
				if (argc >= 4){// il reste de paramètres en option
					if (strcmp(argv[3],"-f")==0 && argc>=4){// l'utilisateur souhaitent ajouter des mots ET a donner le nom du fichier à ajouter
						fprintf(stderr,"on rentre dans le -f");
						nomFichier = argv[3];
						DICTIONNAIRE_ajouterFichier(&dictionnaire,nomFichier);
					}
					else {//le paramètre suivant n'est pas -f OU le fichier n'a pas été donné
						afficherAide();
					}
				}
				else{
					//coder la correction ici 
					//Le dictionnaire a été chargé il faut récupérer la chaine de carcatère du texte et appliquer les éventuelles corrections
					saisirChaine(chaineEntree,sizeof(chaineEntree));
					fprintf(stderr,"on a rentre %s\n",chaineEntree);//pour tester le fonctionnement
					tableauMotDansPhrase = CO_phraseEnMots(chaineEntree);
					tableauDeMot = CO_obtenirTabMots(tableauMotDansPhrase);
					tableauBool = CO_sontPresents(tableauDeMot,dictionnaire);
					tableauPositions = CO_obtenirTabPositions(tableauMotDansPhrase);
					logueurTableau = CO_obtenirLongueurTabEntiers(tableauBool);
					for (i = 0; i<logueurTableau;i++){
						entierCourant = CO_obtenirIemeEntier(tableauBool,i);
						if (entierCourant){
							printf("*\n");
						}
						else{
							printf("& ");
							motAcorriger = MOT_obtenirIemeMot(tableauDeMot,i);
							printf("%s ", MOT_motEnChaine(motAcorriger));
							tableauMotCorriger = CO_proposerMots(motAcorriger,dictionnaire);
							longueurTableauMotCor = MOT_obtenirLongueurTabMots(tableauMotCorriger);
							printf("%d ", longueurTableauMotCor);
							position = CO_obtenirIemeEntier(tableauPositions,i);
							printf("%d:", position);
							for (j = 0; j<longueurTableauMotCor;j++){
								printf("%s ",MOT_motEnChaine(MOT_obtenirIemeMot(tableauMotCorriger,j)));
							}
							printf("\n");
						}
					}
				}
			}
			else{//la premiere option n'est pas -d ou il n'y a pas le nom de fichier après
				afficherAide();
			}
		}
	}
	else {//appel sans option
		afficherAide();
	}
}