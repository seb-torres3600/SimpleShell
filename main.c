#include <stdio.h>
#include <stdlib.h>

#include "include/readline.h"
#include "include/splitline.h"
#include "include/launchline.h"
#include "include/executeline.h"
#include "include/helpers.h"

int main(){
    int status = 1;
    while(status){
        char *shell_input;
        char **args;
        char *current_directory = get_working_directory();
        char *current_user = get_current_user();
        char *hostname = get_current_hostname();
        printf("%s@%s %s >> ", current_user, hostname, current_directory);
        shell_input = read_shell_command();
        args = split_shell_command(shell_input);
        status = execute_shell_commands(args);
        free(shell_input);
        free(args);
        free(current_directory);
        free(current_user);
        free(hostname);
    }
    return 0;
}