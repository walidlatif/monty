#include "monty.h"

/**
 * _nop - does nothing
 * @stack: A reference pointing to the stack's head.
 * @line_number: The line number that corresponds to
 * the currently executing command.
 */

void _nop(stack_t **stack, uint line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - Perform the subtraction of the top two
 * elements in the stack.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number corresponding to
 * the currently executed command.
 */

void _sub(stack_t **stack, uint line_number)
{
	int diff;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	diff = (*stack)->next->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = diff;
	free(temp);
}

/**
 * _div - The line number associated with the
 * currently executed command.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number associated with
 * the currently executed command.
 */

void _div(stack_t **stack, uint line_number)
{
	int quotient;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = quotient;
	free(temp);
}

/**
 * _mul - Perform multiplication on the top two
 * elements of the stack.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number corresponding to the
 * currently executed command.
 */

void _mul(stack_t **stack, uint line_number)
{
	int product;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = product;
	free(temp);
}

/**
 * _mod - Calculate the remainder of the second highest
 * element in the stack.
 * @stack: Reference to the stack's head pointer.
 * @line_number: The line number corresponding to the
 * currently executed command.
 */

void _mod(stack_t **stack, uint line_number)
{
	int remainder;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = remainder;
	free(temp);
}
