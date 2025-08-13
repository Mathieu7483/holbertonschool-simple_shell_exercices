#include "split.h"
/**
 * @brief La variable externe 'environ' est un pointeur
 * vers un tableau de chaînes de caractères des variables
 * d'environnement.
 */
extern char **environ;

/**
 * @brief Indicateur pour savoir si l'environnement a été initialisé dynamiquement.
 */
static int environ_initialized = 0;

/**
 * @brief Initialise l'environnement global en créant une copie entièrement dynamique.
 * * Cette fonction s'assure que toutes les chaînes et le tableau de pointeurs
 * sont alloués dynamiquement, ce qui permet des modifications et des
 * libérations de mémoire sûres par la suite.
 * * @return 0 en cas de succès, -1 en cas d'erreur.
 */
static int _init_environ(void)
{
    int i;
    int count;
    char **new_environ;

    // Compter le nombre de variables existantes
    for (count = 0; environ[count] != NULL; count++);

    // Allouer de la mémoire pour le nouveau tableau de pointeurs
    new_environ = malloc(sizeof(char *) * (count + 1));
    if (new_environ == NULL)
        return (-1);

    // Dupliquer chaque chaîne de l'ancien environnement
    for (i = 0; i < count; i++)
    {
        new_environ[i] = strdup(environ[i]);
        if (new_environ[i] == NULL)
        {
            // Libérer ce qui a été alloué en cas d'erreur
            for (int j = 0; j < i; j++)
                free(new_environ[j]);
            free(new_environ);
            return (-1);
        }
    }
    new_environ[count] = NULL;

    // Mettre à jour le pointeur global 'environ' et l'indicateur
    environ = new_environ;
    environ_initialized = 1;
    return (0);
}


/**
* _unsetenv - Removes an environment variable by name.
* @name: The name of the environment variable to remove.
* Return: 0 on success, -1 on failure.
*/
int _unsetenv(const char *name)
{
	int i, j;

	size_t name_len;

	if (environ_initialized == 0)
	{
		if (_init_environ() == -1)
			return (-1);
	}

	if (name == NULL || *name == '\0')
		return (-1);

	name_len = strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			free(environ[i]);

			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			return (0);
		}
	}

	return (0);
}
