#ifndef SPLITLINE_H
#define SPLITLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char **split_shell_command(char *input);

#endif