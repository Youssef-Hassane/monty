#include "monty.h"







void display_stack_contents(stack_t **top, unsigned int unused_line_num)
{
	stack_t *current;

	(void)unused_line_num;
	if (top == NULL)
		exit(EXIT_FAILURE);
	current = *top;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

