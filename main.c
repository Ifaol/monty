#include "monty.h"
/**
 *main - a function that executes opcode
 *@argc: no of args intered
 *@argv: array of args string
 *
 *Return: 0 if sucessfull
 */
int main(int argc, char *argv[])
{
stack_t *stack = NULL;
unsigned int line_number = 0;
char line[256];
int value;
FILE *file = NULL;
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
while (fgets(line, sizeof(line), file))
{
line_number++;
if (sscanf(line, "push %d", &value) == 1)
{
push(&stack, value, line_number);
}
else if (strcmp(line, "pall\n") == 0)
{
pall(stack);
}
else
{
fprintf(stderr, "Error: Invalid opcode\n");
fclose(file);
free_stack(stack);
exit(EXIT_FAILURE);
}
}
fclose(file);
free_stack(stack);
return (0);
}
