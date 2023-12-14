#include "monty.h"
/**
 *f_push - pushes a data to stack
 *@stack: stack_t data structure input
 *@line_no: line number of opcode
 *
 *Return: void
 */
void f_push(stack_t **stack, unsigned int line_no)
{
stack_t *new_stack = NULL;
int value, n = 0;
n = check_string(bus.arg);
if (n == 0)
{
fprintf(stderr, "L%u: usage: push integer\n", line_no);
fclose(bus.file);
free_stack(*stack);
exit(EXIT_FAILURE);
}
else
{
value = atoi(bus.arg);
new_stack = (stack_t *)malloc(sizeof(stack_t));
if (new_stack == NULL)
{
fprintf(stderr, "Error: malloc failed");
exit(EXIT_FAILURE);
}
new_stack->n = value;
new_stack->next = *stack;
*stack = new_stack;
}
}
/**
 *f_pall - prints stack data
 *@stack: dtack_t pointer input
 *@line_number: line counter
 *
 *Return: void
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
if (line_number >= 1)
{
stack_t *current = NULL;
current = *stack;
if (current == NULL)
{
return;
}
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
}
/**
 *free_stack - free a stack
 *@stack: stack_t data structure input
 *
 *Return: void
 */
void free_stack(stack_t *stack)
{
stack_t *temp = NULL;
temp = stack;
while (stack != NULL)
{
temp = stack->next;
free(stack);
stack = temp;
}
}
