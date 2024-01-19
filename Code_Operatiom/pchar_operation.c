#include "../monty.h"

/**
 * pchar_operation - Handles the "pchar" operation.
 * Return: None.
 * --------------------------
 * Prototype: void pchar_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Prints the character at the top of the stack.
 * If the stack is empty, prints an error message and exits.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void pchar_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Buffer for error messages */
	char error_message[100];
	/* Check if the stack is empty */
	if (*head == NULL)
	{
		/* Format and write an error message to stderr */
		sprintf(error_message, "L%u: can't pchar, stack empty\n",
		theNumberOfTheLine);
		write(STDERR_FILENO, error_message, strlen(error_message));
		/* Close the file and cleanup resources */
		fclose(montyExecutionContext.theFile);
		FREE_VARIABLE(montyExecutionContext.theBuffer);
		release_stack(*head);
		/* Exit the program with a failure status */
		exit(EXIT_FAILURE);
	}
	/* Check if the value at the top of the stack is within ASCII range */
	if ((*head)->n < ZERO || (*head)->n > 127)
	{
		/* Format and write an error message to stderr for out of range values */
		sprintf(error_message, "L%u: can't pchar, value out of range\n",
		theNumberOfTheLine);
		write(STDERR_FILENO, error_message, strlen(error_message));
		/* Close the file and cleanup resources */
		fclose(montyExecutionContext.theFile);
		FREE_VARIABLE(montyExecutionContext.theBuffer);
		release_stack(*head);
		/* Exit the program with a failure status */
		exit(EXIT_FAILURE);
	}
	/* Print the character at the top of the stack */
	printf("%c\n", (char)((*head)->n));
}
