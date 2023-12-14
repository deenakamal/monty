#include "monty.h"
/**
 * _push - to add elements in list
 * @stack: head stack
 * @line_number: command number
 * Return: void
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int is_valid, number;
	/*char *data;*/

	/*data = strtok(NULL, " \t\r\n\a\"");*/
	is_valid = check_input(data);

	if ((!is_valid))
	{
		free_list(&new_node);
		free_list(stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	number = atoi(data);

	new_node->n = number;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * _pall - print elements in stack
 * @stack: head stack
 * @line_number: line number of command
 * Return: void
*/
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
/**
 * free_list - free stack
 * @stack: head
 * Return: void
*/
void free_list(stack_t **stack)
{
	stack_t *head = *stack;
	stack_t *tmp_me;

	while (head != NULL)
	{
		tmp_me = head;
		head = head->next;
		free(tmp_me);
	}
	*stack = NULL;
}
/**
 * check_input - convert and check if data from 0 to 9
 * @data: input data to check
 * Return: return 1 is valid 0 otherwisw
*/

int check_input(char *data)
{
	char *p = data;

	if (data == NULL)
		return (0);
	if (*p == '-')
		p++;
	while (*p != '\0')
	{
		if (*p >= '0' && *p <= '9')
			p++;
		else
			return (0);
	}
	return (1);
}
