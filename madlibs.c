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
#define SIZE 100


/* Function prototypes: */
int lineNumberer(FILE*);
void readFile(FILE*, int, char*);


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
	
	readFile(fp, lines, letterHolder);
	
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
void readFile(FILE* fptr, int numL, char letterHolder[])
{
	for(int i = 0; i < numL / 2; i++)
	{
		printf("Enter a character: ");
		scanf("%c ", &letterHolder[i]);
	} 
}
