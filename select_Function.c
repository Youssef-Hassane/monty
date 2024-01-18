#include "monty.h"

/**
 * select_Function - Selects and executes the appropriate
 * function based on the operation.
 * Return: 0 if successful, 1 if an unknown
 * instruction is encountered.
 * --------------------------
 * Prototype: int select_Function(
 *	String theBuffer, stack_t **stack,
 *	unsigned int theNumberOfTheLine, FILE *theFile
 *);
 * --------------------------
 * @theBuffer: Line read from the Monty script file.
 * @stack: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * @theFile: Pointer to the Monty script file.
 * --------------------------
 * Description: Parses the operation from theBuffer,
 * searches for a matching function,
 * and executes it. If the operation is not recognized,
 * prints an error message and exits.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

int select_Function(
	String theBuffer, stack_t **stack,
	unsigned int theNumberOfTheLine, FILE *theFile)
{
	unsigned int theIndex = 0;
	String operation;

	instruction_t allTheFunctions[] = {
	    {"push", push_operation},
	    {"pall", pall_operation}, /* Task 0 (push & pall) */
	    {NULL, NULL}
	};

	operation = strtok(theBuffer, THE_DELIMITERS);

	if (operation && operation[ZERO] == HASH)
	{
		return (ZERO);
	}
	montyExecutionContext.theArgument = strtok(NULL, THE_DELIMITERS);

	while (allTheFunctions[theIndex].codeOperation && operation)
	{
		if (strcmp(allTheFunctions[theIndex].codeOperation, operation) == ZERO)
		{
			allTheFunctions[theIndex].f(stack, theNumberOfTheLine);
			return (ZERO);
		}
		INCREASE_BY_ONE(theIndex);
	}
	if (operation && allTheFunctions[theIndex].codeOperation == NULL)
	{
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, operation, strlen(operation));
		write(STDERR_FILENO, ": Unknown instruction\n", 21);

		fclose(theFile);
		free(theBuffer);
		release_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (ONE);
}
