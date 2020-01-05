#include "monty.h"
/**
 * clear - Clean tokens
 * @tokens: tokens
 */
void clear(char *tokens[])
{
	int c;

	for (c = 0; tokens[c]; c++)
	{
		tokens[c][0] = '\0';
	}
}
/**
 * cargc - count argc
 * @argc: # of arguemtns
 */
void cargc(int argc)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * copen_file - Check open file
 * @file: the file
 * @name: name
 */
void copen_file(FILE *file, char *name)
{
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
}
/**
 * cpush - check push
 * @tok_line: argument
 * @fline: number of line
 * Return: 1 if fails else 0 ok
 */
int cpush(char *tok_line[], int fline)
{
	if (strcmp(tok_line[0], "push") == 0)
	{
		if (tok_line[1][0] != '\0' && cnumber(tok_line[1]))
		{
			status[0] = atoi(tok_line[1]);
		}
		else
		{
			printf("L%d: usage: push integer nico\n", fline);
			status[2] = 1;
			return (0);
		}
		return (1);
	}
	return (0);
}
/**
 * ccoment - check if exist comments
 * @token:arguemtns
 * Return: 1 if ok
 */
int ccoment(char **token)
{
	if (*token[0] == '#')
	{
		*token[0] = '\0';
		return (1);
	}
	return (0);
}
