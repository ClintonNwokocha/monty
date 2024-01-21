#include "monty.h"

/**
 * e_pall - prints all the values on the stack from the top.
 * @stack: double pointer to the top of the stack.
 * @line_number: line number in the script.
 * Return: prints all values on stack.
 */
void e_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
