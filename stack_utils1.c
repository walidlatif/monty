#include "monty.h"

/**
 * _push - Adds an element to the top of the stack.
 *
 * This function adds a new element to the top of the stack.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number where the push operation is called.
 */

void _push(stack_t **stack, uint line_number)
{
	int n;
	char *arg;

	arg = strtok(NULL, " \n\t");
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);

	if (data.format == STACK)
		add_node(stack, n);
	else
		add_node_end(stack, n);
}

/**
 * _pall - Prints all values on the stack, starting from the top.
 *
 * This function prints all the values stored in the stack, beginning from
 * the top element and moving downwards.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number where the pall command is executed.
 */

void _pall(stack_t **stack, uint line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - Display the value located at the top of the stack.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number corresponding to the executed command.
 */

void _pint(stack_t **stack, uint line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - Pop the top element from the stack.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number corresponding to the executed command.
 */

void _pop(stack_t **stack, uint line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * _add - Sum the top two elements of the stack.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number associated with
 * the currently executed command.
 */

void _add(stack_t **stack, uint line_number)
{
	int sum;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;

	free(temp);
}
