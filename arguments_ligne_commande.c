#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isFloat(char* s)
{
	int i=0;
	if(s[i]=='-') i++;
	if(!isdigit(s[i])) return 0;
	i++;
	while(isdigit(s[i])) i++;
	if(s[i]=='\0') return 1;
	if(s[i]!='.') return 0;
	i++;
	if(!isdigit(s[i])) return 0;
	while(isdigit(s[i]))i++;
	if(s[i]=='\0') return 1;
	return 0;
}

int main(int argc, char** argv)
{
	int i;
	char str[80];
	for(i=1; i<argc; i++)
	{							 
		if(!isFloat(argv[i])) 
		{
			sprintf(str,"%s n'est pas un float\n",argv[i]);
			printf("%s",str);
			exit(0);
		}
	}
	double s=0;
	for(i=0; i<argc; i++)
	{
		printf("%s ",argv[i]);
	}
	for(i=1; i<argc; i++)
	{
		s+=atof(argv[i]);
	}
	printf("\nla somme est %f\n",s);
	
	exit(0);
}

