#include <stdlib.h>
#include "mot.h"
#include "dictionnaire.h"
#include "correcteurOrthographique.h"

CO_TableauDEntiers CO_tableauDEntiersVide(){
	CO_TableauDEntiers tab;
	tab.lesEntiers = NULL;
	tab.longeur = 0;
	return tab;
}



