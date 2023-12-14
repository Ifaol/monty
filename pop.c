#include "monty.h"
/**
 *f_pop - removes the top
 *@stack: stack head
 *@line_no: line_number
 *
 *Return: no return
*/
void f_pop(stack_t **stack, unsigned int line_no)
{
stack_t *temp = NULL;
temp = *stack;
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
fclose(bus.file);
free_stack(*stack);
exit(EXIT_FAILURE);
}
*stack = temp->next;
free(temp);
}
