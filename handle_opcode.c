#include "monty.h"
char *data;
/**
 * handle_opcode - handle
 * @line_dub: line
 * @opcode: pointer to opcode
 * @stack: head pointer
 * @line_: line number
 */
void handle_opcode(
		char *line_dub, instruction_t *opcode, stack_t **stack, unsigned int line_)
{
	 int idx;

	 data = strtok(NULL, " \t\r\n\a\"");
	 idx = get_opcode_index(line_dub, opcode);

	 if (idx >= 0)
		 opcode[idx].f(stack, line_);
	 else
	 {
		 free_list(stack);
		 fprintf(stderr, "L%d: unknown instruction %s\n", line_, line_dub);
		 free(line_dub);
		 exit(EXIT_FAILURE);
	 }
}
/**
 * get_opcode_index - get opcode by index
 * @line: .
 * @opcode: .
 * Return: .
 */
int get_opcode_index(char *line, instruction_t opcode[])
{
	int i;

	for (i = 0; i < 16; i++)
	{
		if (strcmp(line, opcode[i].opcode) == 0)
			return (i);
	}
	return (-1);
}
/**
 * parse_line - Function handles the line that user enters
 * @line: Take the line from getline function
 * Return: The handled string without new line(\n)
*/
char *parse_line(char *line)
{
	int len, i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
		{
			line += i;
			break;
		}
		i++;
	}
	len = (int)strlen(line);
	if (len == 1 && line[0] == '\n')
		return (line);
	len = (int)strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
