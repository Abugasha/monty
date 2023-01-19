#include "monty.h"
/**
 * rotl - rotates stack to the left
 * @stack: pointer to head element of stack list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack, *origin = *stack;

	(void) line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->prev->next = NULL;
	tail->next = origin;
	tail->prev = NULL;
	origin->prev = tail;
	*stack = tail;
}

/**
 * rotr - rotates stack to the right
 * @stack: pointer to head element of stack list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack, *origin = *stack;

	(void) line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	*stack = origin->next;
	(*stack)->prev = NULL;
	origin->next = NULL;
	origin->prev = tail;
	tail->next = origin;
}

/**
 * pop - adds a new node at the top of a stack_t list.
 * @stack: pointer to head element of list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
		current = current->next;
	if (current->prev != NULL)
		current->prev->next = NULL;
	else
			*stack = NULL;
	free(current);
	current = NULL;
}
