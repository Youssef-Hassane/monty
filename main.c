#include "main.h"

/**
 * main - entry point of the program
 * Return: 0 on success
 * -------------------------
 * @argumentCounter: number of arguments
 * @argumentVector: list of arguments
 * -------------------------
 * By Youssef Hassane AKA Almasy
 */

Integer main(Integer argumentCounter, StringArray argumentVector)
{

	/**
	 * julien@ubuntu:~/monty$ ./monty bytecodes/00.m
	 * 3
	 * 2
	 * 1
	 */

	(void)argumentVector;

	FILE *theFile;
	String theBuffer;
	ULI theSizeOfTheBuffer;
	Integer theNumberOfTheLine = ONE;

	if (argumentCounter != TWO)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	theFile = fopen(argumentCounter[ONE], READ);

	if (!theFile)
	{
		write(STDERR_FILENO, "Error: Can't open file ", 23);
		write(STDERR_FILENO, argumentCounter[ONE], strlen(argumentCounter[ONE]));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}

	while (getline(&theBuffer, &theSizeOfTheBuffer, theFile) != -1)
	{
		INCREASE_BY_ONE(theNumberOfTheLine);
	}
	fclose(theFile);
}
