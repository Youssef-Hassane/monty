#include "monty.h"


/**
 * pint_operation - Handles the "pint" operation.
 * Return: None.
 * --------------------------
 * Prototype: void pint_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @counter: Current line number in the script file.
 * --------------------------
 * Description: Prints the value at the top of the stack.
 * If the stack is empty, prints an error message and exits.
 * --------------------------
 * By Youssef Hassane AKA Almasy
*/
void pint_operation(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(montyExecutionContext.theFile);
		free(montyExecutionContext.theBuffer);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
