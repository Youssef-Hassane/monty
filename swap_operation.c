#include "monty.h"

/**
 * swap_operation - Handles the "swap" operation.
 * Return: None.
 * --------------------------
 * Prototype: void swap_operation(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: Swaps the top two elements of the stack.
 * If the stack has less than 2 elements, prints an error message and exits.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void swap_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", theNumberOfTheLine);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
}
