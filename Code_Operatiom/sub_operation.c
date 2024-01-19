#include "../monty.h"

/**
 * sub_operation - Handles the "sub" operation.
 * Return: None.
 * --------------------------
 * Prototype: void sub_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Checks if the argument after "sub"
 * is a valid integer.
 * If not, prints an error message and exits.
 * Subtracts the integer from the stack or queue.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void sub_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Declare a character array to hold the error message */
	char errorMessage[50];
	/* Temporary pointer for stack manipulation */
	stack_t *temporaryPointer;
	/* Check if the stack is too short to perform subtraction */
	if (!head || !*head || !(*head)->next)
	{
		/* Prepare error message */
		sprintf(errorMessage, "L%d: can't sub, stack too short\n",
		theNumberOfTheLine);
		/* Output error message to stderr */
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		/* Close the file stream associated with the Monty script */
		fclose(montyExecutionContext.theFile);
		/* Free the buffer used for storing lines from the Monty script */
		FREE_VARIABLE(montyExecutionContext.theBuffer);
		/* Release all nodes of the stack */
		release_stack(*head);
		/* Exit due to the error */
		exit(EXIT_FAILURE);
	}
	/* Point to the second element in the stack */
	temporaryPointer = (*head)->next;
	/* Subtract the top element value from the second element value */
	temporaryPointer->n -= (*head)->n;
	/* Remove the top element of the stack after the subtraction */
	pop_operation(head, theNumberOfTheLine);
}
