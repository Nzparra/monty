#include "monty.h"
/**
 * f_rotr - Rotates stack
 * @stack: head of stack
 * @ln: line
 */
void f_rotr(stack_t **stack, unsigned int ln)
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
		while (save1->next != NULL)
		{
			save1 = save1->next;
		}
		save1->prev->next = NULL;
		save1->prev = NULL;
		save1->next = save;
		save->prev = save1;
		(*stack) = save1;
	}

}
/**
 * f_mod - Modulate stack
 * @stack: head of stack
 * @ln: line
 */
void f_mod(stack_t **stack, unsigned int ln)
{
	stack_t *save, *save1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", ln);
		status[2] = 1;
		return;
	}
	save = (*stack);
	save1 = save->next;
	if (save->n == 0)
	{
		printf("L%d: division by zero\n", ln);
		status[2] = 1;
		return;
	}
	save->n = save1->n % save->n;
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
 * f_mul - Multiply two tops
 * @stack: head of stack
 * @ln: line
 */
void f_mul(stack_t **stack, unsigned int ln)
{
	stack_t *save, *save1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", ln);
		status[2] = 1;
		return;
	}
	save = (*stack);
	save1 = save->next;
	save->n = save1->n * save->n;
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
 * f_sub - Subs two tops
 * @stack: head of stack
 * @ln: line
 */
void f_sub(stack_t **stack, unsigned int ln)
{
	stack_t *save, *save1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", ln);
		status[2] = 1;
		return;
	}
	save = (*stack);
	save1 = save->next;
	save->n = save1->n - save->n;
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
 * f_div - Adds div tops
 * @stack: head of stack
 * @ln: line
 */
void f_div(stack_t **stack, unsigned int ln)
{
	stack_t *save, *save1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", ln);
		status[2] = 1;
		return;
	}
	save = (*stack);
	save1 = save->next;
	if (save->n == 0)
	{
		printf("L%d: division by zero\n", ln);
		status[2] = 1;
		return;
	}
	save->n = (int)(save1->n / save->n);
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
