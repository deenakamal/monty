#include "monty.h"

/**
 * handle_operations - handles wish function to call based on a single line
 * @stack: double pointer to head of stack data structure
 * @operation: operation to be called
 * @line_number: line in byte-code file being processed, zero indexed
 * Return: void
 */

void handle_operations(
	stack_t **stack, char *operation, unsigned int line_number)
{
	size_t i;

	instruction_t all_operations[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
	};

	if (operation[0] == '#')
		return;

	for (i = 0; i < sizeof(all_operations) / sizeof(instruction_t); i++)
	{
		if (strcmp(operation, all_operations[i].opcode) == 0)
		{
			all_operations[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, operation);
}
