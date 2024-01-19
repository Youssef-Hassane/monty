#include "../monty.h"

/**
 * rotr_operation - Handles the "rotr" operation.
 * Return: None.
 * --------------------------
 * Prototype: void rotr_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Rotates the stack to the right.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void rotr_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Declare a temporary pointer */
	stack_t *temporaryPointer = NULL;

	/* Unused variable */
	(void)theNumberOfTheLine;

	/* Nothing to rotate if the stack is empty or has only one node */
	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	/* Get the last node */
	temporaryPointer = *head;
	while (temporaryPointer->next != NULL)
		temporaryPointer = temporaryPointer->next;

	/* Detach the last node and update the links */
	if (temporaryPointer->prev)
		temporaryPointer->prev->next = NULL;

	if (*head != temporaryPointer)
	{
		temporaryPointer->prev->next = NULL;
		temporaryPointer->prev = NULL;
		temporaryPointer->next = *head;
		(*head)->prev = temporaryPointer;
		*head = temporaryPointer;
	}
}
