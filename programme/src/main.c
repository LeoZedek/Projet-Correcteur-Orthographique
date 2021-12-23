#include<stdio.h>
#include<string.h>
#include"correcteurOrthographique.h"
#include"dictionnaire.h"
#include"mot.h"

void afficherAide(){
	printf("Aide de asispell :\n");
	printf("\t asispell -h : cette aide\n");
	printf("\t asispell -d dico : correction de l'entree standard a l'aide du dictionnaire dico\n");
	printf("\t asispell -d dico -f fic : completer le dictionnaire dico a l'aide des mots du fichier fic (un mot par ligne)\n");
}

int main(int argc, char **argv){	
	
	if (argc == 1){
		afficherAide(); //Affichage de l'aide dans le cas ou il n'y a pas de paramètre à l'appelle de la fonction
	}
	else{
		if (strcmp(argv[1],"-h")==0){// Affichage de l'aide à la demande de l'utilisateur
			afficherAide(); 
		}
		else{
			/*------------------------ Fonctionnement du correcteur ------------------------------*/
			printf("n'affiche pas l'aide");
		}
	}
}
