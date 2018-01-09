#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include "teste_old.c"
#include "show_files.c"



/* fonction to print out a picture */
print_out(char *image)
	{
		char variable[256];
		sprintf(variable,"eog %s",image);
		system(variable);
	}


 int main (int c, char *v[]) {
	
	char tampon[256]; 
	
	
	print_out("bmw2002tii.jpeg");	// on passe le nom de l'image pour l'afficher 

	// cette partie qui me permet d'afficher le chemain de repertoir courant	   
	    if (getcwd (tampon, 256) == NULL) {
		return 0;
	    } 
	    printf("le chemin du répertoire courant est :\n");
	    puts (tampon);

	show_files(tampon);	// afficher tous les fichier de notre repertoire courant
	openDirectory(tampon);		// ouvrir le chemin donner dans la fonction


    }




