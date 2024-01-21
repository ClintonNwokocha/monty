#include "monty.h"

/**
 * free_stack - frees a stack.
 * @head: Pointer to the head of the stack.
 */
void free_stack(stack_t *head)
{
	stack_t *temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
