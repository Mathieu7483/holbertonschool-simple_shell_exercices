#include "split.h"
/**
*main - Searches for commands in the directories listed in PATH.
*@argc: Argument count.
*@argv: Argument vector.
*Return: 0 on success, 1 on error.
*/
int main(int argc, char *argv[])
{
	char *path = getenv("PATH");

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return (1);
	}
	if (path == NULL)
	{
		fprintf(stderr, "Erreur: la variable PATH n'a pas été trouvée.\n");
		return (1);
	}

	for (int i = 1; i < argc; i++)

	{
		find_command(argv[i], path);
	}

	return (0);
}

/**
*find_command - Searches for a command in the directories listed in PATH.
*@filename: The name of the command to search for.
*@path: The PATH environment variable containing directories.
*/
void find_command(char *filename, char *path)
{
	char *path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("strdup");
		return;
	}

	char *token = strtok(path_copy, ":");

	int found = 0;

	while (token != NULL)
	{
		if (check_path(token, filename))
		{
			found = 1;
			break;
		}
		token = strtok(NULL, ":");
	}

	if (!found)
	{
		fprintf(stderr, "%s: command not found\n", filename);
	}

	free(path_copy);
}

/**
*check_path - Checks if a command exists
*and is executable in a given directory.
*@directory: The directory to search in.
*@filename: The name of the command to check.
*Return: 1 if the command is found and executable, 0 otherwise.
*/
int check_path(char *directory, char *filename)
{
	size_t full_path_size = strlen(directory) + strlen(filename) + 2;
	char *full_path = malloc(full_path_size);

	if (full_path == NULL)
	{
		perror("malloc");
		exit(1);
	}

	strcpy(full_path, directory);
	strcat(full_path, "/");
	strcat(full_path, filename);

	if (access(full_path, F_OK) == 0)
	{
		printf("%s\n", full_path);
		free(full_path);
		return (1);
	}

	free(full_path);
	return (0);
}
