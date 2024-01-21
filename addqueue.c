#include "monty.h"

/**
 * addqueue - Adds a new node at the end of the queue.
 * @head: Double pointer to the head of the queue.
 * @n: The value for the new node.
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *last = *head;
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_node;
	new_node->prev = last;
}
