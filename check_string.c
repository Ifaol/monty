#include "monty.h"
/**
 *check_string - a function zt checks a string os all digits
 *@com_arg: a string pointer input
 *
 *Return: 1 if all integers and 0 else
 */
int check_string(char *com_arg)
{
int i, c = 0;
if (com_arg == NULL)
{
return (0);
}
if (com_arg[0] == '-')
{
c = 1;
}
for (i = c ; com_arg[i] != '\0' ; i++)
{
if (!isdigit(com_arg[i]))
{
return (0);
}
}
return (1);
}
