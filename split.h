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

#endif /*split_h*/
