#ifndef MON
#define MON
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
void cargc(int argc);
void copen_file(FILE *file, char *name);
void free_stack(stack_t *head);
int cpush(char *tok_line[], int fline);
void (*select_function(char *line))(stack_t **stack, unsigned int len);
void f_push(stack_t **stack, unsigned int len);
extern int status[];
int add_stack(stack_t **head, int s);
int print_stack(stack_t **head);
void f_pall(stack_t **stack, unsigned int ln);
int ccoment(char **token);
void clear(char *tokens[]);
int token(char *line, char *token[]);
int cnumber(char *line);
void cstructure(char *line);
void cfail(char *line, FILE *file, stack_t *head);
void cfunction(void (*opcode)(), int fline, char *line);
int cempty(const char *c);
void f_pint(stack_t **stack, unsigned int ln);
int cascii(int d);
void f_pstr(stack_t **stack, unsigned int ln);
int dhead_stack(stack_t **head);
void f_pop(stack_t **stack, unsigned int ln);
void f_swap(stack_t **stack, unsigned int ln);
void f_add(stack_t **stack, unsigned int ln);
void f_nop(stack_t **stack, unsigned int ln);
void f_sub(stack_t **stack, unsigned int ln);
void f_div(stack_t **stack, unsigned int ln);
void f_mul(stack_t **stack, unsigned int ln);
void f_pchar(stack_t **stack, unsigned int ln);
void f_rotl(stack_t **stack, unsigned int ln);
void f_rotr(stack_t **stack, unsigned int ln);
void f_mod(stack_t **stack, unsigned int ln);
void fend(FILE *file, char *line, stack_t *head);
#endif
