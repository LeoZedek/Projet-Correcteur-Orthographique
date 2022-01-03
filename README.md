# ITI_ALGO_2021_2022 : Projet Correcteur Orthographique
## Contexte :
Ce projet a été réalisé par IMBERT Alexis, LIOTE Ruth, SAKOUTI Amina et ZEDEK Léo dans le cadre du cours d'algorithmie suivie en ITI3 dirigé par M DELESTRE, le projet a été supervisé par M GUERIAU.  
  
## Cahiers des charges
L’objectif de ce projet est de développer un correcteur orthographique à l’image des programmes unix ispell et aspell 1. Les fonctionnalités attendues de ce programme sont les suivantes.  
  
### Aider
Lorsqu’il est lancé sans option, ou avec l’option -h, ou avec une option non reconnue, le programme doit afficher une aide.
Par exemple :  
. / a s i s p e l l  
A i d e d e a s i s p e l l :  
    a s i s p e l l −h : c e t t e a i d e  
    a s i s p e l l −d d i c o : c o r r e c t i o n d e l ’ e n t r e e s t a n d a r d a l ’ a i d e du d i c t i o n n a i r e d i c o  
    a s i s p e l l −d d i c o −f f i c : c o m p l e t e r l e d i c t i o n n a i r e d i c o a l ’ a i d e d e s m o t s du f i c h i e r f i c ( un mot p a r l i g n e )  
  
### Compléter un dictionnaire
Il doit être possible de compléter un dictionnaire à l’aide des mots d’un fichier texte (un mot par ligne). Les options sont alors :  
-d pour spécifier le nom du fichier correspondant au dictionnaire utilisé ;  
-f pour spécifier le nom du fichier contenant les mots à ajouter.  
L’exemple suivant ajoute les mots du fichier dico-ref_asscii.txt (téléchargeable sur moodle) au dictionnaire francais.dico :  
. / a s i s p e l l −d f r a n c a i s . d i c o −f d i c o −r e f −a s c i i . t x t  
  
### Corriger
A l’image du programme ispell, le programme doit pouvoir analyser (et proposer des corrections orthographiques si besoin) un texte qui lui est donné via l’entrée standard. Cette analyse est dépendante d’un dictionnnaire (option -d). Cette analyse sera produite sur la sortie standard avec un mot analysé par ligne. Deux cas de figure sont traités :  
  
1. un mot est bien orthographié (présent dans le dictionnaire), le programme produit une étoile (’*’)
pour ce mot ;  
2. un mot est mal orthographié, le programme produit un et commercial (&) suivi des informa-
tions suivantes :  
— le mot mal orthographié ;  
— le nombre de corrections proposées ;  
— le position du mot mal orthographié depuis le début du flux d’entrée, suivi de deux points  
— les corrections proposées séparées par un espace.  
Voici un exemple d’utilisation :  
e c h o ” yn p e t t t s e t d e c o r e c t i o n o r t h o g r a p h y q u e a v e c q u e l q u e s  
f o t e s d ’ o r t h o g r a p h e . ” | . / a s i s p e l l −d f r a n c a i s . d i c o  
& yn 7 1 : y i n y e n un on i n e n a n  
& p e t t 2 4 : p e t i t p e u t  
& t s e t 1 1 1 : t e s t  
*& c o r e c t i o n 1 1 9 : c o r r e c t i o n  
& o r t h o g r a p h y q u e 1 2 9 : o r t h o g r a p h i q u e  
*  
*& f o t e s 16 5 8 : f o u t e s f o r t e s f o n t e s f o r e s f o i e s f ˆu t e s f ˆı t e s f ê t e s  
v o t e s r o t e s p o t e s n o t e s l o t e s d o t e s c o t e s b o t e s  
& d 11 6 4 : d ˆu d é du do dm d l dg d e à y a  
*  


## Comment corriger un mot ?  
Pour proposer des corrections d’un mot mal orthographié (pour un dictionnnaire donné) le plus  simple est de partir de ce mot et de lui appliquer des transformations qui permettent d’obtenir des mots proches . Si une transformation donne un mot bien orthographié alors ce mot est une correction possible. Voici quelques exemples de transformation :  
— remplacement d’une lettre ;  
— inversion de deux lettres consécutives ;  
— suppression d’une lettre ;  
— insertion d’une lettre ;  
— décomposition d’un mot en plusieurs mots ;  
— proposition d’un mot phonétiquement proche ;  
— etc.  
Dans l’exemple précédent, ce sont ces trois premières stratégies qui sont utilisées (c’est pour cela que le programme n’arrive pas à proposer une correction valable pour le mot fote ).  
L’inconvénient de cette méthode est qu’elle génère beaucoup de mots. Par exemple pour un mot de 5 lettres, la première stratégie va générer 5 ×(26 + 16) −5 = 205 mots (26 lettres de l’alphabet et 16 versions accentuées). Il faut donc que être capable de vérifier si un mot est présent dans un dictionnaire de manière efficace (le fichier dico-ref_asscii.txt proposé contient 336531 mots)  
  
## Travail demandé
### Analyse
On nous donne les type Mode, et le TAD Fichiertexte, dans le rapport.  
  
Nous avons du spécifier les TADs Mot, Dictionnaire et CorrecteurOrthographique.  
### Conception
#### Conception préliminaire
Nous avons données les signatures des fonctions et procédures des TAD précédents ainsi que celles issues de l'analyse descendantes (fonctions et procédures métiers)  

#### Conception détaillée
Nous avons fais l'analyse descendantes des fonctions et procédures des TAD précédents les plus complexes. Ainsi que celle des fonctions et procédures métiers.  

### Dévellopement, tests unitaires et documentation
Développer le programme en C en testant au maximum vos fonctions à l’aide de l’API CUnit (la personne qui codera les tests unitaires ne doit pas être la personne qui implante les fonctions C). Vous générerez aussi une documentation de votre code à l’aide du logiciel Doxygen  

## Ajout
Le pdf du rapport peut être obtenue grace à la compilation du fichier .tex (make dans le dossier rapport).    
Le correcteur orthographique est lui aussi compilable grace un makefile dans le dossier programme,  
Les options du makefile  
 - all (make par défaut) compile le programme, les tests unitaires et la documentation  
 - tests compile seulements les tests unitaires  
 - doc compile uniquement la documentation Doxygen  
  
Nous avons ajouté un script à la racine du projet qui permet de compilé à la fois le rapport et le programme (option all) en copiant dans le dossier "resultat" le pdf du rapport, le programe et la documentation Doxygen au format pdf.  




