#include "split.h"

static int environ_initialized = 0;

/**
 */
static int _init_environ(void)
{
    int i;
    int count;
    char **new_environ;


    for (count = 0; environ[count] != NULL; count++);


    new_environ = malloc(sizeof(char *) * (count + 1));
    if (new_environ == NULL)
        return (-1);


    for (i = 0; i < count; i++)
    {
        new_environ[i] = strdup(environ[i]);
        if (new_environ[i] == NULL)
        {

            for (int j = 0; j < i; j++)
                free(new_environ[j]);
            free(new_environ);
            return (-1);
        }
    }
    new_environ[count] = NULL;


    environ = new_environ;
    environ_initialized = 1;
    return (0);
}
/**
*_setenv - function that changes or adds an
*environment variable (without using setenv)
*@name: name of the variable to be define
*@value: value to attribute to a the variable
*@overwrite: overwrite if non zero, otherwise create it
*Return: 0 if access, -1 if error
*/
int _setenv(const char *name, const char *value, int overwrite)
{
    int i, count;
    size_t name_len;
    char *new_var;
    char **new_environ;

    if (!environ_initialized)
    {
        if (_init_environ() == -1)
            return (-1);
    }
    
    if (name == NULL || *name == '\0' || value == NULL)
        return (-1);

    name_len = strlen(name);
    new_var = malloc(name_len + strlen(value) + 2);
    if (new_var == NULL)
        return (-1);
    
    strcpy(new_var, name);
    strcat(new_var, "=");
    strcat(new_var, value);

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            if (overwrite)
            {
                free(environ[i]);

                environ[i] = new_var;
                return (0);
            }
            else
            {

                free(new_var);
                return (0);
            }
        }
    }

    for (count = 0; environ[count] != NULL; count++);

    new_environ = malloc(sizeof(char *) * (count + 2));
    if (new_environ == NULL)
    {
        free(new_var);
        return (-1);
    }
    

    for (i = 0; i < count; i++)
        new_environ[i] = environ[i];

    new_environ[count] = new_var;
    new_environ[count + 1] = NULL;

    free(environ);
    environ = new_environ;

    return (0);
}

int main(void)
{

    printf("--- Environnement Initial ---\n");
    for (int i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
    printf("---------------------------\n\n");


    printf("--- Ajout de MY_VARIABLE ---\n");
    if (_setenv("MY_VARIABLE", "my_value", 1) == 0)
    {
        printf("MY_VARIABLE a été ajoutée avec succès.\n");
    }
    printf("---------------------------\n");


    printf("--- Environnement après ajout ---\n");
    for (int i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
    printf("-------------------------------\n\n");


    printf("--- Modification de MY_VARIABLE (overwrite = 1) ---\n");
    if (_setenv("MY_VARIABLE", "new_value", 1) == 0)
    {
        printf("MY_VARIABLE a été modifiée avec succès.\n");
    }
    printf("------------------------------------------------\n");


    printf("--- Environnement après modification ---\n");
    for (int i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
    printf("--------------------------------------\n\n");


    printf("--- Tentative de modification de MY_VARIABLE (overwrite = 0) ---\n");
    if (_setenv("MY_VARIABLE", "final_value", 0) == 0)
    {
        printf("MY_VARIABLE n'a pas été modifiée.\n");
    }
    printf("------------------------------------------------------------\n");


    printf("--- Environnement final ---\n");
    for (int i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
    printf("---------------------------\n");

    return (0);
}
