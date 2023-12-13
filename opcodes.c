#include "monty.h"
/**
 *push - pushes a data to stack
 *@stack: stack_t data structure input
 *@value: int value to be added
 *@line_number: line number of opcode
 *
 *Return: void
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
stack_t *new_stack = NULL;
if (value || value == 0)
{
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
else
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
}
/**
 *pall - prints stack data
 *@stack: dtack_t pointer input
 *
 *Return: void
 */
void pall(stack_t *stack)
{
stack_t *current = NULL;
current = stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
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
while (stack != NULL)
{
temp = stack;
stack = stack->next;
free(temp);
}
}
