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
	Integer theValueToBePushed, characterIndex = 0, theMode = 0;
	/* char lineNumStr[12]; */
	/* sprintf(lineNumStr, "%u", theNumberOfTheLine); */
	if (montyExecutionContext.theArgument)
	{
		if (montyExecutionContext.theArgument[0] == DASH)
			INCREASE_BY_ONE(characterIndex);
		while (montyExecutionContext.theArgument[characterIndex] != NULL_TERMINATOR)
		{
			if (montyExecutionContext.theArgument[characterIndex] > 57 ||
			    montyExecutionContext.theArgument[characterIndex] < 48)
				theMode = 1;
			INCREASE_BY_ONE(characterIndex);
		}
		if (theMode == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", theNumberOfTheLine);
			fclose(montyExecutionContext.theFile);
			FREE_VARIABLE(montyExecutionContext.theBuffer);
			release_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", theNumberOfTheLine);
		fclose(montyExecutionContext.theFile);
		FREE_VARIABLE(montyExecutionContext.theBuffer);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	theValueToBePushed = atoi(montyExecutionContext.theArgument);
	if (montyExecutionContext.theMode == 0)
		addNodeToStack(head, theValueToBePushed);
	else
		AddNodeToQueue(head, theValueToBePushed);
}
