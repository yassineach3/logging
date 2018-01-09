#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *No_Lignes(char *c,char *d){
	
char ch;	
FILE *f,*h;
f=fopen(c,"rt+");
h=fopen(d,"w+");
rewind(f);
ch=fgetc(f);
while(ch!=EOF)
{ 
	if(ch==EOF)
	fputc(ch,h);
	if(ch!='\n')
	fputc(ch,h);
	else // ch== \n
	{
		ch=fgetc(f);
		
		if(ch=='\n')
		{
			while(ch=='\n')
		ch=fgetc(f);
		
		fputc('\n',h);
		fputc(ch,h);
	}
	else
	{
		fputc('\n',h);
	fputc(ch,h);
	}
	
	}
	ch=fgetc(f);
}
fclose(h);
fclose(f);

 return h;
}


