#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <math.h> 

// === FUNCTION PROTOTYPES ===== \\
 
void displayHints(int computerNumber, int userGuess);
int checkGuess(int computerNumber, int userNumber);
int getUserGuess(void);
int generateRandomNumber(int difficulty);
void evenOrOdd(int computerNumber);
void digitSum(int computerNumber);
void digitimpact(int computerNumber);
char playAgain(void);

int main()
{
  srand(time(0));    // Every time random numbers
  printf("==Game starting...==\n");
  
  printf("== LEVEL 1 is 1-10==\n");
  printf("== LEVEL 2 is 10-100==\n");
  printf("== LEVEL 3 is 100-1000==\n");
  
  do {
    int difficulty;
    printf("Choose your level!\n");
    scanf("%d", &difficulty);
    
    int computerNumber;
    int userNumber;
    int attempts = 0;
    
    computerNumber = generateRandomNumber(difficulty);   // Computer Takes random value 
    
    do {
      userNumber = getUserGuess();   // user write his guess
      attempts++;   
      
      int control;   // if our guess is correct return 0
      control = checkGuess(computerNumber, userNumber);
      
      if (control == 0) {
        printf("You WON!!! %d attempts\n", attempts);
        int score = 100 - (attempts * difficulty * 5);  // eveluate our score
        printf("Your Score is %d\n", score);
        break;
      } else {
        displayHints(computerNumber, userNumber);  // if our guess is not correct computer gives a hint lower or higher
      }
      
      if (attempts == 2) {    // if user cannot know two times computer gives a hint about value even or odd
        evenOrOdd(computerNumber);
      }
      
      if (attempts == 3 && difficulty > 1) { // if user can not know three times computer gives  digit of sum computer number 
        digitSum(computerNumber);
      }
      if(attempts == 4 && difficulty > 1)  // if user can not know four times computer gives digit of multiplying themselves computer digits
      {
      	digitimpact(computerNumber);
	  }
    } while (1);
    
    playAgain();   // if user do not want to play again game
    
    attempts = 0;  // if   user  want to play again
  } while (1);
  
  return 0;
}
 
  //computer generate random number  according to difficulty
int generateRandomNumber(int difficulty)
{
  int number;
  
  if (difficulty == 1) {
    number = rand() % 10;
    return number;
  } else if (difficulty == 2) {
    number = 10 + rand() % 89;
    return number;
  } else if (difficulty == 3) {
    number = 100 + rand() % 899;
    return number;
  }
}
  
  // user guess the number if user don't write integer  computer takes a integer
int getUserGuess(void)
{
  int userGuess;
  printf("Write your guess:");
  
  while (1) {
    if (scanf("%d", &userGuess) == 1) {
      break;
    } else {
      printf("\nPlease enter an integer: ");
      while (getchar() != '\n');
    }
  }
  
  return userGuess;
}


// computer gives  hints about number low or high

void displayHints(int computerNumber, int userGuess)
{
  if (computerNumber > userGuess) {
    printf("Too low!");
  } else {
    printf("Too high!");
  }
  
  printf("\nTry again!\n");
}


 // computer check the number
int checkGuess(int computerNumber, int userNumber)
{
  if (computerNumber == userNumber) {
    return 0; // correct
  } else {
    return 1; // incorrect
  }
}

 // computer gives hint even or odd
void evenOrOdd(int computerNumber)
{
  if (computerNumber % 2 == 0) {
    printf("Our Number is Even!\n");
  } else {
    printf("Our Number is Odd!\n");
  }
}
 // computer gives digitsum
void digitSum(int computerNumber)
{
  int sum = 0;
  int temp = computerNumber;
  
  while (temp > 0) {
    sum += temp % 10;
    temp /= 10;
  }
  
  printf("Sum of digits is %d\n",sum);
}
 // computer gives digit impact
void digitimpact(int computerNumber)
{
	
	int imp = 0;
	int temp = computerNumber;
	
	 while(temp>0)
	 {
	 	imp *= temp % 10;
	 	temp /= 10;
	 }
	
	printf("Multiplying the digits of a number %d\n",imp);
}

 // if user write n or N game is finish 
 
char playAgain(void)
{
  char answer;
  printf("Do you want to play again? (Y/N): ");
  scanf(" %c", &answer);  

  if (answer == 'y' || answer == 'Y') {
    return 1; 
  } else {
    printf("\nFinishing...");
    exit(0);  // hole program is finish
  }
}

