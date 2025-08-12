#include "split.h"
/**
* free_args - Frees a dynamically allocated array of strings.
* @args: The array of strings to free.
*/
void free_args(char **args)
{
	int i = 0;

	if (args == NULL)
		return;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/**
* read_line - Reads a line from stdin.
* Return: A pointer to the line read, or NULL on error or EOF.
*/
char *read_line(void)
{
	char *line = NULL;

	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			return (NULL);
		}
		else
		{
			free(line);
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

/**
* parse_line - Splits a line into tokens.
* @line: The line to parse.
* Return: An array of strings (tokens).
*/
char **parse_line(char *line)
{
	char **tokens = NULL;

	char *token;

	int bufsize = 64;

	int i = 0;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			free_args(tokens);
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
* execute_command - Executes a command.
* @args: The array of command and its arguments.
* Return: The status of the executed command.
*/
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args == NULL || args[0] == NULL)
		return (1);

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (WEXITSTATUS(status));
}

/**
* main - Entry point for the super simple shell program.
* @argc: Argument count.
* @argv: Argument vector.
*
* Return: Status code from the last executed command.
*/
int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	char *line = NULL;

	char **args = NULL;

	int status = 0;

	while (1)
	{
		printf("$ ");
		line = read_line();

		if (line == NULL)
		{
			printf("\n");
			break;
		}

		args = parse_line(line);
		if (args != NULL && args[0] != NULL)
		{
			status = execute_command(args);
		}

		free(line);
		if (args != NULL)
			free_args(args);
	}

	return (status);
}
