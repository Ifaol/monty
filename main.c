#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
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
char content[MAX_LINE_LENGTH];
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
bus.file = file;
while (fgets(content, sizeof(content), file) != NULL)
{
line_number++;
execute(content, &stack, line_number, bus.file);
}
fclose(bus.file);
free_stack(stack);
return (0);
}
