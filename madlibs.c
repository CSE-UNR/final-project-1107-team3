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
int lineNumberer(FILE* fp);


/* Main function: */
int main()
{
	char letterHolder[SIZE];
	int lines;

	FILE *fp;
	
	fp = fopen(FILE_LIBS1, "r");
	
	if(fp == NULL)
	{
		printf("File could not open.");
		return 0;
	}
	
	//Ignore this following code it just shows the number of lines in the file
	lines = lineNumberer(fp);
	printf("%d\n", lines);
	
	fclose(fp);
	return 0;
}


/* Function definitions: */

//The following function returns the number of lines in a file:
int lineNumberer(FILE* fp)
{
	char stuff[SIZE];
	int counter = 0;
	
	while(fgets(stuff, SIZE, fp) != NULL)
	{
		counter++;
	}
	return counter;
}
