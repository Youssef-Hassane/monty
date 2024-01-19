#include "../monty.h"

/**
 * pint_operation - Handles the "pint" operation.
 * Return: None.
 * --------------------------
 * Prototype: void pint_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Prints the value at the top of the stack.
 * If the stack is empty, prints an error message and exits.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void pint_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Declare a character array to hold the error message */
	char error_message[100];
	/* Check if the stack is empty */
	if (*head == NULL)
	{
		/* Format the error message with the line number */
		sprintf(error_message, "L%u: can't pint, stack empty\n", theNumberOfTheLine);
		/* Write the error message to the standard error file descriptor */
		write(STDERR_FILENO, error_message, strlen(error_message));
		/* Close the file associated with the Monty execution context */
		fclose(montyExecutionContext.theFile);
		/* Free the buffer used to store the script file contents */
		FREE_VARIABLE(montyExecutionContext.theBuffer);
		/* Release the memory allocated for the stack */
		release_stack(*head);
		/* Exit the program with a failure status */
		exit(EXIT_FAILURE);
	}
	/* If the stack is not empty, print the value at the top of the stack */
	printf("%d\n", (*head)->n);
}
