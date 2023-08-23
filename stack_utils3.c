#include "monty.h"

/**
 * _swap - Exchange the positions of the top
 * two elements in the stack.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number associated with
 * the currently executed command.
 */

void _swap(stack_t **stack, uint line_number)
{
	int temp;

	if (!*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * _pchar - Display the character located at the top of the stack.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number associated with
 * the currently executed command.
 */

void _pchar(stack_t **stack, uint line_number)
{
	int c;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	c = (*stack)->n;
	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}

/**
 * _pstr - Output the string beginning from
 * the top of the stack.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number associated with
 * the currently executed command.
 */

void _pstr(stack_t **stack, uint line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * _rotl - Rotate the elements of the stack to the left.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number associated with
 * the currently executed command.
 */

void _rotl(stack_t **stack, uint line_number)
{
	stack_t *temp, *last;

	(void)(line_number);

	if (!*stack || !(*stack)->next)
		return;

	temp = *stack;
	last = *stack;

	while (last->next)
		last = last->next;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
}

/**
 * _rotr - Rotate the stack to the right
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number associated with
 * the currently executed command.
 */

void _rotr(stack_t **stack, uint line_number)
{
	stack_t *temp, *last;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	temp->prev = last;
	last->next = temp;
	*stack = last;
}
