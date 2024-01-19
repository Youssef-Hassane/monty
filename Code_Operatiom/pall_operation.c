#include "../monty.h"

/**
 * pall_operation - Handles the "pall" operation.
 * Return: None.
 * --------------------------
 * Prototype: void f_pall(stack_t **head, unsigned int counter);
 * --------------------------
 * @head: Pointer to the top of the stack.
 * @theNumberOfTheLine: Current line number in the script file.
 * --------------------------
 * Description: prints all elements in the stack.
 * --------------------------
 * By Youssef Hassane AKA Almasy
 */

void pall_operation(stack_t **head, unsigned int theNumberOfTheLine)
{
	/* Traverse the stack and write each element to standard output */
	/* char buffer[12]; */
	/* int numDigits; */
	/* Declare a pointer to the top of the stack */
	stack_t *pointerToTheTop;
	/* Suppress compiler warning about an unused variable */
	(void)theNumberOfTheLine;
	/* Initialize the pointer with the address of the top of the stack */
	pointerToTheTop = *head;
	/* Check if the stack is empty */
	if (pointerToTheTop == NULL)
	{
		/* If the stack is empty, return early */
		return;
	}
	while (pointerToTheTop)
	{
		/* numDigits = sprintf(buffer, "%d\n", pointerToTheTop->n); */
		/* write(STDOUT_FILENO, buffer, numDigits); */
		printf("%d\n", pointerToTheTop->n);
		pointerToTheTop = pointerToTheTop->next;
	}
}
