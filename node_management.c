#include "monty.h"

/**
 * add_node - Insert a new node at the start of a stack_t linked list.
 * @head: Double pointer referencing the top of the stack.
 * @n: value of new node
 *
 * Return: Memory address of the new element, or NULL if the operation failed.
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}

/**
 * free_stack - Deallocate memory used by a stack.
 * @head: Reference to the stack's head.
 */

void free_stack(stack_t **head)
{
	stack_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

/**
 * add_node_end - Insert a new node at the end of a stack_t linked list.
 * @head: Double pointer pointing to the top of the stack.
 * @n: value of new node
 *
 * Return: Memory address of the new element, or NULL if the operation failed.
 */

stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *last = *head;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;

	if (!*head)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (last->next)
		last = last->next;

	last->next = new;
	new->prev = last;

	return (new);
}
