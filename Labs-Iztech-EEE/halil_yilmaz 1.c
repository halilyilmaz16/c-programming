
//Libraries I use

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// I used this variables

#define ROW_SIZE 9   
#define COL_SIZE 9
#define MAT_SIZE 3

char myArray[ROW_SIZE][COL_SIZE]; // I defined my array as a local string


int play_game(void); // This function works when the game starts and displays the screen in front of us.
int game_mode(void); //This function takes a value from us when we open a new game.
int writeFileToArray(int mode, char myArray[ROW_SIZE][COL_SIZE]); //This function saves the file for the new game opened to our directory.
void print_table(char myArray[ROW_SIZE][COL_SIZE]); //This function prints our sudoku board and also prints the values in the file we scanned.
int control_row(int x); //These three arrays of our values look at whether a value is entered between 1-9 and S values.
int control_col(int a);
int control_num(int b);
int save_the_game(char myArray[ROW_SIZE][COL_SIZE]); //This function prints our array to file
int  load_save_game(char myArray[ROW_SIZE][COL_SIZE]); //This function opens the file named .txt
int check_sudoku(char myArray[ROW_SIZE][COL_SIZE],int row, int cols); //This function checks whether the entered value is used more than once in rows, columns and matrices.
int control_table(char myArray[ROW_SIZE][COL_SIZE]); //This function ends the game and starts it again if all elements of the array are non-0.





int main() 
{
  int row, cols;  //I used for array
  int num;  //I defined it as an integer, took the value as %d and converted it to a character variable.
  int control; //I defined this variable to exit the while condition if the control string returns 0 
  int mode;

  do {
   
    int result = play_game(); //Checks new game, saved game or game exit status
    
    
    if(result==1)
    {
    	mode = game_mode(); //If it is called new game, it takes the value of game mode.
    	
    	writeFileToArray(mode,myArray); //Transfers the selected mode from file to array
	}
    
    else if (result == 2) {
      
      load_save_game(myArray); //Loads the saved game file into the array
    }
    
    do {
              print_table(myArray);  //Prints our table
      
             row=control_row(row); //takes our values
               cols=control_col(cols);
               num=control_num(num);
              
               
               char num_char = num + '0';  //converts our number to character and prints the value in the table when the string is printed again
               myArray[row-1][cols-1]=num_char;
               
               
               check_sudoku(myArray,row,cols); //It checks whether the value we entered is in the other row, column and matrix.
               
               control = control_table(myArray); //controls what percentage of the game we do
               
               
            } while (control);
            print_table(myArray);  // last time we can see the table
    } while (1);
    return 0;
}

int control_table(char myArray[ROW_SIZE][COL_SIZE])
{
	int i,j;
	char temp[81]; //I reduced the two-matrix array to a single matrix to control it more easily. To see if there is a 0 in the array. Reverse engineering :-)
	int a=0;
	
	for(i=0;i<ROW_SIZE;i++)
	{
		for(j=0;j<COL_SIZE;j++)
		{
			temp[a]=myArray[i][j];
			a++;
		}
	}
	
	
	//controls  to zero
	a=0;
	do{
	   if(temp[a]== '0')
	   {
	   	 
	   	 
	   	  return 1;
	    }	
		a++;
	}while(a<81);
		printf("You WON! Press Enter\n");
		  return 0;
	
	
}

int check_sudoku(char myArray[ROW_SIZE][COL_SIZE],int row,int cols){

    char temp;
    
	int i,j;
	for(i=0;i<9;i++)
	{
	  if(i !=row-1 && myArray[i][cols-1]==myArray[row-1][cols-1] )  //I prevented him from checking his own value
	  {
	  	printf("The ROW has the same number!\n");
	    
	  }
	}
	for(j=0;j<9;j++)
	{
		if( j != cols-1  &&  myArray[row-1][j]==myArray[row-1][cols-1])
		{
		 printf("The COLUMN has the same number!\n");
		
		}
	}
	
	 //I used two variables to control the 3x3 matrix
     int stROW = (row-1/MAT_SIZE)*MAT_SIZE;
     int stCOL = (cols-1/MAT_SIZE)*MAT_SIZE;
     
     
     temp = myArray[row-1][cols-1];
     
     for(i=0;i<MAT_SIZE;i++)
     {
     	for(j=0;j<MAT_SIZE;j++)
     	{
     		if((stROW+i !=row-1 || stCOL+j != cols-1) && (myArray[stROW+i][stCOL+j]==temp))
     		{
     			printf("The MATRIX has the same number\n");
			 }
     		
		 }
	 }
     
     
    
	
	return 0;
}

int  load_save_game(char myArray[ROW_SIZE][COL_SIZE])
{

	int i,j;
	FILE *file;
	char loadfile[100];
	char temp[81];
	int a = 0;
	char ch;
	printf("Please Enter Saved Game:"); //It asks us to enter the name of the game in .txt format
	scanf("%s",&loadfile);
	
	file=fopen(loadfile,"r");

   if(file == NULL)
   {
   	printf("Error opening the file \n.");
   	return 1;
   }
     while ((a < 81) && (ch = fgetc(file)) != EOF) {
    if (ch >= '0' && ch <= '9') { // check if the character is a digit
      temp[a] = ch;
      a++;
    }
  }
	
	
	// copy temp to myArray
  for (i = 0; i < ROW_SIZE; i++) {
    for (j = 0; j < COL_SIZE; j++) {
      myArray[i][j] = temp[i * 9 + j];
    }
  }
	
}

int control_row(int x)
{
   //It only takes values 1-9 and S. If S is entered in these three functions, the save function runs and saves the game.
	do{
	printf("Please enter a Row  (1-9 or 'S'):");
	if(scanf(" %d",&x) == 1)
	{
		
	}
	else
	{
		char y;
		scanf(" %c",&y);
		if( y == 'S')
		{
			save_the_game(myArray);
			printf("Saving...");
			exit(0);
		}
	}
    }while(x<1 || x>9);
    return x;
	
}

int control_col(int a)
{
	
	do{
	printf("Please enter a Column  (1-9 or 'S'):");
	if(scanf("%d",&a) == 1)
	{
		
	}
	else
	{
		char y;
		scanf(" %c",&y);
		if( y == 'S')
		{
			save_the_game(myArray);
			printf("Saving...");
			exit(0);
		}
	}
    }while(a<1 || a>9);
	return a;
}

int control_num(int b)
{
do{
	printf("Please enter a Number  (1-9 or 'S'):");
	if(scanf("%d",&b) == 1)
	{
		
	}
	else
	{
		char y;
		scanf(" %c",&y);
		if( y == 'S')
		{
			save_the_game(myArray);
			printf("Saving...");
			exit(0);
		}
	}
    }while(b<1 || b>9);
    return b;
}

int save_the_game(char myArray[ROW_SIZE][COL_SIZE])
{
	//As I mentioned, if the S character is entered, this function opens a .txt file and saves the game.
	int i,j;
	FILE *file;
	
	char filename[100];
	printf("Please Enter a Saved Game Name:");
	scanf("%s",&filename);
	
	
	
	file = fopen(filename,"w");
	
	
	if(file == NULL)
	{
		printf("Error opening the file for writing\n.");
		return 1;
	}
	
	//Write the array to file
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			fprintf(file,"%c",myArray[i][j]);
		}
		fprintf(file,"\n");
	}
	
	fclose(file);
}

int game_mode(void) {
   //This screen greets us as the opening screen of the game. It prints the exact desired screen. only takes 1-3 !
 
  int x;
  printf("*-*-*-*-*-*-*-*-* Game Mode *-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
  printf("*\t\t\t 1- Easy\t\t\t*\n");
  printf("*\t\t\t 2- Medium \t\t\t*\n");
  printf("*\t\t\t 3- Hard \t\t\t*\n");
  printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
  do {
    printf("Your Selection:");
    scanf("%d", & x);
    if (x > 3 || x < 1) {
      printf("INVALID INPUT!\n");
    }
  } while (x > 3 || x < 1);
  return x;
}

int play_game(void) {
  //It asks us to choose the game mode and only takes values between 1-3
   
  int x;
  printf("*-*-*-*-*-*-* Welcome to IZTECH Sudoku Game *-*-*-*-*-*-*\n");
  printf("*\t\t\t Please Press \t\t\t*\n");
  printf("*\t\t\t 1- Play New Game\t\t*\n");
  printf("*\t\t\t 2- Load Game \t\t\t*\n");
  printf("*\t\t\t 3- Quit  \t\t\t*\n");
  printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
  do {
    printf("Your Selection:");
    scanf("%d", & x);
    if (x > 3 || x < 1) {
      printf("INVALID INPUT !!!\n");
    }
  } while (x > 3 || x < 1);
  if (x == 3) {
    printf("Finishing...");
    exit(0);
  } else {
    return x;
  }
}

void print_table(char myArray[ROW_SIZE][COL_SIZE]) {
 
  int i, j;

  printf("\nPress Key 'S' whenever you want to save the current the game\n");
  printf("+===+===+===+===+===+===+===+===+===+\n"); // top part
  
  for (i = 0; i < ROW_SIZE; i++) {
    for (j = 0; j < COL_SIZE; j++) {
       //before every value
      if(j %3 == 0)
      {
      	printf("|");
	  }
	  else{
	  	printf(":");
	  }
      if (myArray[i][j] == '0') {
        printf("   "); //If our value is equal to 0, press space
      } else {
        // print the value of myArray[i][j] if it's not '0'
        printf(" %c ", myArray[i][j]);
      }
    }
    printf("|\n"); //close the end
    if(i == 2 || i == 5 || i == 8) //specify matrices
		{
			printf("+===+===+===+===+===+===+===+===+===+\n");
		}
		else if(i<8)  // if not print this
		{
			printf("+---+---+---+---+---+---+---+---+---+\n");
		} // for the pattern
  }
}

int writeFileToArray(int mode, char myArray[ROW_SIZE][COL_SIZE]) {
	
  int i, j;
  FILE * file;
  char ch;
  char temp[81];
  int a = 0;
 //open that file based on selected status
  if (mode == 1) {
    file = fopen("easy.txt", "r");
  } else if (mode == 2) {
    file = fopen("medium.txt", "r");
  } else if (mode == 3) {
    file = fopen("hard.txt", "r");
  } else {
    printf("INVALID INPUT !!!\n");
    return 1;
  }
  //check if file open
  if (file == NULL) {
    printf("File does not exist \n");
    return 1;
  }

  // read file contents till end of file
  while ((a < 81) && (ch = fgetc(file)) != EOF) {
    if (ch >= '0' && ch <= '9') { // check if the character is a digit
      temp[a] = ch;  //save a temp string
      a++;
    }
  }

  // close file
  fclose(file);

  // copy temp to myArray
  for (i = 0; i < ROW_SIZE; i++) {
    for (j = 0; j < COL_SIZE; j++) {
      myArray[i][j] = temp[i * 9 + j];
    }
  }
   
  

  return 0;
}

//coded by Halil_Yýlmaz

