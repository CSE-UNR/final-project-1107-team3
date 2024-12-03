//Programmers: Dylan Chhorn,
//Date: 11-26-2024
//Purpose: Use Arrays and FILE IO to create a madlibs for the user

#include <stdio.h>
#include <stdbool.h>
#define FILE_LIBS1 "madlib1.txt"
#define FILE_LIBS2 "madlib2.txt"
#define SIZE 100

//Function Prototype
int linenumberer(FILE* fp);

int main (){

	char letterholder[SIZE];
	int lines;

	FILE *fp;
	
	fp = fopen(FILE_LIBS1, "r");
	
	if (fp == NULL)
	{
		printf("File could not open.");
		return 0;
	}
	
	lines = linenumberer(fp);
	printf("%d", lines);
	
	
	fclose(fp);
	return 0;

}

int linenumberer(FILE* fp)
{
	char *stuff[SIZE];
	int counter = 0;
	while (fgets(*stuff, SIZE, fp) != "\n")
	{
		counter++;
	}
	return counter;
}


