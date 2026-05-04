#include <stdio.h>
#include <stdlib.h>

int main()
{
	int mid1,mid2,final;
	float grade;
	char mod;
	printf("Please Select Exam Structure:\n");
	printf("1-Two exam model:Midterm and Final Exam\n");
	printf("2-Three exam model: Two midterm and Final Exam\n");
	printf(" Please select your selection: 1 or 2: ");
	scanf("%c",&mod);
	if(mod=='1')
	{
		printf("Enter Midterm grade:");
		scanf("%d",&mid1);
		printf("Enter Final:");
		scanf("%d",&final);
		grade= (float)(float)(mid1*0.4)+(float)(float)(final*0.6);
		printf("Your grade is %.3f",grade);
	}
	else if(mod=='2')
	{
		printf("Enter First Midterm grade:");
		scanf("%d",&mid1);
		printf("Enter Second Midterm grade:");
		scanf("%d",&mid2);
		printf("Enter Final:");
		scanf("%d",&final);
	    grade=(float)(float)(mid1*0.3)+(float)(float)(mid2*0.3)+(float)(float)(final*0.4);
		printf("Your grade is %.3f",grade);
	}
	else
	{
		printf("You enter  an absent system!");
	}
	
}
