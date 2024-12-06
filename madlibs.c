/************************************************************************
 * File name: madlibs.c                                                 *
 * Programmers: Dylan Chhorn, James Thompson, and Kenneth Rather.       *
 * Due date: December 10th, 2024 @ 11:59 PM PST.                        *
 * Purpose: Use all previous knowledge of C to create the game Mad Libs.*
 ************************************************************************/

/* Preprocessor directives: */
#include <stdio.h>
#include <stdbool.h>
#define FILE_LIBS1 "madlib1.txt"
#define FILE_LIBS2 "madlib2.txt"
#define SIZE 500

/* Function prototypes: */
int lineNumberer(FILE* fp);
void readFile(FILE*, char*);
void promptU(FILE* fptr, int evens, char letterHolder[], char userInput[][SIZE]);
void modUI(FILE* fptr, int lines, char userInput[][SIZE], char finalStory[][SIZE]);
int getuserinputSize(char userInput[][SIZE], int counter);

/* Main function: */
int main()
{
	char letterHolder[SIZE];
	int lines, f;

	FILE *fp;
	
	//This isnt in the executable but will be useful for us
	printf("Which file(1 or 2): ");
	scanf("%d", &f);
	
	if(f == 1)
	{
		fp = fopen(FILE_LIBS1, "r");
	}
	else if(f == 2)
	{
		fp = fopen(FILE_LIBS2, "r");
	}
	else
	{
		return 0;
	}
	
	if(fp == NULL)
	{
		printf("File could not open.");
		return 0;
	}
	
	//Ignore this following code it just shows the number of lines in the file
	lines = lineNumberer(fp);
	printf("%d\n", lines);
	fclose(fp);
	if(f == 1)
	{
		fp = fopen(FILE_LIBS1, "r");
	}
	else if(f == 2)
	{
		fp = fopen(FILE_LIBS2, "r");
	}
	else
	{
		return 0;
	}
	
	if(fp == NULL)
	{
		printf("File could not open.");
		return 0;
	}
	
	//Reads from file and stores the files char on each even line 
	readFile(fp, letterHolder);
	fclose(fp);
	if(f == 1)
	{
		fp = fopen(FILE_LIBS1, "r");
	}
	else if(f == 2)
	{
		fp = fopen(FILE_LIBS2, "r");
	}
	else
	{
		return 0;
	}
	
	if(fp == NULL)
	{
		printf("File could not open.");
		return 0;
	}
	
	int even = lines / 2;
	
	even--;
	
	char userInput[even][SIZE];
	
	promptU(fp, even, letterHolder, userInput);
	fclose(fp);
	if(f == 1)
	{
		fp = fopen(FILE_LIBS1, "r");
	}
	else if(f == 2)
	{
		fp = fopen(FILE_LIBS2, "r");
	}
	else
	{
		return 0;
	}
	
	if(fp == NULL)
	{
		printf("File could not open.");
		return 0;
	}
	
	char finalStory[lines][SIZE];
	modUI(fp, lines, userInput, finalStory);
	
	fclose(fp);
	return 0;
}


/* Function definitions: */

//The following function returns the number of lines in a file:
int lineNumberer(FILE* fptr)
{
	char stuff[SIZE];
	int counter = 0;
	
	while(fgets(stuff, SIZE, fptr) != NULL)
	{
		counter++;
	}
	
	return counter;
}

//The following function reads the file and stores the type of input requested in a string:
void readFile(FILE* fptr, char letterHolder[])
{
	char stuff[SIZE];
	int counter = 0;
	
	while(fgets(stuff, SIZE, fptr) != NULL)
	{
		fgets(stuff, SIZE, fptr);
		letterHolder[counter] = stuff[0];
		counter++;
	}
}

//Following function prompts and stores the userinput into an array
void promptU(FILE* fptr, int evens, char letterHolder[], char userInput[][SIZE])
{
	for(int i = 0; i < evens; i++)
	{
		if(letterHolder[i] == 'A')
		{
			printf("Please enter an adjective: ");
			scanf("%s", &userInput[i]);
		}
		else if(letterHolder[i] == 'N')
		{
			printf("Please enter an noun: ");
			scanf("%s", &userInput[i]);
		}
		else if(letterHolder[i] == 'V')
		{
			printf("Please enter an verb: ");
			scanf("%s", &userInput[i]);
		}
		else
		{
			//TEST CHANGE LATER
			printf("SHIT WACK");
		}
		printf("%s\n", userInput[i]);
	}
}

//The following function gets the size of the userinputted string
int getuserinputSize(char userInput[][SIZE], int counter)
{
	int count = 0;
	for(int j = 0; userInput[counter][j] != '\0'; j++)
	{
		count++;
	}
	return count;
}

//The following function assigns the userInput array into the position
//of the finalStory array
void modUI(FILE* fptr, int lines, char userInput[][SIZE], char finalStory[][SIZE])
{
	char stuff[SIZE];
	int counter = 0;
	
	for(int i = 0; i < lines; i++)
	{
		fgets(finalStory[i], SIZE, fptr);
	}
	
	for(int j = 0; j < lines; j++)
	{
		if ((j % 2) != 0)
		{
			for(int l = 0; l < getuserinputSize(userInput, counter); l++)
			{
				finalStory[j][l] = userInput[counter][l];
			}
			finalStory[j][getuserinputSize(userInput, counter)] = '\0';
			counter++;
		}
	}
	
	//The following below is just for seeing it. Get rid of later
	for(int m = 0; m < (lines - 1); m++)
	{
		printf("%s", finalStory[m]);
	}
	
}

