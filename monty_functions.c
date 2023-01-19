#include "monty.h"

/**
 * push - adds a new node at the end of a stack_t list.
 * @stack: pointer to head element of list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *tmp = *stack;

	if (c_args.opcode[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_all();
	}
	is_number(line_number);
	new = malloc(sizeof(stack_t));
	if (new != NULL)
	{
		new->n = atoi(c_args.opcode[1]);
		new->prev = NULL, new->next = NULL;
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(new);
		free_all();
	}
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
}

/**
 * pall - prints all elements of a stack ist.
 * @stack: pointer to head element of stack list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int num = 0;
	stack_t *tmp = *stack;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
		return;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	for (num = 0; tmp != NULL; num++)
	{
		if (tmp == NULL)
			return;

		printf("%i\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
 * free_stack - Free a list.
 * @stack: pointer to head element of list
 *
 * Return: Nothing
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
}

/**
 * free_all - Free a list.
 * Return: Nothing
 */
void free_all(void)
{
	free_grid(c_args.opcode);
	free_stack(c_args.head);
	fclose(c_args.fd);
	exit(EXIT_FAILURE);
}

/**
 * is_number - Verify if opcode is a number
 * @line_number: Error line number
 *
 * Return: Nothing
 */
void is_number(unsigned int line_number)
{
	int i, start = 0;

	if (c_args.opcode[1][0] == '-' && c_args.opcode[1][1] != 0)
		start = 1;

	for (i = start; c_args.opcode[1][i] != 0; i++)
	{
		if (c_args.opcode[1][i] < '0' || c_args.opcode[1][i] > '9')
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			free_all();
		}
	}
}
