#ifndef SPLIT_H
#define SPLIT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

char **split_with_strtok(char *str, const char *delim, int *count);

#endif /*split_h*/
