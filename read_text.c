#include "monty.h"
/**
 *read_textfile - read text from a file and disp in stdout
 *@filename: name of the file
 *Return: number of letters printed
 */
FILE *open_file(const char *filename)
{
	FILE *fd;

	fd = fopen(filename, "r+");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 *free_grid - allocate matrix in the form of memory
 *@grid: 2d matrix
 *Return: None
 */
void free_grid(char **grid)
{
	int i;

	for (i = 0; grid[i] != NULL; i++)
		free(grid[i]);
	free(grid);
	grid = NULL;
}

/**
 *extract_string - extract string data
 *@string: quantity of arguments
 *@data_length: quantity of arguments in commands
 *Return: Always double pointer with commands
 */
char **extract_string(char *string, int *data_length)
{
	int i = 0;
	char *copy, *token, *copy2;
	const char *delim = " \n\t";
	char **command = NULL;

	copy = _calloc(strlen(string) + 1, 1);
	if (copy == NULL)
		return (NULL);
	strncpy(copy, string, strlen(string));
	token = strtok(copy, delim);
	while (token != NULL)
	{
		(*data_length)++;
		token = strtok(NULL, delim);
	}
	free(copy);
	command = _calloc(((*data_length) + 1), sizeof(char *));
	if ((command) == NULL)
		return (NULL);
	copy2 = _calloc(strlen(string) + 1, 1);
	if (copy2 == NULL)
		return (NULL);

	strncpy(copy2, string, strlen(string));
	token = strtok(copy2, delim);
	for (i = 0; i < (*data_length); i++)
	{
		command[i] = _calloc(strlen(token) + 1, 1);
		if (command[i] == NULL)
		{
			free_grid(command);
			free(copy2);
			return (NULL);
		}
		strncpy(command[i], token, strlen(token));
		token = strtok(NULL, delim);
	}
	free(copy2);
	command[i] = NULL;
	return (command);
}

/**
 *_calloc - using calloc with malloc
 *@nmemb: number of entries
 *@size: bytes of the entry
 *Return: 0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *pointer;

	if (size <= 0 || nmemb <= 0)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (NULL);
	pointer = _memset(pointer, 0, nmemb * size);
	return ((void *)pointer);
}

/**
 *_memset -  sets memory values from *s to n quantity
 *@s: initial address
 *@b: value
 *@n: quantity of bytes
 *Return: pointer to the memory area of s
 */
char *_memset(char *s, char b, unsigned int n)
{
	char **pointer_to_s;
	unsigned int i;

	pointer_to_s = &s;
	for (i = 0; i < n; i++)
	{
	*(*pointer_to_s + i) = b;
	}
	return (*pointer_to_s);
}
