#include "monty.h"
int main(int argc, char *argv[]);
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
/**
 *f_swap - swaps 2 the top
 *@head: stack head
 *@counter: line_number
 *
 *Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
{
stack_t *temp = *head;
int len = 0, value;
while (temp != NULL)
{
temp = temp->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%u: can't swap, stack too short", counter);
fclose(bus.file);
free_stack(*head);
exit(EXIT_FAILURE);
}
value = (*head)->n;
(*head)->n = (*head)->next->n;
(*head)->next->n = value;
}
