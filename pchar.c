#include "monty.h"
/**
 *f_pchar - prints the top int at the stack as a char
 *@head: stack head
 *@counter: line_number
 *
 *Return: no return
*/
void f_pchar(stack_t **head, unsigned int counter)
{
stack_t *temp = NULL;
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pchar, stack empty\n", counter);
fclose(bus.file);
free_stack(*head);
exit(EXIT_FAILURE);
}
temp = *head;
if (temp->n >= 0 && temp->n <= 127)
{
printf("%c\n", temp->n);
}
else
{
fprintf(stderr, "L%u: can't pchar, value out of range\n", counter);
fclose(bus.file);
free_stack(*head);
exit(EXIT_FAILURE);
}
}
