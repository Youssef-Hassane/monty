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
	/* char errorBuffer[50]; */
	/* int numChars; */

	instruction_t allTheFunctions[] = {
	    {"push", push_operation},
	    {"pall", pall_operation},
	    {"pint", pint_operation},
	    {NULL, NULL}
	};

	operation = strtok(theBuffer, " \n\t");

	if (operation && operation[ZERO] == HASH)
	{
		return (ZERO);
	}
	montyExecutionContext.theArgument = strtok(NULL, " \n\t");

	while (allTheFunctions[theIndex].codeOperation && operation)
	{
		if (strcmp(operation, allTheFunctions[theIndex].codeOperation) == ZERO)
		{
			allTheFunctions[theIndex].f(stack, theNumberOfTheLine);
			return (ZERO);
		}
		INCREASE_BY_ONE(theIndex);
	}
	if (operation && allTheFunctions[theIndex].codeOperation == NULL)
	{ /* numChars = sprintf(errorBuffer, "L%d: unknown instruction %s\n", */
		/* theNumberOfTheLine, operation); */
		/* write(STDERR_FILENO, errorBuffer, numChars); */
		fprintf(stderr, "L%d: unknown instruction %s\n",
		theNumberOfTheLine, operation);
		fclose(theFile);
		free(theBuffer);
		release_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (ONE);
}
