#include "split.h"

/**
* print_path_directories - display directories
*/
void print_path_directories(void)
{
	char *path;

	char *path_copy;

	char *token;

	path = getenv("PATH");

	if (path == NULL)
	{
		fprintf(stderr, "Erreur: la variable PATH n'a pas été trouvée.\n");
		return;
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		return;
	}

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	free(path_copy);
}

/**
* main - teste la fonction
*
* Return: Always 0 (Success)
*/
int main(void)
{
	printf("Répertoires dans le PATH :\n");
	printf("---------------------------\n");
	print_path_directories();
	printf("---------------------------\n");
	return (0);
}
