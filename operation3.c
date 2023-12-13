#include "monty.h"
/**
 * pchar - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->n > 0 && (*stack)->n < 127))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
