#include "monty.h"
#define ERR_MESSAGE "L%d: unknown instruction %s\n"
/**
 * get_op_func - Select the function according to the opcode.
 * @line: Line number of file
 * Return: 0 (success).
 */

void (*get_op_func(int line))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode_fun[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", diva},
		{"mul", mul},
		{"mod", moda},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	int pos_op = 0;

	while (opcode_fun[pos_op].opcode)
	{
		if (strcmp(opcode_fun[pos_op].opcode, c_args.opcode[0]) == 0)
		{
			return (opcode_fun[pos_op].f);
		}
		pos_op++;
	}
	dprintf(STDERR_FILENO, ERR_MESSAGE, line, c_args.opcode[0]);
	free_all();
	exit(EXIT_FAILURE);
}
