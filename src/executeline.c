#include "../include/executeline.h"
#include "../include/launchline.h"
#include "../include/builtin.h"

int execute_shell_commands(char **args){
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  int max = num_builtins();
  for (i = 0; i < max; i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }
  return launch_shell_commands(args);
}