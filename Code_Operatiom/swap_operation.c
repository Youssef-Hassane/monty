#include "../monty.h"

/**
 * swap_operation - Handles the "swap" operation.
 * Return: None.
 * --------------------------
 * Prototype: void swap_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Swaps the top two elements of the stack.
 * If the stack has less than 2 elements, prints an error message and exits.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void swap_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Declare a temporary pointer */
	stack_t *temporaryPointer;
	/* Declare an error message buffer */
	char errorMessage[50];
	/* Check if the stack is empty or has only one element */
	if (*head == NULL || (*head)->next == NULL)
	{
		/* Format the error message */
		sprintf(errorMessage, "L%u: can't swap, stack too short\n",
		theNumberOfTheLine);
		/* Write the error message to stderr */
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		/* Exit with failure status */
		exit(EXIT_FAILURE);
	}
	/* Store the second node in temp */
	temporaryPointer = (*head)->next;
	/* Link the first node to the third node */
	(*head)->next = temporaryPointer->next;
	/* Place the first node after the second node */
	temporaryPointer->next = *head;
	/* Update the head to the second node */
	*head = temporaryPointer;
}
