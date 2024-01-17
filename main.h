#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>


typedef char *String;
typedef char **StringArray;
typedef int Integer;
typedef unsigned long int ULI;

#define THE_DELIMITERS " \t\n"
#define READ "r"
#define ZERO 0
#define ONE 1
#define TWO 2
#define INCREASE_BY_ONE(x) (x++)
#define NEW_LINE "\n"
#define STACK "stack"
#define QUEUE "queue"
#define HASH '#'

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @codeOperation: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *codeOperation;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;







void select_Function(
	String codeOperation, String theToken,
	Integer theNumberOfTheLine, Integer stackOrQueue);

void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln);
void display_stack_contents(stack_t **stack, unsigned int line_number);
void release_stack(void);
void enqueue(stack_t **new_node, __attribute__((unused))unsigned int ln);
stack_t *allocate_new_node(int n);

#endif
