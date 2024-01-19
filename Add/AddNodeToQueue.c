#include "../monty.h"

/**
 * AddNodeToQueue - Adds a node to the queue.
 * Return: None.
 * --------------------------
 * Prototype: void AddNodeToQueue(stack_t **head, int n);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @ValueToBeAdded: Value to be added to the queue.
 * --------------------------
 * Description: Allocates memory for a new node,
 * sets its value, and adds it to the end of the queue.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void AddNodeToQueue(stack_t **head, int ValueToBeAdded)
{
	/*Declare pointers for the new node and the current top of the stack*/
	stack_t *newNode, *currentTop;
	/* Set currentTop to point to the current top of the stack */
	currentTop = *head;
	/* Allocate memory for the new node */
	newNode = malloc(sizeof(stack_t));
	/* Check if memory allocation was successful */
	if (newNode == NULL)
	{
		write(STDERR_FILENO, "Error\n", 6);
	}
	/* Set the value of the new node */
	(*newNode).n = ValueToBeAdded;
	/* Set the next pointer of the new node to */
	/* NULL (since it's the last in the queue) */
	(*newNode).next = NULL;
	/* If the stack is not empty, find the last node in the queue */
	if (currentTop)
	{
		while (currentTop->next)
			currentTop = (*currentTop).next;
	}
	/* If the stack is empty, update the head to point to the new node */
	if (!currentTop)
	{
		*head = newNode;
		(*newNode).prev = NULL;
	}
	else
	{
		/* If the stack is not empty, update pointers to */
		/* add the new node to the end of the queue */
		(*currentTop).next = newNode;
		(*newNode).prev = currentTop;
	}
}
