#include <stdio.h>
#include <stdlib.h>

void printArray(int a[],int element)
{
	
	int i;
	printf("Orginal Array: ");
	for(i=0;i<element;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void findMaxAndRecord(int a[],int element) 
{
	int i,j,k;
	int max=0;
	printf("Sorted Array with max element: ");
	for(i=1;i<element;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(a[j]<a[j+1])
			{
				max=a[j+1];
				a[j+1]=a[j];
				a[j]=max;
				
			}
		}
	 
	}
	
	for(k=0;k<element;k++)
	{
		printf(" %d ",a[k]);
			} 
}







int main()
{
	int n,i;
	printf("Enter the size of array! :");
	scanf("%d",&n);
	int arr[n];
	int tarr[n];
	printf("Enter the elements of array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printArray(arr,n);
	findMaxAndRecord(arr,n);
	
	 
	

	return 0;
	
}
