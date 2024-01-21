#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its functiom
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - carries various data throughout the program
 * @arg: argument to the curreeent opcode
 * @file: file pointer to Monty bytecodes file
 * @content: content from the file
 * @lifi: flag to indicate stack (0) or queue (1) mode
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

extern bus_t bus;

void e_push(stack_t **head, unsigned int line_number);
void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void e_pall(stack_t **stack, unsigned int line_number);
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file);

#endif
