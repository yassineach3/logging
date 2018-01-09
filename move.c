#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

void copy(char *name_file)
{
	char *d,*x;
	d = name_file;
	x = (char*)malloc(sizeof(char));
	x="cp ";
	x=strcat(x,"image");
	x=strcat(x," ");
	x = strcat(x,d);
	
	system(x);
}