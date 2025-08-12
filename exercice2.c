#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*command_line_to_argv - Splits a command line string into an argument vector.
*@line: The input command line string.
*@argc: Pointer to an int where the number of arguments will be stored.
*
* Return: An array of strings (argument vector), NULL-terminated.
*/
char **command_line_to_argv(const char *line, int *argc)
{
char *copy = strdup(line);
char *token;
int count = 0;
int capacity = 10;
char **argv = malloc(capacity * sizeof(char *));

	if (!argv)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, " ");
	while (token != NULL)
	{
		if (count >= capacity)
		{
			capacity *= 2;
			argv = realloc(argv, capacity * sizeof(char *));
			if (!argv)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		argv[count++] = strdup(token);
		token = strtok(NULL, " ");
	}

	argv[count] = NULL;
	*argc = count;

	free(copy);
	return (argv);
}
