#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>

struct pixel
{
	int r, g, b;
};
typedef struct pixel PIXEL;

struct imageppm
{
	int L, H, max;
	PIXEL** tab;
};
typedef struct imageppm IMAGEPPM;



IMAGEPPM memorise_image(FILE *f)
{
	IMAGEPPM image;
	fscanf(f,"P3\n%d %d\n%d\n",&image.L,&image.H,&image.max);
	printf("%d %d %d\n",image.L,image.H,image.max); 
	image.tab=malloc(image.L*sizeof(PIXEL*));
	for(int i=0; i<image.L; i++)
	{
		image.tab[i]=malloc(image.H*sizeof(PIXEL));
	}
	for(int i=0; i<image.H; i++)
	{
		for(int j=0; j<image.L; j++)
		{
			fscanf(f,"%d %d %d ",&image.tab[i][j].r,&image.tab[i][j].g,&image.tab[i][j].b);
			//printf("\n%d - %d\t\t",j,i);
			//printf("R = %d G = %d B = %d\n",image.tab[i][j].r,image.tab[i][j].g,image.tab[i][j].b);
		}
	}
	return image;
}

void affiche_image_terminal(IMAGEPPM image)
{
	char p;
	for(int i=0; i<image.L; i++)
	{
		for(int j=0; j<image.H; j++)
		{
			if(image.tab[i][j].r>image.tab[i][j].g && image.tab[i][j].r>image.tab[i][j].b) p='R';
			else if(image.tab[i][j].g>image.tab[i][j].r && image.tab[i][j].g>image.tab[i][j].b) p='G';
			else p='J';
			printf("%c",p);
		}
		printf("\n");
	}	
}

void affiche_image_graphique(IMAGEPPM image)
{
	init_graphics(image.L,image.H);
	POINT P;
	for(int i=0; i<image.L; i++)
	{
		P.y=image.L;
		for(int j=0; j<image.H; j++)
		{
			P.x=image.H;
			draw_pixel(P,couleur_RGB(image.tab[i][j].r,image.tab[i][j].g,image.tab[i][j].b));
		}
	}
}

int main(int argc, char** argv)
{
	FILE *f = fopen(argv[1], "r");
	IMAGEPPM image;
	image=memorise_image(f);
	//affiche_image_terminal(image);
	affiche_image_graphique(image);
	
	exit(0);
}
