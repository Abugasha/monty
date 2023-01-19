#include "monty.h"
#define BUFFER_SIZE 1024
creator_args c_args;
/**
 * main - This receives the data path
 * from the monty file.
 * @ac: quantity of arguments received.
 * @av: filepath of the monty bytecode.
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;
	struct stat st;
	char buf[BUFFER_SIZE], **opcode = NULL;
	int data_length = 0, line_counter = 1;
	stack_t *head = NULL;
	void (*pointer_to_function)(stack_t**, unsigned int);

	c_args.opcode = opcode, c_args.fd = fd, c_args.head = head;
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (stat(av[1], &st) != 0 || access(av[1], R_OK) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	c_args.fd = open_file(av[1]);
	while (fgets(buf, BUFFER_SIZE, c_args.fd) != NULL)
	{
		c_args.opcode = extract_string(buf, &data_length);
		if (c_args.opcode[0] != NULL && c_args.opcode[0][0] != '#')
		{
			pointer_to_function = get_op_func(line_counter);
			(*pointer_to_function)(&c_args.head, line_counter);
		}
		line_counter++;
		free_grid(c_args.opcode);
		data_length = 0;
	}
	free_stack(c_args.head);
	fclose(c_args.fd);
	return (0);
}
