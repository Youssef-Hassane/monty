#include "../monty.h"

/**
 * rotl_operation - Handles the "rotl" operation.
 * Return: None.
 * --------------------------
 * Prototype: void rotl_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Rotates the stack to the left.
 * If the stack is empty, prints an error message and exits.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void rotl_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	stack_t *theFirst = NULL;
	stack_t *theLast = NULL;
	/* Unused variable */
	(void)theNumberOfTheLine;
	/* Nothing to rotate if the stack is empty or has only one node */
	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	theFirst = *head;
	theLast = *head;
	/* Traverse to the end of the stack */
	while (theLast->next != NULL)
		theLast = theLast->next;
	/* The second element becomes the top */
	*head = theFirst->next;
	/* Set new top's prev to NULL */
	theFirst->next->prev = NULL;
	/* Detach the first node from the stack */
	theFirst->next = NULL;
	/* Add the first node to the end */
	theLast->next = theFirst;
	/* Maintain the double link */
	theFirst->prev = theLast;
}
