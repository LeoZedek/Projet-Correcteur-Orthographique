#include<stdio.h>
#include"correcteurOrthographique.h"
#include"dictionnaire.h"
#include"mot.h"

void afficherAide(){
	printf("Affichage de l'aide");
}

int main(int argc, char **argv){	
	
	if (argc == 1){
		afficherAide(); //Affichage de l'aide dans le cas ou il n'y a pas de paramètre à l'appelle de la fonction
	}
	else{
		if (1/*A Changer*/){//argv[1]=="-h" faire la comparaison avec les  chaine de char
			afficherAide(); // Affichage de l'aide à la demande de l'utilisateur
		}
		else{
			/*------------------------ Fonctionnement du correcteur ------------------------------*/
			
		}
	}
}
