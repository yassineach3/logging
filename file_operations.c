#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "No_spaces.c"
#include "No_Lignes.c"
#include "compter_mot.c"
#include "suppr_commentaire.c"
#include <dirent.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include "teste_old.c"
#include "show_files.c"


char *Nom_Fichier(){
	
	char *c;
	
	c=(char*)malloc(sizeof(char));
	
	printf("Entrez le nom de votre fichier :\n");

	scanf("%s",c);
	
	return c;
}



char *Nomer_Fichier(){
	
	char *c;
	
	c=(char*)malloc(sizeof(char));
	
	printf("Entrez le nom de nouveau fichier :\n");

	scanf("%s",c);
	
	return c;
}


/*******************************************************************************************/




int main() 
{
	
	char tampon[256]; 
	   
	if (getcwd (tampon, 256) == NULL) {
		return 0;
	    } 
	puts (tampon);
		

	int choix;
	char *c,*d;

	c=(char*)malloc(sizeof(char));
	d=(char*)malloc(sizeof(char));
	
	do
	   {

	printf("\n****************Menu****************\n");
	printf("1-Spprimer les commentaire \n");
	printf("2-Compter le nombre des mots existant dans un fichier \n");
	printf("3-Supprimer les espaces unitils \n");
	printf("4-Supprimer les lignes unitils \n");
	printf("5-Supprimer un fichier\n");
	printf("0-quitter\n\n");
	printf("\nvotre choix :\n");
	scanf("%d",&choix);
	system("clear");
	switch(choix)
	{
		case 1 : c=Nom_Fichier();d=Nomer_Fichier();suppr_commentaire(c,d);openDirectory(tampon); break ;
		case 2 : c=Nom_Fichier();compter_mot(c);openDirectory(tampon);break;
		case 3 : c=Nom_Fichier();d=Nomer_Fichier();No_Space(c,d);openDirectory(tampon);break;
		case 4 : c=Nom_Fichier();d=Nomer_Fichier();No_Lignes(c,d);openDirectory(tampon);break;
		case 5 : c=Nom_Fichier();remove(c);openDirectory(tampon);break;
		
		case 0 : printf("\nQuiter !\n");openDirectory(tampon);break;
		
		default : printf("entrez un choix entre 0-5\n")	;
	
	}
	
		}while(choix!=0);
	
	return 0;
}

