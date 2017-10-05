#include <stdio.h>
#include <stdlib.h>

void tableau(int N)
{
	int t[N];
	int p=1;
	int min;
	for(int i=0; i<N; i++)
	{
		t[i]=1;
	}
	for(int i=0; i<N; i++)
	{
		p=p*t[i];
	}
	printf("\nle produit de toute les valeurs du tableau est %d \n",p);
	min=t[0];
	for(int i=1; i<N; i++)
	{
		if(t[i]<min) {min=t[i];}
	}
	printf("\nle plus petit élément du tableau est %d \n",min);
	
}

void syracuse(int U)
{
	int i=0;
	printf("U%d=%d \n",i,U);
	while(i<60)
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
	int n=10;
	int s=8000;
	int x=156;
	int y=67;
	int a=49;
	int nmax=10000;
	int U=127;
	int k=5;
	int j=8;
	int N=50;
	etoiles(n);
	conversion(s);
	multegypt(x,y);
	nombre_premier(a);
	nombres_amis(nmax);
	syracuse(U);
	tableau(N);
	
	exit(0);
}
