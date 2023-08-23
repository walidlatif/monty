#include "monty.h"

/**
 * _stack - Configure the data format as STACK.
 * @stack: Reference to the unused stack head pointer.
 * @line_number: The line number of the unused command being executed.
 */

void _stack(stack_t **stack, uint line_number)
{
	(void)stack;
	(void)line_number;
	data.format = STACK;
}

/**
 * _queue - Configure the data format as QUEUE.
 * @stack: Reference to the unused stack head pointer.
 * @line_number: The line number of the unused command being executed.
 */

void _queue(stack_t **stack, uint line_number)
{
	(void)stack;
	(void)line_number;
	data.format = QUEUE;
}
