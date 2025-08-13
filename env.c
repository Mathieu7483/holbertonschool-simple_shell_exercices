#include "split.h"
/**
*main - fonction principale
*@ac: Le nombre d'arguments.
*@av: Un tableau de pointeurs vers les chaînes d'arguments.
*@env: Un tableau de pointeurs vers les chaînes de variables d'environnement.
*Return: 0 if access
*/
int main(int ac, char **av, char **env)
{
printf("Adresse de la variable locale 'env' (le 3e paramètre de main) : %p\n", (void *)env);
printf("Adresse de la variable globale 'environ' : %p\n", (void *)environ);

printf("\n");

printf("Adresse de la première variable du tableau 'env' : %p\n", (void *)env[0]);
printf("Adresse de la première variable du tableau 'environ' : %p\n", (void *)environ[0]);

printf("\n");

printf("La première variable d'environnement (via 'env') : %s\n", env[0]);
printf("La première variable d'environnement (via 'environ') : %s\n", environ[0]);

return (0);
}
