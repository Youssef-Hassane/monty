#include "../monty.h"

/**
 * addNodeToStack - Adds a node to the stack.
 * Return: None.
 * --------------------------
 * Prototype: void addNodeToStack(stack_t **head, int ValueToBeAdded);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @ValueToBeAdded: Value to be added to the new node.
 * --------------------------
 * Description: Allocates memory for a new node,
 * sets its value, and adds it to the top of the stack.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void addNodeToStack(stack_t **head, int ValueToBeAdded)
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
		/* If malloc fails, write an error message to stderr and exit */
		write(STDERR_FILENO, "Error\n", 6);
		exit(ZERO);
	}
	/* If the stack is not empty, update the prev pointer of the current top */
	if (currentTop)
	{
		(*currentTop).prev = newNode;
	}
	/* Set the value of the new node */
	(*newNode).n = ValueToBeAdded;
	/* Update pointers to add the new node to the top of the stack */
	(*newNode).next = *head;
	(*newNode).prev = NULL;
	*head = newNode;
}
