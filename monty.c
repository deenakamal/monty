#include "monty.h"
/**
 * main - entry point for program
 * @ac: number of argments
 * @av: array of arguments
 * Return: 0 on success
 */
int main(int ac, char const *av[])
{
	FILE *file;


	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	process_instructions(file);
	/*fclose(file);*/
	return (0);
}
/**
 * process_instructions - read from file
 * @file: file
 */
void process_instructions(FILE *file)
{
	char *line = NULL, *line_dub, *instruction;
	size_t len = 0;
	ssize_t read;
	unsigned int number_line = 0;
	int index = 0;

	stack_t *stack = NULL;
	instruction_t opcode[] = {{"push", _push}, {"pall", _pall}};

	while (1)
	{
		number_line++;
		read = getline(&line, &len, file);
		if (read == -1)
			break;
		line_dub = parse_line(line);

		if (strcmp(line_dub, "\n") == 0 || line_dub[0] == '#')
			continue;

		instruction = strtok(line_dub, " \t\r\n\a\"");
		/*data = strtok(NULL, " \t\r\n\a\"");*/

		index = check_opcode(instruction, opcode);
		if (index >= 0)
			opcode[index].f(&stack, number_line);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", number_line, line_dub);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	free_list(&stack);
	fclose(file);
}
