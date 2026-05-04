#include <stdio.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14


 char plotArray[21][41];
 
double generateSinuswave(double time,double Amplitude,double frequency)
{
	return (Amplitude *sin(0.4*PI)*(time*frequency));
}
void clearscreen(char arr[21][41]);
void coordinate_system(char arr[21][41]);
void printScreen(char arr[21][41]);
void plotWaveform(magnitude,frequency);

int main()
{
	double magnitude;
	double frequency;
	printf("Welcome to Sine Wave Generator Oscillopse Screen\n");
	printf("Please Enter the magnitude:");
	scanf(" %lf",&magnitude);
	printf("Please Enter the frequency:");
	scanf(" %lf",&frequency);
	char plotArray[21][41];
	clearscreen(plotArray);
	coordinate_system(plotArray);
	printScreen(plotArray);
	plotWaveform(magnitude,frequency);

	
	return 0;
}
void printScreen(char arr[21][41])
{
	int i,j;
	for(i=0;i<21;i++)
	{
		for(j=0;j<41;j++)
		{
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
}
void coordinate_system(char arr[21][41])
{
	
	int i,j;
	for(i=0;i<21;i++)
	{
		for(j=0;j<41;j++)
		{
			if(j==20)
			{
				arr[i][j]='|';
				if(i % 5 ==0)
				{
					arr[i][j]='+';
				}
			}
			if(i==10)
			{
				arr[i][j]='-';
				if(j % 5 == 0)
				{
					arr[i][j]='+';
				}
			}
			
		}
	}
	
	
}
void clearscreen(char arr[21][41])
{
	
	int i,j;
	for(i=0;i<21;i++)
	{
		for(j=0;j<41;j++)
		{
		  arr[i][j]=' ';	
		}
	
	}
}

void plotWaveform(double amplitude,double frequency)
{
	
	
	
}

