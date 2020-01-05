#include "holberton.h"
int status[3] = {0, 0, 0};
/**
 * main - Monty Language
 * @argc: # of arguemtns
 * @argv: arguemtns
 * Return: 1 if ok
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *path, *line, *tok_line[2];
	size_t len, fline;
	ssize_t read;
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *head;

	head = NULL;
	line = NULL;
	cargc(argc);
	path = argv[1];
	file = fopen(path, "r");
	copen_file(file, path);
	for (fline = 1; (read = getline(&line, &len, file)) != -1; fline++)
	{
		cempty(line);
		token(line, tok_line);
		cpush(tok_line, fline);
		cfail(line, file, head);
		cstructure(tok_line[0]);
		f = select_function(tok_line[0]);
		cfunction(f, fline, tok_line[0]);
		cfail(line, file, head);
		(*f)(&head, fline);
		cfail(line, file, head);
		clear(tok_line);
	}
	fend(file, line, head);
	return (0);
}
