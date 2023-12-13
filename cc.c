#include "monty.h"

/**
 * mod - computes the remainder of dividing the
 * second element of the stack by the top element.
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int remainder = (*stack)->next->n % (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(
			stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: can't divide by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	pop(stack, line_number);
	(*stack)->n = remainder;
}

/**
 * pchar - prints the character corresponding
 * to the ASCII value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value = (*stack)->n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ascii_value);
}

/**
 * pstr - prints the string of characters
 * corresponding to the ASCII values in the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)(line_number);

	while (
		current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}

/**
 * rotl - rotates the stack to the top, moving the top element to the bottom.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void)(line_number);
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom,
 * moving the bottom element to the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void)(line_number);

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
}
