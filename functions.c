#include "holberton.h"
/**
 * f_push - Push value to stack
 * @stack: head of stack
 * @len: line
 */
void f_push(stack_t **stack, unsigned int len)
{
	int save;

	if (status[1] == 0)
	{
		save = add_stack(stack, status[0]);
	}
	else
	{
		save = add_stack(stack, status[0]);
	}
	if (save < 0)
	{
		printf("L%d: usage: push integer\n", len);
		status[2] = 1;
		return;
	}
}
/**
 * f_pall - Prints value to stack
 * @stack: head of stack
 * @ln: line
 */
void f_pall(stack_t **stack, unsigned int ln)
{
	(void) ln;

	print_stack(stack);
}
/**
 * f_pint - Prints value top1
 * @stack: head of stack
 * @ln: line
 */
void f_pint(stack_t **stack, unsigned int ln)
{
	stack_t *head;

	head = *stack;
	if (head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", ln);
		status[2] = 1;
		return;
	}
	printf("%d\n", head->n);
}
/**
 * f_pstr - Prints string top
 * @stack: head of stack
 * @ln: line
 */
void f_pstr(stack_t **stack, unsigned int ln)
{
	stack_t *temp;
	int d;
	(void) ln;

	temp = (*stack);
	while (temp != NULL && temp->n != 0 && cascii(temp->n))
	{
		d = temp->n;
		putchar(d);
		temp = temp->next;
	}
	putchar('\n');
}
/**
 * f_pop - Removes element in stack
 * @stack: head of stack
 * @ln: line
 */
void f_pop(stack_t **stack, unsigned int ln)
{
	int del;

	del = dhead_stack(stack);
	if (del != 1)
	{
		printf("L%d: cant't pop en empty stack\n", ln);
		status[2] = 1;
	return;
	}
}
