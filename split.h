#ifndef SPLIT_H
#define SPLIT_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

char **split_with_strtok(char *str, const char *delim, int *count);

char *read_line(void);
char **parse_line(char *line);

int execute_command(char **args);

void free_args(char **args);

void find_command(char *filename, char *path);

int check_path(char *directory, char *filename);

int environnement(int ac, char **av, char **env);

char *my_getenv(const char *name);

/**
 * struct list_s - Singly linked list node
 *to store directory paths for command searching
 * @dir: Directory path
 * @next: Pointer to the next node
 *
 * Description: Node structure for a singly
 *linked list used to store directory paths
 * for command searching in the shell project.
 */
typedef struct list_s
{
	char *dir;

	struct list_s *next;
} list_t;

#endif /*split_h*/
