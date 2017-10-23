#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

//STRUCTURES

struct tableau
{
	int tab[100];
	int taille;
};
typedef struct tableau TABLEAU;

typedef struct element ELEMENT;
struct element
{
    int val;
    struct element *next;
};
typedef element* LISTE;





//FONCTIONS

int alea(int n)
{
	return rand()%(n+1);
}




TABLEAU tri_TABLEAU(TABLEAU var)
{
	int swh;
	for(int i=var.taille-1; i>=0; i--)
	{
		for(int j=0; j<i; j++)
		{
			if(var.tab[i]<var.tab[j])
			{
				swh=var.tab[i];
				var.tab[i]=var.tab[j];
				var.tab[j]=swh;
			}
				
		}
	}
	return var;
}



TABLEAU decalage_de_un(TABLEAU var)
{
	var.taille++;
	for(int i=var.taille-1; i>=0; i--)
	{
		var.tab[i+1]=var.tab[i];
	}
	var.tab[0]=0;
	return var;
}

int element_minimum_TABLEAU(TABLEAU var)
{
	int min=var.tab[0];
	for(int i=1; i<var.taille; i++)
	{
		if(var.tab[i]<min) {min=var.tab[i];}
	}
	return min;
}


long int produit_element_TABLEAU(TABLEAU var)
{
	long int p=1;
	for(int i=0; i<var.taille; i++)
	{
		p=p*var.tab[i];
	}
	return p;
}

void affiche_elements_TABLEAU(TABLEAU var)
{
	for(int i=0; i<var.taille; i++)
	{
		printf("à l'indice %d le tableau contient %d \n",i,var.tab[i]);
	}
}


TABLEAU init_struct_TABLEAU()
{
	TABLEAU var;
	var.taille=10;
	for(int i=0; i<var.taille; i++)
	{
		var.tab[i]=alea(20);
	}
	return var;
}

void permute_pointeurs(int* pointeur1, int* pointeur2)
{
	int p;
	p=*pointeur1;
	*pointeur1=*pointeur2;
	*pointeur2=p;
}

void taille_tableau()
{
	int t[10];
	printf("la taille de tab est de %lu octets \n",sizeof(t));
	printf("la taille de tab[0] est de %lu octets \n",sizeof(t[0]));
	printf("la taille de &tab[0] est de %lu octets \n",sizeof(&t[0]));
	printf("la taille de *&tab est de %lu octets \n",sizeof(*&t));
	printf("la taille de *&tab[0] est de %lu octets \n\n",sizeof(*&t[0]));
}

void taille_types()
{
	printf("la taille d'un char est de %lu octets \n",sizeof(char));
	printf("la taille d'un int est de %lu octets \n",sizeof(int));
	printf("la taille d'un double est de %lu octets \n",sizeof(double));
	printf("la taille d'un char* est de %lu octets \n",sizeof(char*));
	printf("la taille d'un void* est de %lu octets \n",sizeof(void*));
	printf("la taille d'un int* est de %lu octets \n",sizeof(int*));
	printf("la taille d'un double* est de %lu octets \n",sizeof(double*));
	printf("la taille d'un int** est de %lu octets \n",sizeof(int**));
	printf("la taille de int[10]  est de %lu octets \n",sizeof(int[10]));
	printf("la taille de char[7][3] est de %lu octets \n\n",sizeof(int[7][3]));
}

void decalage(int t[N])
{
	for(int i=0; i<N-1; i++)
	{
		t[i+1]=t[i];
	}
	t[0]=0;
}

int min_tableau(int t[N])
{
	int min=t[0];
	for(int i=1; i<N; i++)
	{
		if(t[i]<min) {min=t[i];}
	}
	return min;
}
int produit_tableau(int t[N])
{
	int p=1;
	for(int i=0; i<N; i++)
	{
		p=p*t[i];
	}
	return p;
}
void init_tableau(int t[N])
{
	for(int i=0; i<N; i++)
	{
		t[i]=1;
	}
}

void syracuse(int U)
{
	int i=0;
	printf("U%d=%d \n",i,U);
	while(i<30)
	{
		if(U%2==0)
		{
			U=U/2;
		}
		else
		{
			U=3*U+1;
		}
		i++;
		printf("U%d=%d \n",i,U);
	}
}

int somme_diviseur(int n)
{
	int s=1;
	for(int i=2;i<n; i++)
	{
		if(n%i==0) s+=i;
	}
	return s;
}

void nombres_amis(int nmax)
{
	int n;
	for(n=1; n<=nmax; n++)
	{
		if(somme_diviseur(somme_diviseur(n))==n)
		{
				printf("%d et %d sont amis \n",n,somme_diviseur(n));
		}
	}		
}

int nombre_premier(int a)
{
	for(int i=a-1; i>=2; i--)
	{
		if(a%i==0)
		{
			printf("%d n'est pas premier, sont plus grand diviseur est %d \n\n",a,i);
			return 0;
		}
	}
	printf("%d est nombre premier \n\n",a);
	return 1;
}

void multegypt(int x, int y)
{
	int z=0;
	printf("%d x %d \n",x,y);
	while(x>=1)
	{
		if(x%2==0)
		{
			x=x/2; 
			y=2*y;
		}
		else
		{
			x--; z+=y;
		}
		printf("=%d x %d +%d \n",x,y,z);
	}
	printf("=%d\n\n",z);
}

void conversion(int s)
{
	int m,h;
	h=s/3600;
	s=s%3600;
	m=s/60;
	s=s%60;
	printf("%d secondes vaut %d heures, %d minutes et %d secondes \n\n", s+60*m+3600*h,h,m,s);
}

void etoiles(int n)
{
	int i,j;
	for(i=0; i<n; i++)
	{
		for (j=0; j<(n-1-i); j++)
		{
			printf(" ");
		}
		printf("*\n");
	}
}

int main()
{
	//pour la fonction aléa
	srand(time(NULL));
	
	//calculs, rappels
	int etoile=10;
	int conv=8000;
	int x=156;
	int y=67;
	int prem=49;
	int nmax=10000;
	int syr=32;
	etoiles(etoile);
	conversion(conv);
	multegypt(x,y);
	nombre_premier(prem);
	nombres_amis(nmax);
	syracuse(syr);
	
	//tableaux
	int t[N];
	int produit;
	int minimum;
	init_tableau(t);
	produit=produit_tableau(t);
	printf("\nle produit de toute les valeurs du tableau est %d \n",produit);
	minimum=min_tableau(t);
	printf("\nle plus petit élément du tableau est %d \n\n",minimum);
	decalage(t);
	
	//pointeur
	int pointeur1=1;
	int pointeur2=2;
	taille_types();
	taille_tableau();
	permute_pointeurs(&pointeur1, &pointeur2);
	printf("pointeur1 = %d \npointeur2 = %d \n\n",pointeur1,pointeur2);
	
	//structure, tableaux
	long int prod_elem;
	int elem_min;
	printf("la taille de la structure TABLEAU est %lu octets\n\n",sizeof(TABLEAU)); 
	TABLEAU var;
	var=init_struct_TABLEAU();
	affiche_elements_TABLEAU(var);
	prod_elem=produit_element_TABLEAU(var);
	printf("\nle produit des éléments du tableau est %ld \n\n",prod_elem);
	elem_min=element_minimum_TABLEAU(var);
	printf("l'élément minimum du tableau est %d \n\n",elem_min);
	var=decalage_de_un(var);
	var=tri_TABLEAU(var);
	affiche_elements_TABLEAU(var);
	
	//listes chaînées
    
	
	
	exit(0);
}
