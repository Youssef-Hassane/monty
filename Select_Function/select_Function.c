#include "../monty.h"

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
	unsigned int theIndex = 0;	/* Initialize the index for the loop*/
	String operation;			/* Declare a variable to hold the operation name */
	char errorBuffer[50];		/* Buffer to store error messages */
	int numChars;			/* store the number of characters written to errorBuffer */
	/* Array of all supported functions and their corresponding operations */
	instruction_t allTheFunctions[] = {
	    {"push", push_operation}, {"pall", pall_operation},
	    {"pint", pint_operation}, {"pop", pop_operation},
	    {"swap", swap_operation}, {"add", add_operation},
	    {"nop", nop_operation}, {"sub", sub_operation},
	    {"div", div_operation}, {"mul", mul_operation},
	    {"mod", mod_operation}, {"pchar", pchar_operation},
	    {"pstr", pstr_operation}, {"rotl", rotl_operation},
	    {"rotr", rotr_operation}, {"queue", queue_operation},
	    {"stack", stack_operation}, {NULL, NULL}
	};	/* Tokenize the buffer to get the operation name */
	operation = strtok(theBuffer, THE_DELIMITERS);
	if (operation && operation[ZERO] == HASH)
		return (ZERO);
	montyExecutionContext.theArgument = strtok(NULL, THE_DELIMITERS);
	/* Loop through all operations */
	while (allTheFunctions[theIndex].codeOperation && operation)
	{	/* If the operation matches, execute the corresponding function */
		if (strcmp(operation, allTheFunctions[theIndex].codeOperation) == ZERO)
		{	/* Execute operation function */
			allTheFunctions[theIndex].f(stack, theNumberOfTheLine);
			return (ZERO);	/* Return success */
		} /* Increment the index for the next iteration*/
		INCREASE_BY_ONE(theIndex);
	}	/* If no operation is found */
	if (operation && allTheFunctions[theIndex].codeOperation == NULL)
	{	/* Print error message to error buffer */
		numChars = sprintf(errorBuffer, "L%d: unknown instruction %s\n",
		theNumberOfTheLine, operation);
		write(STDERR_FILENO, errorBuffer, numChars);/* Write error message to s-r*/
		fclose(theFile);		/* Close the script file */
		free(theBuffer);		/* Free the buffer allocated for the line */
		release_stack(*stack);	/* Release the stack */
		exit(EXIT_FAILURE);	/* Exit with failure*/
	} return (ONE);	/* Return failure if no operation was executed */
}
