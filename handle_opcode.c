#include "monty.h"
/**
 * check_opcode - get opcode by index
 * @line: .
 * @opcode: .
 * Return: .
 */
int check_opcode(char *line, instruction_t opcode[])
{
	int i;

	for (i = 0; i < NUM_OPCODES; i++)
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
	int length, i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
		{
			line += i;
			break;
		}
		i++;
	}
	length = (int)strlen(line);
	if (length == 1 && line[0] == '\n')
		return (line);

	length = (int)strlen(line);
	if (line[length - 1] == '\n')
		line[length - 1] = '\0';
	return (line);
}
