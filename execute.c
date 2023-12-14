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
char *com = NULL, *com_arg = NULL;
int n, c = 0;
com = strtok(content, " \n\t");
if (com != NULL)
{
if (com[0] == '#')
{
return (0);
}
else
{
com_arg = strtok(NULL, " \n\t");
if (strcmp(com, "push") == 0)
{
c = check_string(com_arg);
if (c == 0)
{
fprintf(stderr, "L%u: usage: push integer\n", line_no);
fclose(file);
free_stack(*stack);
exit(EXIT_FAILURE);
}
n = atoi(com_arg);
push(stack, n, line_no);
}
else if (strcmp(com, "pall") == 0)
{
pall(*stack);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_no, com);
fclose(file);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}
}
return (1);
}
