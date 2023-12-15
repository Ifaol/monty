#include "monty.h"
/**
 *f_rotr - inverts the stack
 *@head: stack head
 *@counter: line_number
 *
 *Return: no return
*/
void f_rotr(stack_t **head, unsigned int counter)
{
stack_t *prev = NULL;
stack_t *current = *head;
stack_t *next = NULL;
(void) counter;
if (current == NULL)
return;
while (current != NULL)
{
next = current->next;
current->next = prev;
current->prev = next;
prev = current;
current = next;
}
*head = prev;
}
