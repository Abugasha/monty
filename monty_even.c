#include "monty.h"

/**
 * add - adds the top two elements of the stack_t list.
 * @stack: pointer to head element of list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		free_all();
	}
	while (tail->next != NULL)
		tail = tail->next;
	tail->prev->n += tail->n;
	tail->prev->next = NULL;
	free(tail);
}

/**
 * sub - Subtracts the top two elements of the stack_t list.
 * @stack: pointer to head element of list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		free_all();
	}
	while (tail->next != NULL)
		tail = tail->next;
	tail->prev->n -= tail->n;
	tail->prev->next = NULL;
	free(tail);
}

/**
 * diva - Divides the second top element by the top element of the stack.
 * @stack: pointer to head element of list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void diva(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		free_all();
	}
	while (tail->next != NULL)
		tail = tail->next;
	if (tail->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free_all();
	}
	tail->prev->n = tail->prev->n / tail->n;
	tail->prev->next = NULL;
	free(tail);
}

/**
 * mul - Multiplies the top two elements of the stack_t list.
 * @stack: pointer to head element of list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		free_all();
	}
	while (tail->next != NULL)
		tail = tail->next;
	tail->prev->n *= tail->n;
	tail->prev->next = NULL;
	free(tail);
}

/**
 * moda - Rest of the division of the second top element
 * by the top element of stack.
 * @stack: pointer to head element of list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void moda(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		free_all();
	}
	while (tail->next != NULL)
		tail = tail->next;
	if (tail->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free_all();
	}
	tail->prev->n = tail->prev->n % tail->n;
	tail->prev->next = NULL;
	free(tail);
}
