#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *No_Space(char *c,char *d){

	char ch,sh;
	FILE *f,*h;
	f=fopen(c,"r+");
	h=fopen(d,"w+");
	rewind(f);
	ch=fgetc(f);
	while(ch!=EOF)
	{
		if(ch!=' ')
		fputc(ch,h);
		else
		{
		sh=ch;
		ch=fgetc(f);
		if(ch!=' ')
		{
			fputc(' ',h);
		fputc(ch,h);
	}
		else
		{
			fputc(sh,h);
			while(ch==' ')
			{
				ch=fgetc(f);
			}
			fputc(ch,h);
		}
		
	}
	ch=fgetc(f);
 }
 
 fclose(h);
 fclose(f);
 return h;
	
}
