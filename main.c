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
	FILE *theFile;				/* File pointer to the Monty bytecodes file */
	String theBuffer;				/* Buffer string to hold each line from the file*/
	ULI theSizeOfTheBuffer = 0;		/* Size of the buffer, initially zero */
	ssize_t get_line = 1;			/* Variable to store the getline() return value */
	unsigned int theNumberOfTheLine = 0;/* Line counter for the Monty file */
	stack_t *stack = NULL;			/* Pointer to the top of the stack */
	/* Check if the correct number of command-line arguments is given */
	if (argumentCounter != TWO)
	{	/* Print usage message to stderr and exit if incorrect */
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	} /* Open the Monty bytecodes file */
	theFile = fopen(argumentVector[ONE], READ);
	/* Store the file pointer in the global execution context */
	montyExecutionContext.theFile = theFile;
	/* If the file failed to open, print error message to stderr and exit */
	if (!theFile)
	{
		write(STDERR_FILENO, "Error: Can't open file ", 23);
		write(STDERR_FILENO, argumentVector[ONE], strlen(argumentVector[ONE]));
		write(STDERR_FILENO, NEW_LINE, ONE);
		exit(EXIT_FAILURE);
	} /* Read each line from the file using getline in a loop */
	while (get_line > ZERO)
	{	/* Set the buffer to NULL before reading a new line */
		NULL_VARIABLE(theBuffer);
		/* Read a line and store it in theBuffer; update theSizeOfTheBuffer */
		get_line = getline(&theBuffer, &theSizeOfTheBuffer, theFile);
		/* Store the current buffer in the global execution context */
		montyExecutionContext.theBuffer = theBuffer;
		INCREASE_BY_ONE(theNumberOfTheLine);
		if (get_line > ZERO)
		{	/* If a line was read, process the line with select_Function */
			select_Function(theBuffer, &stack, theNumberOfTheLine, theFile);
		}	/* Free the buffer after processing*/
		FREE_VARIABLE(theBuffer);
	}
	release_stack(stack);	/* After reading all lines, release the stack */
	fclose(theFile);		/* Close the Monty file */
	return (ZERO);		/* Return 0 to indicate successful execution */
}
