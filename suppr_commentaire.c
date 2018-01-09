
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Fonction qui supprime les commentaires */
FILE *suppr_commentaire(char *c,char *d){
int com=0; char ch,sh;
FILE *f,*h;
h=fopen(d,"w+");
f=fopen(c,"r+");
ch=fgetc(f);
while(ch!=EOF)
{	
	
	if(ch=='/')
	{	
		sh=ch;
		ch=fgetc(f);		
		if(ch=='/')
			{
				com++;	
			while(ch!='\n' && ch!=EOF)
				{
					ch=fgetc(f);
				}
			}			
		else 
			{
				fputc(sh,h);
			}	
	}
	fputc(ch,h);
	ch=fgetc(f);
}
printf("\nLe nombre de commentaire de type // que vous avez dans votre fichier est : %d",com);
fclose(f);
fclose(h);
return h;

}