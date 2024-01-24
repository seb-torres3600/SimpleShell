#ifndef BUILTIN_H
#define BUILTIN_H

#define STARTING_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


extern char *builtin_str[];

extern int (*builtin_func[]) (char **);

char* last_directory;

int num_builtins();
int builtin_cd(char **args);
int builtin_help(char **args);
int builtin_exit(char **args);
int builtin_pwd(char **args);

// Helpers
void set_current_directory();

#endif