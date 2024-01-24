#include "../include/builtin.h"

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "cd",
  "help",
  "exit",
  "pwd"
};

int (*builtin_func[]) (char **) = {
  &builtin_cd,
  &builtin_help,
  &builtin_exit,
  &builtin_pwd
};

int num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int builtin_cd(char **args)
{
  if (args[1] == NULL) {
    char *home_directory = getenv("HOME");
    set_current_directory();
    if (getcwd(last_directory, STARTING_SIZE) == NULL) {
      perror("getcwd() error");
    }
    if (chdir(home_directory) != 0){
      perror("lsh");
    }
  } else if(strcmp(args[1], "-") == 0){
    if (last_directory == NULL){
      set_current_directory();
    }
    if (chdir(last_directory) != 0){
      perror("lsh");
    }
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}

int builtin_pwd(char **args){
  char *working_directory = malloc(sizeof(char) * STARTING_SIZE);
  if(getcwd(working_directory, STARTING_SIZE) != NULL){
    printf("%s\n", working_directory);
  } else{
    perror("getcwd() error");
  }
  free(working_directory);
  return 1;
}

int builtin_help(char **args)
{
  int i;
  printf("Sebastian Torres Simple Shell\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");
  int max = num_builtins();
  for (i = 0; i < max; i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int builtin_exit(char **args)
{
  free(last_directory);
  return 0;
}

void set_current_directory(){
    last_directory = malloc(sizeof(char) * STARTING_SIZE);
    if (getcwd(last_directory, STARTING_SIZE) == NULL) {
      perror("getcwd() error");
    }
}