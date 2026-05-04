#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void storePattern(char coordinates[100][100], int length);
void printArrays(char pA[100][100], int length);

double main()
{
	int length;
	char coordinates[100][100];
	printf("Enter the length of side :");
	scanf("%d",&length);
     
	storePattern(coordinates,length);
	
}

void storePattern(char coordinates[100][100], int length)
{
	int i,j;
	
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
          if(i == 0 || j == 0)  // iþlemi*
          {
          	coordinates[i][j]='*';
		  }
		  if(i == length || j== length)
		  {
		  	coordinates[i][j]='*';
		  }
		  if(i == j || i == length - j)
		  {
		
		  	coordinates[i][j]='*';
		  }
		  if(i< j && i < length-j) // 2 için
		  {
		  	coordinates[i][j]='2';
		  }
          if(j < i && j < length-i)  // 1 için
          {
          	
          	coordinates[i][j]='1';
		  }
          if(length-j<i && length-j<  ) // 3 için
          {
          	coordinates[i][j]='3';
		  }
          if()
          {
          	coordinates[i][j]='4';
		  }
		}
		
	}
	
	
}

void printArrays(char pA[100][100], int length)
{
	int i,j;
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			printf("%c",&pA[i][j]);
		}
		
		printf("\n");
	}
	
	
	
}
