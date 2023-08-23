#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef unsigned int uint;

/**
 * struct stack_s - Doubly Linked List Node
 * for Representing a Stack (or Queue)
 * @n: Integer value
 * @prev: Previous node
 * @next: Next node
 *
 * Description: Defines a node in a list for stack,
 * queue operations at Holberton.
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, uint line_number);
} instruction_t;

/**
 * enum format_e - Format of the data
 * @STACK: Stack (LIFO) format
 * @QUEUE: Queue (FIFO) format
 *
 * Format of the data for the Monty bytecode interpreter
 */

typedef enum format_e
{
	STACK,
	QUEUE
} format_t;

/**
 * struct global_s - structure holding global variables
 * for Monty interpreter
 * @fp: file pointer to Monty bytecode file
 * @line: buffer for storing lines using getline
 * @len: length of the line retrieved by getline
 * @nread: count of characters read using getline
 * @line_number: current line number in the Monty bytecode file
 * @stack: pointer to the top of the stack
 * @format: data format (stack or queue)
 *
 * Purpose: This structure encapsulates global variables used
 * by the Monty interpreter.
 */

typedef struct global_s
{
	FILE *fp;
	char *line;
	size_t len;
	ssize_t nread;
	uint line_number;
	stack_t *stack;
	format_t format;
} global_t;

extern global_t data;

/* stack_utils1.c */
void _push(stack_t **stack, uint line_number);
void _pall(stack_t **stack, uint line_number);
void _pint(stack_t **stack, uint line_number);
void _pop(stack_t **stack, uint line_number);
void _add(stack_t **stack, uint line_number);
/* stack_utils2.c */
void _nop(stack_t **stack, uint line_number);
void _sub(stack_t **stack, uint line_number);
void _div(stack_t **stack, uint line_number);
void _mul(stack_t **stack, uint line_number);
void _mod(stack_t **stack, uint line_number);
/* stack_utils3.c */
void _swap(stack_t **stack, uint line_number);
void _pchar(stack_t **stack, uint line_number);
void _pstr(stack_t **stack, uint line_number);
void _rotl(stack_t **stack, uint line_number);
void _rotr(stack_t **stack, uint line_number);
/* data_format.c */
void _stack(stack_t **stack, uint line_number);
void _queue(stack_t **stack, uint line_number);

/* opcode_parser.c */
int is_number(char *str);
void (*get_op_func(char *opcode))(stack_t **stack, uint line_number);
void parse_line(void);

/* node_management.c */
stack_t *add_node(stack_t **head, const int n);
void free_stack(stack_t **head);
stack_t *add_node_end(stack_t **head, const int n);

#endif /* MONTY_H */
