#include "monty.h"
/**
 *check_string - a function zt checks a string os all digits
 *@com_arg: a string pointer input
 *
 *Return: 1 if all integers and 0 else
 */
int check_string(char *com_arg)
{
int i;
if (com_arg == NULL)
{
return (0);
}
for (i = 0 ; com_arg[i] != '\0' ; i++)
{
if (!isdigit(com_arg[i]))
{
return (0);
}
}
return (1);
}
