#include "../include/launchline.h"

int launch_shell_commands(char **args){
    pid_t pid;
    pid_t wpid;
    int status;

    pid = fork();

    if(pid < 0){
        printf("Fork failed\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0){
        execvp(args[0], args);
    }
    else{
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        }  while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}
