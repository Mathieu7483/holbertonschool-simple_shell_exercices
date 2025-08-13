#include "split.h"
/**
*main - Entry point for the program
*@ac: Argument count
*@av: Argument vector
*@env: Environment variables
*Return: Always 0 (Success)
*/
int main(int ac, char **av, char **env)
{
(void)ac;
(void)av;
int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
