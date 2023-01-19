#ifndef _MONTY_H
#define _MONTY_H
/*Global variables definition*/

/*This space is reserved library calls*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/*This space is reserved for structure definitions*/



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct creator_params - singly linked list
 * @opcode: pointer that stores what the user writes
 * @fd: counter of shell, shows error in the lines
 * @head: path of the enviroment variable
 *
 * Description: This structure give us input arguments
 * to create processes -
 */
typedef struct creator_params
{
	char **opcode;
	FILE *fd;
	stack_t *head;
} creator_args;
extern creator_args c_args;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*This space is reserved for function prototypes*/
FILE *open_file(const char *filename);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
char **extract_string(char *string, int *data_length);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_memset(char *s, char b, unsigned int n);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
void free_grid(char **grid);
void (*get_op_func(int line))(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void free_all(void);
void is_number(unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void diva(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void moda(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
#endif /* _MONTY_H */
