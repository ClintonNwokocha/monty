#include "monty.h"

bus_t bus;

/**
 * is_valid_number - checks if a string is a valid integer
 * @str: string to check
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_number(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * e_push - add node to the stack
 * @head: stack head
 * @element: line_number
 * Return: no return
 */
void e_push(stack_t **head, unsigned int line_number)
{
	int n;

	if (bus.arg == NULL || !is_valid_number(bus.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
