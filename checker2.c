#include "monty.h"
/**
 * cnumber - check number
 * @line: argument
 * Return: 1 if fails else 0 ok
 */
int cnumber(char *line)
{
	int c;

	if (line && *line == '-')
	{
		line++;
	}
	for (c = 0; line[c] != '\0'; c++)
	{
		if (isdigit(line[c]))
		{
			return (1);
		}
	}
	return (0);
}
/**
 * cstructure - check structure
 * @line: argument
 */
void cstructure(char *line)
{
	if (strcmp(line, "stack") == 0)
	{
		status[1] = 0;
	}
	else if (strcmp(line, "queue") == 0)
	{
		status[1] = 1;
	}
}
/**
 * cfail - Frees if something fails
 * @line: argument
 * @file: File
 * @head: pointer to head
 */
void cfail(char *line, FILE *file, stack_t *head)
{
	if (status[2] == 1)
	{
		free(line);
		fclose(file);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}
/**
 * cfunction - check if the function exists
 * @opcode: function
 * @fline: number of line
 * @line: argument
 * Return: 1 if fails else 0 ok
 */
void cfunction(void (*opcode)(), int fline, char *line)
{
	if (opcode == NULL)
	{
		printf("L%d: unknown instruction %s\n", fline, line);
		status[2] = 1;
		return;
	}
}
/**
 * cempty - check if empty
 * @c: line
 * Return: 1 if fails else 0 ok
 */
int cempty(const char *c)
{
	while (*c != '\0')
	{
		if (!isspace((unsigned char)*c))
		{
			return (0);
		}
		c++;
	}
	return (1);
}
