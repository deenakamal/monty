#include "monty.h"

/**
 * create_new_node - creates a new node
 * @value: value of the node
 * Return: new node
 */

stack_t *create_new_node(int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

/**
 * parse_value - parses the value
 * @operation: operation
 * @line_number: line number
 * Return: value
 */

int parse_value(char *operation, unsigned int line_number)
{
	char *endptr;
	int value = strtol(operation, &endptr, 10);

	if (*endptr != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	return (value);
}

/**
 * update_stack - updates the stack
 * @stack: double pointer to the first node
 * @new_node: new node
 * Return: void
 */

void update_stack(stack_t **stack, stack_t *new_node)
{
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
