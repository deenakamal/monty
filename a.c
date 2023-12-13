#include "monty.h"

/**
 * monty - handles opening and reading the monty file
 * @filename: str name of monty opcode file
 * @stack: double pointer to top of stack data struct
 * Return: return an error code or success
 */

int monty(char *filename, stack_t **stack)
{
	char *line = NULL, *opcode = NULL;
	size_t len = 0;
	int line_number = 0;
	ssize_t read;
	FILE *file;

	if (!filename)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		opcode = strtok(line, " \t\n");

		line_number++;
		if (opcode)
		{
			handle_operations(stack, opcode, line_number);
		}
	}
	free(line);
	fclose(file);
	return (EXIT_FAILURE);
}
