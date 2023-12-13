#include "monty.h"

/**
 * main - monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on error.
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty(argv[1], &stack);
	free_nodes(&stack);
	return (EXIT_SUCCESS);
}

/**
 * free_nodes - frees the nodes
 * @stack: double pointer to the first node
 * Return: void
 */

void free_nodes(stack_t **stack)
{
	stack_t *tmp;

	if (*stack == NULL)
		return;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp), tmp = NULL;
	}
}
