
/* Fonction qui compte le nombre des mots dans un fichier donner */

int compter_mot(char *c){
	
	
int cpt=0,mot=0;

char ch;


FILE *f;

f=fopen(c,"r+");

ch=fgetc(f);

while(ch!=EOF)
{
	if(ch!=' ' && ch!='\n')
	{	
		do{
			cpt++;
			ch=fgetc(f);
		}
		while(ch!=' ' && ch!='\n' && ch!=EOF);
	
		if(cpt>1) 
		{
			mot++;cpt=0;
		}
	
	}
	ch=fgetc(f);
}
	
printf("le nombre des mots est : %d",mot);	
return mot;
	
fclose(f);
}
