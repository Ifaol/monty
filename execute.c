#include "monty.h"
/**
 *execute- a function zt executes opcodes
 *@content: line content
 *@stack:head linked list - stack
 *@line_no: line counter
 *@file: poiner to monty file
 *
 *Return: 0 for and 1 else
 */
int execute(char *content, stack_t **stack, unsigned int line_no, FILE *file)
{
instruction_t opst[] = {{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
{"nop", f_nop}, {"sub", f_sub}, {"div", f_div}, {NULL, NULL}};
char *com = NULL;
int i = 0;
com = strtok(content, " \n\t");
if (com != NULL)
{
if (com[0] == '#')
{
return (0);
}
else
{
bus.arg = strtok(NULL, " \n\t");
bus.content = content;
while (opst[i].opcode)
{
if (strcmp(com, opst[i].opcode) == 0)
{
opst[i].f(stack, line_no);
return (0);
}
i++;
}
if (opst[i].opcode == NULL)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_no, com);
fclose(file);
if (line_no != 1)
{
free_stack(*stack);
}
exit(EXIT_FAILURE);
}
}
}
return (1);
}
