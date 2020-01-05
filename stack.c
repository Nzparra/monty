#include "monty.h"
/**
 * free_stack - Free stack
 * @head: stack to free
 */
void free_stack(stack_t *head)
{
	stack_t *save;

	while (head != NULL)
	{
		save = head;
		head = head->next;
		free(save);
	}
}
/**
 * add_stack - add to stack
 * @head: stack
 * @n: line
 * Return: 1 if ok
 */
int add_stack(stack_t **head, int n)
{
	stack_t *save;

	save = malloc(sizeof(stack_t));
	if (save == NULL)
	{
		printf("Error: malloc falided\n");
		return (-1);
	}
	save->n = n;
	save->prev = NULL;
	if (*head == NULL)
	{
		save->next = NULL;
		*head = save;
	}
	else
	{
		save->next = *head;
		(*head)->prev = save;
		*head = save;
	}
	return (1);
}
/**
 * print_stack - Print all stack
 * @head: stack
 * Return: 0 if is ok
 */
int print_stack(stack_t **head)
{
	stack_t *temp;

	temp = (*head);
	if (temp == NULL)
	{
		return (-1);
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (0);
}
/**
 * dhead_stack - delete in head of stack
 * @head: stack
 * Return: 1 if ok
 */
int dhead_stack(stack_t **head)
{
	stack_t *save;

	if (*head == NULL)
	{
		return (-1);
	}
	save = (*head);
	if (save->next == NULL)
	{
		free(save);
		(*head) = NULL;
		return (1);
	}
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(save);
	return (1);
}
