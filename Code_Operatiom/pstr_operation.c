#include "../monty.h"
#include <ctype.h>

/**
 * pstr_operation - Handles the "pstr" operation.
 * Return: None.
 * --------------------------
 * Prototype: void pstr_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Prints the string at the top of the stack.
 * If the stack is empty, prints an error message and exits.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void pstr_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Initialize a pointer to the current node in the stack */
	stack_t *current = *head;
	/* Cast theNumberOfTheLine to void to avoid unused variable warning */
	(void)theNumberOfTheLine;

	/* Loop through the stack until a non-printable character */
	/* or the end of the stack is reached */
	while (current && isprint(current->n))
	{
		/* Cast the integer value to a char and print it */
		putchar((char)current->n);
		/* Move to the next node in the stack */
		current = current->next;
	}
	/* Print a newline character after the string */
	putchar('\n');
}
