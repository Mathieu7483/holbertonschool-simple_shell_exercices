#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"
/*
* main - Entry point for testing string splitting functions.
*
* Return: Always 0 (Success)
*/
/**
 * main - Entry point for testing string splitting functions.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
const char *phrase = "pomme; banane, cerise orange;kiwi";
const char *delim = " ,;";
int nb;
char *copie;
char **tokens1;
char **tokens2;
int i;

	copie = strdup(phrase);
	tokens1 = split_with_strtok(copie, delim, &nb);

	printf("Avec strtok:\n");

	for (i = 0; i < nb; i++)
	{
		printf("Mot %d : %s\n", i + 1, tokens1[i]);
		free(tokens1[i]);
	}
	free(tokens1);
	free(copie);
}
