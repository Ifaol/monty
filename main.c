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
char *content = NULL;
size_t size = 0;
ssize_t read_line = 1;
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
while (read_line > 0)
{
content = NULL;
line_number++;
read_line = getline(&content, &size, file);
if (read_line > 0)
{
execute(content, &stack, line_number, file);
}
free(content);
}
fclose(file);
free_stack(*stack);
return (0);
}
