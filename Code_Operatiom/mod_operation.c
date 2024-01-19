#include "../monty.h"

/**
 * mod_operation - Handles the "mod" operation.
 * Return: None.
 * --------------------------
 * Prototype: void mod_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Checks if the argument after "mod"
 * is a valid integer.
 * If not, prints an error message and exits.
 * Modulos the integer from the stack or queue.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void mod_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	int result;				/* Variable to hold the result of the modulo operation */
	stack_t *temporaryPointer;	/* Temporary pointer for stack manipulation */
	char errorMessage[50];		/* Array to hold error messages */
	/* Check if the stack does not have at least two elements */
	if (*head == NULL || (*head)->next == NULL)
	{
		/* Format and send error message to stderr */
		sprintf(errorMessage, "L%u: can't mod, stack too short\n",
		theNumberOfTheLine);
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		/* Exit program with a failure status */
		exit(EXIT_FAILURE);
	}
	/* Check if the top element of the stack */
	/* is zero to prevent division by zero */
	if ((*head)->n == 0)
	{
		/* Format and send division by zero error message to stderr */
		sprintf(errorMessage, "L%u: division by zero\n", theNumberOfTheLine);
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		/* Exit program with a failure status */
		exit(EXIT_FAILURE);
	}
	/* Perform the modulo operation using the top */
	/* two elements and store the result */
	result = ((*head)->next->n) % ((*head)->n);
	/* Update the second element from the top with the result */
	(*head)->next->n = result;
	/* Point the temporary pointer to the top element of the stack */
	temporaryPointer = *head;
	/* Move the head pointer to the next element in the stack */
	*head = (*head)->next;
	/* If the stack is not empty, set */
	/* the previous pointer of the new head to NULL */
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	/* Free the memory of the element that was at the top of the stack */
	free(temporaryPointer);
}
