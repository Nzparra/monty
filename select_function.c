#include "monty.h"
/**
 * select_function - Return the correct function
 * @line: function passed
 * Return: function
 */
void (*select_function(char *line))(stack_t **stack, unsigned int len)
{
	int c = 0;
	instruction_t s[] = {
		{"pall", f_pall},
		{"push", f_push},
		{"pint", f_pint},
		{"pstr", f_pstr},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"stack", f_nop},
		{"queue", f_nop},
		{NULL, NULL}
	};

	while (c < 17)
	{
		if (strcmp(line, (s[c]).opcode) == 0)
		{
			return (*(s[c]).f);
		}
		c++;
	}
	return (NULL);
}
