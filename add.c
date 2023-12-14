#include "monty.h"
/**
 *f_add - add 2 the top
 *@head: stack head
 *@counter: line_number
 *
 *Return: no return
*/
void f_add(stack_t **head, unsigned int counter)
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
fprintf(stderr, "L%u: can't add, stack too short\n", counter);
fclose(bus.file);
free_stack(*head);
exit(EXIT_FAILURE);
}
temp = *head;
value = temp->n + temp->next->n;
temp->next->n = value;
*head = temp->next;
free(temp);
}
