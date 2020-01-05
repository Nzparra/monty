#include "monty.h"
/**
 * token - Tokenize
 * @line: line to tokenize
 * @token: tokens
 * Return: 1 if ok
 */
int token(char *line, char *token[])
{
	char *tokens, *copy;
	int c, succes;

	tokens = strtok_r(line, " \t\n", &copy);
	succes = ccoment(&tokens);
	if (succes == 1)
	{
		return (0);
	}
	for (c = 0; tokens && c < 2; c++)
	{
		token[c] = tokens;
		tokens = strtok_r(NULL, " \t\n", &copy);
	}
	return (1);

}
/**
 * fend - Close file and free memory
 * @file: file to close
 * @line: to freeline
 * @head : to free
 */
void fend(FILE *file, char *line, stack_t *head)
{
	fclose(file);
	free(line);
	free_stack(head);
}
