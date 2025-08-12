#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"
/**
*split_with_strtok - Splits a string into words using strtok and a delimiter.
*@str: The input string to split (will be modified).
*@delim: The delimiter string for splitting.
*@count: Pointer to an int where the number of words will be stored.
* Return: An array of strings (words), or NULL on failure.
*/
char **split_with_strtok(char *str, const char *delim, int *count)
{
	char **words = NULL;
	int n = 0;
	char *token = strtok(str, delim);

	while (token != NULL)
	{
		words = realloc(words, sizeof(char *) * (n + 1));
		words[n++] = strdup(token);
		token = strtok(NULL, delim);
	}

	*count = n;
	return (words);
}
