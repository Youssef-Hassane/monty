#include "../monty.h"

/**
 * mul_operation - Handles the "mul" operation.
 * Return: None.
 * --------------------------
 * Prototype: void mul_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Checks if the argument after "mul"
 * is a valid integer.
 * If not, prints an error message and exits.
 * Multiplies the integer from the stack or queue.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void mul_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Pointer to temporarily hold the top of the stack */
	stack_t *temporaryPointer;
	/* Variable to store the result of multiplication */
	int result;
	/* Buffer to hold error messages */
	char errorMessage[50];
	/* Check if the stack is too short to perform multiplication */
	if (*head == NULL || (*head)->next == NULL)
	{
		/* Prepare error message */
		sprintf(errorMessage, "L%u: can't mul, stack too short\n",
		theNumberOfTheLine);
		/* Write error message to stderr */
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		/* Exit with failure status */
		exit(EXIT_FAILURE);
	}
	/* Perform multiplication of the top two elements in the stack */
	result = ((*head)->next->n) * ((*head)->n);
	/* Store result in the second element from the top */
	(*head)->next->n = result;

	/* Set temporaryPointer to the top of the stack */
	temporaryPointer = *head;
	/* Move head to the next element in the stack */
	*head = (*head)->next;
	/* If the stack is not empty, set previous of the new head to NULL */
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	/* Free the original top element of the stack */
	FREE_VARIABLE(temporaryPointer);
}
