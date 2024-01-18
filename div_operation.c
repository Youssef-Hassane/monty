#include "monty.h"

/**
 * div_operation - Handles the "div" operation.
 * Return: None.
 * --------------------------
 * Prototype: void div_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Checks if the argument after "div"
 * is a valid integer.
 * If not, prints an error message and exits.
 * Divides the integer from the stack or queue.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void div_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Declare a temporary pointer */
	stack_t *temporaryPointer;
	int result;
	char errorMessage[50];

	/* Check if the stack contains less than two elements */
	if (*head == NULL || (*head)->next == NULL)
	{
		sprintf(errorMessage, "L%u: can't div, stack too short\n",
		theNumberOfTheLine);
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		exit(EXIT_FAILURE);
	}

	/* Check if the top element of the stack is 0 */
	if ((*head)->n == 0)
	{
		sprintf(errorMessage, "L%u: division by zero\n", theNumberOfTheLine);
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		exit(EXIT_FAILURE);
	}

	/* Perform the division and store the result */
	result = ((*head)->next->n) / ((*head)->n);

	/* Update the second top element of the stack with the result */
	(*head)->next->n = result;

	/* Remove the top element from the stack */
	temporaryPointer = *head;
	*head = (*head)->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	FREE_VARIABLE(temporaryPointer);
}

