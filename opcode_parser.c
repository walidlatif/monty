#include "monty.h"

/**
 * is_number - Verify whether a given string is a numerical value.
 * @str: string to check
 * Return: 1 if true, 0 if false
 */

int is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * get_op_func - Reference to the function associated with the provided opcode.
 * @opcode: opcode string
 * Return: pointer to the corresponding function or NULL if not found
 */

void (*get_op_func(char *opcode))(stack_t **stack, uint line_number)
{
	int i;
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
		};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
	}
	return (NULL);
}

/**
 * parse_line - parse a line of input from a Monty bytecode file
 */

void parse_line(void)
{
	char *opcode;
	void (*op_func)(stack_t **stack, uint line_number);

	opcode = strtok(data.line, " \n\t");

	if (opcode == NULL || opcode[0] == '#')
		return;

	op_func = get_op_func(opcode);
	if (op_func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				data.line_number, opcode);
		exit(EXIT_FAILURE);
	}
	op_func(&data.stack, data.line_number);
}
