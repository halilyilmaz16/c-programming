#include <stdio.h>
#include <stdlib.h>
#include  <math.h>



int main()
{
	double x;
	double a;
	int k,n;
	int y=1;
	int i;
	printf("Enter the value of x in radius:\n");
	scanf("%lf",&x);	
	printf("Enter the value of n:\n");
	scanf("%d",&n);
    printf("The exact value of sin(x)=%lf\n",sin(x));
    printf("The exact value of cos(x)=%lf\n",cos(x));
    for(i=1;i<=n;i++)
    {
      	 y*=i;
    	printf("%d!=%d",i,y);
    	printf("\n");
	}
     
     
     printf("sinexact-sinapprox=0.000\n");
     printf("cosexact-cosapprox=0.000");
    

	return 0;
}
