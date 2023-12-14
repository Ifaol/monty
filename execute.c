#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @line_number: line content
*
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
char *com = NULL, *com_arg = NULL;
com = strtok(content, " \n\t");
if (com != NULL && com[0] == '#')
{
return (0);
}
com_arg = strtok(NULL, " \n\t");
if (strcmp(com, "push") == 0)
{
push(stack, com_arg[0], line_number);
}
else if (strcmp(com, "pall") == 0)
{
pall(*stack);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, com);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
return (1);
}
