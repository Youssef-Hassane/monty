#include "monty.h"

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
	char error_message[100];

	if (*head == NULL)
	{
		sprintf(error_message, "L%u: can't pint, stack empty\n", theNumberOfTheLine);
		write(STDERR_FILENO, error_message, strlen(error_message));
		fclose(montyExecutionContext.theFile);
		free(montyExecutionContext.theBuffer);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
