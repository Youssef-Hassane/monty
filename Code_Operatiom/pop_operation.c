#include "../monty.h"

/**
 * pop_operation - Handles the "pop" operation.
 * Return: None.
 * --------------------------
 * Prototype: void f_pop(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Removes the top element from the stack.
 * If the stack is empty, prints an error message and exits.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void pop_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Declare a character array to hold the error message */
	char errorMessage[100];
	/* Declare a pointer to the top of the stack */
	stack_t *pointerToTop;
	/* Check if the stack is empty */
	if (*head == NULL)
	{
		/* Format the error message with the line number */
		sprintf(errorMessage, "L%u: can't pop an empty stack\n",
		theNumberOfTheLine);
		/* Write the error message to the standard error file descriptor */
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		/* Close the file associated with the Monty execution context */
		fclose(montyExecutionContext.theFile);
		/* Free the buffer used to store the script file contents */
		FREE_VARIABLE(montyExecutionContext.theBuffer);
		/* Release the memory allocated for the stack */
		release_stack(*head);
		/* Exit the program with a failure status */
		exit(EXIT_FAILURE);
	}
	pointerToTop = *head;
	/* Remove the top element from the stack */
	*head = (*pointerToTop).next;
	/* Free the memory associated with the removed element */
	FREE_VARIABLE(pointerToTop);
}
