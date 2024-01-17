#define _POSIX_C_SOURCE 200809L

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

stack_t *head = NULL;

/**
 * main - entry point of the program
 * Return: 0 on success
 * -------------------------
 * @argumentCounter: number of arguments
 * @argumentVector: list of arguments
 * -------------------------
 * By Youssef Hassane AKA Almasy
 */

Integer main(Integer argumentCounter, StringArray argumentVector)
{
	FILE *theFile;
	String theBuffer, codeOperation, theToken;
	ULI theSizeOfTheBuffer;
	Integer stackOrQueue, theNumberOfTheLine = ONE;

	if (argumentCounter != TWO)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	theFile = fopen(argumentVector[ONE], READ);
	if (!theFile)
	{
		write(STDERR_FILENO, "Error: Can't open file ", 23);
		write(STDERR_FILENO, argumentVector[ONE], strlen(argumentVector[ONE]));
		write(STDERR_FILENO, NEW_LINE, ONE);
		exit(EXIT_FAILURE);
	}
	while (getline(&theBuffer, &theSizeOfTheBuffer, theFile) != -1)
	{
		if (theBuffer == NULL)
			write(STDERR_FILENO, "Error: malloc failed\n", 21);
		codeOperation = strtok(theBuffer, THE_DELIMITERS);
		if (codeOperation == NULL)
			continue;
		theToken = strtok(NULL, THE_DELIMITERS);
		if (strcmp(codeOperation, STACK) == ZERO)
			stackOrQueue = 0;
		else if (strcmp(codeOperation, QUEUE) == ZERO)
			stackOrQueue = 1;
		else
			select_Function(codeOperation, theToken, theNumberOfTheLine, stackOrQueue);
		INCREASE_BY_ONE(theNumberOfTheLine);
	}
	fclose(theFile);
	return (0);
}

void select_Function(
	String codeOperation, String theToken,
	Integer theNumberOfTheLine, Integer stackOrQueue)
{
	int theIndex = 0, theIndex_2;
	int matchingCodeOperation = 1, localMatchingCodeOperation;
	stack_t *node;

	instruction_t allTheFunctions[] = {
	    {"push", push_to_stack}, /* Task 0 */
	    {"pall", display_stack_contents},  /* Task 0 */
	    {NULL, NULL}};
	if (codeOperation[ZERO] == HASH)
		return;
	while (allTheFunctions[theIndex].codeOperation != NULL)
	{
		if (strcmp(codeOperation, allTheFunctions[theIndex].codeOperation) == 0)
		{
			localMatchingCodeOperation = 1;
			if (strcmp(codeOperation, "push") == 0)
			{
				if (theToken != NULL && theToken[0] == '-')
				{
					theToken = theToken + 1;
					localMatchingCodeOperation = -1;
				}
				if (theToken == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", theNumberOfTheLine);
					release_stack();
					exit(EXIT_FAILURE);
				}
				for (theIndex_2 = 0; theToken[theIndex_2] != '\0'; theIndex_2++)
				{
					if (isdigit(theToken[theIndex_2]) == 0)
					{
						fprintf(stderr, "L%d: usage: push integer\n", theNumberOfTheLine);
						release_stack();
						exit(EXIT_FAILURE);
					}
				}
				node = allocate_new_node(atoi(theToken) * localMatchingCodeOperation);
				if (stackOrQueue == 0)
					allTheFunctions[theIndex].f(&node, theNumberOfTheLine);
				if (stackOrQueue == 1)
					enqueue(&node, theNumberOfTheLine);
			}
			else
				allTheFunctions[theIndex].f(&head, theNumberOfTheLine);

			matchingCodeOperation = 0;
		}
		INCREASE_BY_ONE(theIndex);
	}
	if (matchingCodeOperation == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", theNumberOfTheLine, codeOperation);
		release_stack();
		exit(EXIT_FAILURE);
	}
}


void release_stack(void)
{
	stack_t *current_node;

	if (!head)
		return;

	while (head)
	{
		current_node = head;
		head = current_node->next;
		free(current_node);
	}
}


void enqueue(stack_t **node, __attribute__((unused)) unsigned int line_num)
{
	stack_t *tail;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *node;
	}
	else
	{
		tail = head;
		while (tail->next != NULL)
			tail = tail->next;

		tail->next = *node;
		(*node)->prev = tail;
	}
}

stack_t *allocate_new_node(int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		exit(4); // Error code 4 indicates malloc failure
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = value;
	return new_node;
}


void push_to_stack(stack_t **node, __attribute__((unused)) unsigned int ln)
{
	stack_t *top;

	if (!node || !*node)
		exit(EXIT_FAILURE);

	(*node)->next = head;
	if (head)
		head->prev = *node;
	head = *node;
}
