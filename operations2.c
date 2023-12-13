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
		free_list(stack);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free_list(stack);
		return;
	}
	temp = *stack;
	((*stack)->next)->prev = NULL;
	*stack = (temp)->next;
	free(temp);
}
/**
 * swap - .
 * @stack: .
 * @line_number: .
 * Return: .
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
 * add - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void _add(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	num = (*stack)->n;
	(*stack)->next->n += num;
	(*stack)->next->prev = NULL;
	free(temp);
	*stack = (*stack)->next;
}
/**
 * nop - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void _nop(stack_t **stack __attribute__((unused)),
unsigned int line_number __attribute__((unused)))
{

}

