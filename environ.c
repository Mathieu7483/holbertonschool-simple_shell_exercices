#include "split.h"
char **environ
/**
*main - Entry point of the program
*Prints the environment variables.
*Return: Always 0 (Success)
*/
int main(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
