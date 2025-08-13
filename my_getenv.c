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
