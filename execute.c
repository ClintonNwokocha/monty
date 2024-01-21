#include "monty.h"

/**
 * execute - Executes Monty byte commands.
 * @content: The line content from Monty file
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the file.
 * @file: Monty bytecode file.
 */
void execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	char *opcode;
	instruction_t instructions[] = {
		{"push", e_push},
		{"pall", e_pall},
		{NULL, NULL}
	};
	int i = 0;

	opcode = strtok(content, " \n\t");

	if (opcode == NULL)
		return;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instructions %s\n", line_number, opcode);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
