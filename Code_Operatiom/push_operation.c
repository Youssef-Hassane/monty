#include "../monty.h"

/**
 * push_operation - Handles the "push" operation.
 * Return: None.
 * --------------------------
 * Prototype: void f_push(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Checks if the argument after "push"
 * is a valid integer.
 * If not, prints an error message and exits.
 * Adds the integer to the stack or queue.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */



void push_operation(stack_t **head, unsigned int theNumberOfTheLine)
{	/* Declare variables for handling the push operation */
	Integer theValueToBePushed, characterIndex = 0, theMode = 0;
	/* Check if an argument is provided after "push" */
	if (montyExecutionContext.theArgument)
	{	/* Handle negative sign in the argument */
		if (montyExecutionContext.theArgument[0] == DASH)
			INCREASE_BY_ONE(characterIndex);
		while (montyExecutionContext.theArgument[characterIndex] != NULL_TERMINATOR)
		{	/* Check if the argument is a valid integers */
			if (montyExecutionContext.theArgument[characterIndex] > 57 ||
			    montyExecutionContext.theArgument[characterIndex] < 48)
				theMode = 1; /* Set theMode to 1 if non-numeric character is found */
			INCREASE_BY_ONE(characterIndex);
		}
		if (theMode == 1)
		{	/* Print error and exit if the argument is not a valid integer */
			fprintf(stderr, "L%d: usage: push integer\n", theNumberOfTheLine);
			fclose(montyExecutionContext.theFile);
			FREE_VARIABLE(montyExecutionContext.theBuffer);
			release_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{	/* Print error and exit if no argument is provided after "push" */
		fprintf(stderr, "L%d: usage: push integer\n", theNumberOfTheLine);
		fclose(montyExecutionContext.theFile);
		FREE_VARIABLE(montyExecutionContext.theBuffer);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}	/* Convert the argument to an integer */
	theValueToBePushed = atoi(montyExecutionContext.theArgument);
	/* Add the integer to the stack or queue based on the execution mode */
	if (montyExecutionContext.theMode == 0)
		addNodeToStack(head, theValueToBePushed);
	else
		AddNodeToQueue(head, theValueToBePushed);
}
