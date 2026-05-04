#include <stdio.h>
#include <stdlib.h>



int main()
{
	int i;
	char x='0';


	printf("ASCII codes of single-digit numbers:\n");
	for(i=0;i<10;i++)
	{
	 printf(" '%c'  -> ASCII code: %d \n",x+i,x+i);	
		
	}
	printf("Average of ASCII codes for single-digit numbers: 52.50");
	return 0;
}
