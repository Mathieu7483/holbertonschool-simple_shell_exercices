#include "split.h"
/**
*environnement - fonction principale
*@ac: Le nombre d'arguments.
*@av: Un tableau de pointeurs vers les chaînes d'arguments.
*@env: Un tableau de pointeurs vers les chaînes de variables d'environnement.
*Return: 0 if access
*/
int environnement(int ac, char **av, char **env)
{
printf("Adresse de la variable locale 'env' (le 3e paramètre de main) :\n"
	   "%p\n", (void *)env);
printf("Adresse de la variable globale 'environ' :\n"
	   "%p\n", (void *)environ);

printf("\n");

printf("Adresse de la première variable du tableau 'env' :\n"
	   "%p\n", (void *)env[0]);
printf("Adresse de la première variable du tableau 'environ' :\n"
	   "%p\n", (void *)environ[0]);

printf("\n");

printf("La première variable d'environnement (via 'env') :\n"
	   "%s\n", env[0]);
printf("La première variable d'environnement (via 'environ') :\n"
	   "%s\n", environ[0]);

return (0);
}
