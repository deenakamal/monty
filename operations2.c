#include "monty.h"
/**
 * _pint - print the top element in stack
 * @stack: head
 * @line_number: command number
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * _pop - remove top element
 * @stack: head stack
 * @line_number: command number
 * Return: void
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		return;
	}
	temp = *stack;
	((*stack)->next)->prev = NULL;
	*stack = (temp)->next;
	free(temp);
}
/**
 * _swap - swap two elemet in top
 * @stack: head stack
 * @line_number: command line
 * Return: void
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	int num;

	if (!(*stack) || !((*stack)->next))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
/**
 * _add - add two elements
 * @stack: head stack
 * @line_number: command number
 * Return: void
*/
void _add(stack_t **stack, unsigned int line_number)
{
	int d;
	stack_t *tmp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	d = (*stack)->n;
	(*stack)->next->n += d;
	(*stack)->next->prev = NULL;
	free(tmp);
	*stack = (*stack)->next;
}
/**
 * _nop - nothing
 * @stack: head
 * @line_number: line number
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

}
