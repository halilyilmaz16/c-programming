#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fibo2(int a1,int a2,int sira,int an,int a[])
{
		int i;

	for(i=0;i<sira;i++)
	  {
	  	an=a1+a2;
	  	a1=an+a2;
	  	a2=an+a1;
	  
	  }
	  printf("\n");
	 printf("F_%d printed in fibo2:%d\n",sira,a2);
	 a[0]= a2;
	 
	
}


void fibo(int a1,int a2,int sira,int an)
{
	int i;
	
	for(i=0;i<sira;i++)
	  {
	  	an=a1+a2;
	  	a1=an+a2;
	  	a2=an+a1;
	  	printf("%d %d  %d ",an,a1,a2);
	  }
	  printf("\n");
	 printf("F_%d printed in fibo:%d",sira,a2);
	 
	
	 
}

int main()
{
	int F_0;
	int F_1;
	int x;
	int n,i;
     printf("Enter the initial point:");
	 scanf("%d",&F_0);
	 printf("Enter the second point:");
	 scanf("%d",&F_1);
	 printf("Enter the number values:");
	 scanf("%d",&n);
	 
	 printf("User entered values\n F_0=%d F_1=%d n=%d\n",F_0,F_1,n);	
	
	  printf("Fibonnaci series sequence\n");
	  printf("%d %d ",F_0,F_1);
	  fibo(F_0,F_1,n,x);
	  printf("\n");
	  printf("F_%d printed in main after fibo:%d\n",n,x);
	  
	  int F_n[0];
	  
	   fibo2(F_0,F_1,n,x,F_n);  
	   printf("F_%d",n);
	  printf(" printed in main after fibo2:%d",n,F_n[0]);
	  
	  
	return 0;
}
