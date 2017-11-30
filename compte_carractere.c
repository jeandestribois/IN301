#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{ 
	FILE *f=fopen(argv[1],"r");
	int compteur=0;
	while(fgetc(f)!=EOF) compteur++;
	fclose(f);
	printf("le nombre de carretère du fichier %s est de %d\n", argv[1], compteur);
	exit(0);
}
