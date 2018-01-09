#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int show_files(char *repertoire)
{
	DIR* rep = NULL;
	rep = opendir(repertoire); /* Ouverture d'un dossier */
	
	/*printf("\n mon teste de repertoire \n");
	printf("%s \n",repertoire);*/


    if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */

        exit(1); /* (mauvais chemin par exemple) */

        


    puts("\nLe dossier a ete ouvert avec succes\n");



     // afficher les fichier d'un repertoire 
	
    // declaration d'un fichier null	
    struct dirent* fichierLu = NULL;

    while ((fichierLu = readdir(rep)) != NULL)

    printf("%ld -> %s\n", telldir(rep), fichierLu->d_name); 


   seekdir(rep, 2); /* On se place au 2e fichier. */

   printf("\n%s\n", readdir(rep)->d_name);


   seekdir(rep, 4); /* On se place au 4e fichier. */

   printf("\n%s\n", readdir(rep)->d_name);


 

    if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */

        exit(-1);


    puts("Le dossier a ete ferme avec succes\n");


    return 0;
}

