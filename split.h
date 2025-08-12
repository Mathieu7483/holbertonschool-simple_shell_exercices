#ifndef SPLIT_H
#define SPLIT_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
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

#endif /*split_h*/
