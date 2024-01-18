#define _POSIX_C_SOURCE 200809L

#include "monty.h"
/* You allowed to use a maximum of one global variable */
/* Global variable to hold shared information */
MontyContext_t montyExecutionContext = {NULL, NULL, NULL, 0};


/**
 * main - Entry point of the Monty interpreter
 * Return: Always 0 (Success)
 * --------------------------
 * Prototype: Integer main(Integer argumentCounter,
 * StringArray argumentVector);
 * --------------------------
 * @argumentCounter: Number of command-line arguments.
 * @argumentVector: Array of command-line argument strings.
 * --------------------------
 * Description: Opens and reads a Monty script file, line by line,
 * executing the corresponding operations using a stack.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

Integer main(Integer argumentCounter, StringArray argumentVector)
{
	FILE *theFile;
	String theBuffer;
	ULI theSizeOfTheBuffer = 0;
	ssize_t get_line = 1;
	unsigned int theNumberOfTheLine = 0;
	stack_t *stack = NULL;

	if (argumentCounter != TWO)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	theFile = fopen(argumentVector[ONE], READ);
	montyExecutionContext.theFile = theFile;
	if (!theFile)
	{
		write(STDERR_FILENO, "Error: Can't open file ", 23);
		write(STDERR_FILENO, argumentVector[ONE], strlen(argumentVector[ONE]));
		write(STDERR_FILENO, NEW_LINE, ONE);
		exit(EXIT_FAILURE);
	}

	while (get_line > ZERO)
	{
		NULL_VARIABLE(theBuffer);
		get_line = getline(&theBuffer, &theSizeOfTheBuffer, theFile);
		montyExecutionContext.theBuffer = theBuffer;
		INCREASE_BY_ONE(theNumberOfTheLine);
		if (get_line > ZERO)
		{
			select_Function(theBuffer, &stack, theNumberOfTheLine, theFile);
		}
		FREE_VARIABLE(theBuffer);
	}
	release_stack(stack);
	fclose(theFile);
	return (ZERO);
}
