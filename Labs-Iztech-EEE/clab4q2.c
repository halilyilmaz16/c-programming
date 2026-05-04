#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void hist(int array[])
{
	int i;
	int j;
	for(i=0;i<15;i++)
	{
		printf("%d  element is %d",array[i],i);
		
		for(j=1;j<=array[i];j++)
		{
			printf(" *");
		
		}
		printf("\n");
	}
}

int main()
{
	int arr[15];
	int i;
	for(i=0;i<15;i++)
	{
		arr[i]=rand()%15;
	}
	hist(arr);
	
}
