#include "monty.h"
/**
 * f_add - Adds two tops
 * @stack: head of stack
 * @ln: line
 */
void f_add(stack_t **stack, unsigned int ln)
{
	stack_t *save;
	stack_t *save1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", ln);
		status[2] = 1;
		return;
	}
	save = (*stack);
	save1 = save->next;
	save->n = save->next->n + save->n;
	save->next = save1->next;
	if (save1->next != NULL)
	{
		save1->next->prev = save;
	}
	else
	{
		save->next = NULL;
	}
	free(save1);
}
/**
 * f_nop - Nothing
 * @stack: head of stack
 * @ln: line
 */
void f_nop(stack_t **stack, unsigned int ln)
{
	(void) stack, (void) ln;
}
/**
 * f_swap - swaps values to stack
 * @stack: head of stack
 * @ln: line
 */
void f_swap(stack_t **stack, unsigned int ln)
{
	stack_t *save, *save1;
	int c;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", ln);
		status[2] = 1;
		return;
	}
	save = (*stack);
	save1 = save->next;
	c = save->n;
	save->n = save1->n;
	save1->n = c;
}
/**
 * f_pchar - Prints char
 * @stack: head of stack
 * @ln: line
 */
void f_pchar(stack_t **stack, unsigned int ln)
{
	int c;
	stack_t *save;

	save = (*stack);
	if (save == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", ln);
		status[2] = 1;
		return;
	}
	c = save->n;
	if (!cascii(c))
	{
		printf("L%d: can't pchar, value out of range\n", ln);
		status[2] = 1;
		return;
	}
	putchar(c);
	putchar('\n');
}
/**
 * f_rotl - rotates stack
 * @stack: head of stack
 * @ln: line
 */
void f_rotl(stack_t **stack, unsigned int ln)
{
	stack_t *save, *save1;
	(void) ln;

	save = (*stack);
	if (save == NULL)
	{
		return;
	}
	save1 = save;
	if (save->next != NULL)
	{
		(*stack) = (*stack)->next;
		while (save1->next != NULL)
		{
			save1 = save1->next;
		}
		save1->next = save;
		save->prev = save1;
		save->next->prev = NULL;
		save->next = NULL;
	}

}
