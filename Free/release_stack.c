#include "../monty.h"

/**
 * release_stack - Frees the memory allocated to the stack
 * and its nodes.
 * Return: None.
 * --------------------------
 * Prototype: void release_stack(stack_t *top);
 * --------------------------
 * @top: Pointer to the top of the stack.
 * --------------------------
 * By Youssef Hassane AKA Almasy
*/

void release_stack(stack_t *top)
{
	/* Temporary pointer to traverse the stack */
	stack_t *temporaryVariable;
	/* Initialize the temporary variable with the top of the stack */
	temporaryVariable = top;
	/* Loop until we reach the end of the stack */
	while (top != NULL)
	{
		/* Move temporaryVariable to the next node */
		temporaryVariable = (*top).next;
		/* Free the current node */
		FREE_VARIABLE(top);
		/* Move top to the next node */
		top = temporaryVariable;
	}
}
