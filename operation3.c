#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 * @stack: head stack
 * @line_number: command number
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->n > 0 && (*stack)->n < 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
