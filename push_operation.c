#include "monty.h"

/**
 * push_operation - Handles the "push" operation.
 * Return: None.
 * --------------------------
 * Prototype: void f_push(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Checks if the argument after "push"
 * is a valid integer.
 * If not, prints an error message and exits.
 * Adds the integer to the stack or queue.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void push_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	char lineNumberString[12];

	Integer pushedValue;

	sprintf(lineNumberString, "%u", theNumberOfTheLine);

	if (!montyExecutionContext.theArgument ||
	    !is_valid_integer(montyExecutionContext.theArgument))
	{
		handle_push_error(theNumberOfTheLine, head);
	}

	pushedValue = atoi(montyExecutionContext.theArgument);

	if (montyExecutionContext.theMode == 0)
	{
		addNodeToStack(head, pushedValue);
	}
	else
	{
		AddNodeToQueue(head, pushedValue);
	}
}

/**
 * handle_push_error - Prints an error message and exits.
 * Return: None.
 * --------------------------
 * Prototype: void handle_push_error(
 *    unsigned int theNumberOfTheLine, stack_t **head
 *);
 * --------------------------
 * @theNumberOfTheLine: Current line number in the script file.
 * @head: Pointer to the top of the stack.
 * --------------------------
 * Description: Prints an error message and exits.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void handle_push_error(unsigned int theNumberOfTheLine, stack_t **head)
{
	char lineNumberString[12];

	sprintf(lineNumberString, "%u", theNumberOfTheLine);

	write(STDERR_FILENO, "L", 1);
	write(STDERR_FILENO, lineNumberString, sizeof(lineNumberString) - 1);
	write(STDERR_FILENO, ": usage: push integer\n", 22);

	
	fclose(montyExecutionContext.theFile);
	FREE_VARIABLE(montyExecutionContext.theBuffer);
	release_stack(*head);
	exit(EXIT_FAILURE);
}

/**
 * is_valid_integer - Checks if the argument is a valid integer.
 * Return: 1 if the argument is a valid integer, 0 otherwise.
 * --------------------------
 * Prototype: int is_valid_integer(const char *arg);
 * --------------------------
 * @theArgument: Argument to check.
 * --------------------------
 * Description: Checks if the argument is a valid integer.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

int is_valid_integer(const char *theArgument)
{
	int index = 0;

	if (!theArgument || *theArgument == NULL_TERMINATOR)
	{
		return (ZERO);
	}

	if (theArgument[ZERO] == '-')
	{
		index = 1;
	}

	while (theArgument[index] != NULL_TERMINATOR)
	{
		if (!isdigit(theArgument[index]))
		{
			return (ZERO);
		}
		INCREASE_BY_ONE(index);
	}

	return (ONE);
}
