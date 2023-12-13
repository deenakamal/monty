#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	char *operation;
	int value;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	operation = strtok(NULL, " \t\n");
	if (operation == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = parse_value(operation, line_number);
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all values on the stack from the top
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;

	(void)(line_number);
	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes top element of stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		return;
	}

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		return;
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
