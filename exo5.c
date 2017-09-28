#include <stdio.h>
#include <stdlib.h>


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
	printf("=%d\n",z);
}

void conversion(int s)
{
	int m,h;
	h=s/3600;
	s=s%3600;
	m=s/60;
	s=s%60;
	printf("%d secondes vaut %d heures, %d minutes et %d secondes \n", s+60*m+3600*h,h,m,s);
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
	etoiles(n);
	conversion(s);
	multegypt(x,y);
	
	exit(0);
}
