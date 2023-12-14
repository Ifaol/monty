#include "monty.h"
/**
 *f_pint - prints the top
 *@head: stack head
 *@counter: line_number
 *
 *Return: no return
*/
void f_pint(stack_t **head, unsigned int counter)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(bus.file);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
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
