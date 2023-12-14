#include "monty.h"
char *data;

/**
 * main - Function that run our interpreter
 * @argc: Argument Count
 * @argv: Argument vector
 * Return: .
*/
int main(int argc, char const *argv[])
{
	char *line = NULL, *line_copy, *instruction;
	size_t len = 0;
	ssize_t read;
	FILE *file;
	unsigned int count = 0;
	int idx;

	instruction_t opcode[] = {{"push", _push}, {"pall", _pall}, {"pint", _pint},
	{"pop", _pop}, {"swap", _swap}, {"add", _add}, {"pchar", _pchar}, {"nop", _nop}};
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		count++;
		read = getline(&line, &len, file);
		if (read == -1)
			break;
		line_copy = parse_line(line);
		if (strcmp(line_copy, "\n") == 0 || line_copy[0] == '#')
			continue;
		instruction = strtok(line_copy, " \t\r\n\a\"");
		data = strtok(NULL, " \t\r\n\a\"");
		idx = check_opcode(instruction, opcode);
		if (idx >= 0)
			opcode[idx].f(&stack, count);
		else
		{
			free_list(&stack);
			fprintf(stderr, "L%d: unknown instruction %s\n", count, line_copy);
			exit(EXIT_FAILURE);
		}
	} free(line);
	free_list(&stack);
	fclose(file);
	return (0);
}
