#include <stdio.h>
#include <stdlib.h>

struct imageppm
{
	char* c;
	int l,h,max;
	LISTE pixel = NULL;
};
typedef struct imageppm IMAGEPPM;

struct elem
{
	int intensité, espace;
	struct elem* suiv;
};
typedef struct elem* LISTE;

IMAGEPPM memorise_image(FILE *f, IMAGEPPM image)
{
	image.c=fgets("%s",10,f);
	image.lh=fgets("%s",100,f);
	image.max=fgets("%s",10,f);
	
}


int main(int argc, char** argv)
{
	FILE *f = fopen(argv[1], "r")
	IMAGEPPM image;
	image=memorise_image(f,image);
}
