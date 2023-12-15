#include "monty.h"
/**
 *f_pstr - prints the top int at the stack as a char
 *@head: stack head
 *@counter: line_number
 *
 *Return: no return
*/
void f_pstr(stack_t **head, unsigned int counter)
{
stack_t *temp = NULL;
(void) counter;
if (*head == NULL)
{
printf("\n");
return;
}
temp = *head;
while (temp != NULL)
{
if (temp->n > 0 && temp->n <= 127)
{
printf("%c", temp->n);
temp = temp->next;
}
else
{
break;
}
}
printf("\n");
}
