#include "split.h"
/**
*my_getenv - Retrieves the value of an environment variable.
*@name: The name of the environment variable to search for.
*Return: Pointer to the value string if found, otherwise NULL.
*/
char *my_getenv(const char *name)
{
	int i;

	size_t name_len;

	if (name == NULL || *name == '\0')
	{
		return (NULL);
	}

	name_len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (&environ[i][name_len + 1]);
		}
	}

	return (NULL);
}
/**
 * main - Entry point of the program.
 * Demonstrates usage of my_getenv to retrieve environment variables.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *path_val;
	char *home_val;
	char *shell_val;
	char *unknown_val;

	path_val = my_getenv("PATH");
	home_val = my_getenv("HOME");
	shell_val = my_getenv("SHELL");
	unknown_val = my_getenv("NON_EXISTENT_VAR");

	printf("Valeur de PATH: %s\n", path_val);
	printf("Valeur de HOME: %s\n", home_val);
	printf("Valeur de SHELL: %s\n", shell_val);

	if (unknown_val == NULL)
	{
		printf("La variable NON_EXISTENT_VAR n'a pas été trouvée.\n");
	}

	return (0);
}
