#include "monty.h"

/**
 * addnode - Adds a new node at the beginning of the stack.
 * @head: Double pointer to the head of the stack.
 * @n: The value of the new node.
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
}
