#include "../monty.h"

/**
 * add_operation - Handles the "add" operation.
 * Return: None.
 * --------------------------
 * Prototype: void add_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Checks if the argument after "add"
 * is a valid integer.
 * If not, prints an error message and exits.
 * Adds the integer to the stack or queue.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void add_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Declare a temporary pointer */
	stack_t *temporaryPointer;
	char errorMessage[50];

	/* Check if the stack has less than two elements */
	if (*head == NULL || (*head)->next == NULL)
	{
		sprintf(errorMessage, "L%d: can't add, stack too short\n",
		theNumberOfTheLine);
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		fclose(montyExecutionContext.theFile);
		FREE_VARIABLE(montyExecutionContext.theBuffer);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	/* Add the top two elements of the stack */
	(*head)->next->n += (*head)->n;
	/* Store the pointer to the second element */
	temporaryPointer = *head;
	/* Move the top pointer to the second element */
	*head = (*head)->next;
	/* Remove the top element from the stack */
	free(temporaryPointer);
	/* Set the next pointer of the new top element to NULL */
	(*head)->prev = NULL;
}
