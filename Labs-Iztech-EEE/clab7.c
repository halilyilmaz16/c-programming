#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

void countWords(char argument[])
{
	int i=0,counter;
	int word=1;
	counter=argument[i];
	while(counter != '\n')
	{ 
	        i++;
			counter=argument[i];
	
		if(counter ==' ')
		{
			word++;
			break;
		}
		
		
	}
	printf("\n Number of words in the sentence: %d",word);
}
	
void countVowelsAndConsonants(char argument[])
{
	int i=0,counter;
	int vowel=0;
	int consonant=0;

	do
	{
		counter=argument[i];
		
		i++; // i sonraký sefer için artýcak
		if(counter == 'a' || counter == 'A')
		{ 
		  vowel++;
		  
		}
		else if(counter == 'e' || counter == 'E')
		{ 
		  vowel++;
		 
		}
		 else if(counter == 'o' || counter == 'O')
		{ 
		  vowel++;
		 
		}
		 else if(counter == 'i' || counter == 'I')
		{ 
		  vowel++;
	}
		else if(counter == 'u' || counter == 'U')
		{ 
		  vowel++;
		  
		}
		else
		{
			consonant++;
			
		}
		
		
		
		
	}while(counter !='\n');
	
	
	printf("\n Number of vowel letter in the sentence: %d",vowel);
    printf("\n Number of consonants letter in the sentence: %d",consonant);	
}

	

int main()
{
 char st[MAX];
   puts("Please Enter a sentence:");
   fgets(st,MAX,stdin);
 countWords(st);
 countVowelsAndConsonants(st);
 
	
	
}
