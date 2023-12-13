#include "monty.h"

/**
 * add - adds top 2 nodes of the stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(
			stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * nop - does anything
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the second element
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int difference = (*stack)->next->n - (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(
			stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	pop(stack, line_number);
	(*stack)->n = difference;
}

/**
 * divide - divides the second element of the stack by the top element.
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void divide(stack_t **stack, unsigned int line_number)
{
	int quotient = (*stack)->next->n / (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(
			stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	pop(stack, line_number);
	(*stack)->n = quotient;
}

/**
 * mul - multiplies the second element of the stack by the top element.
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int product = (*stack)->next->n * (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(
			stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	pop(stack, line_number);
	(*stack)->n = product;
}
