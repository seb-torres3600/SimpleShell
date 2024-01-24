#include "../include/readline.h"

#define BUFFER_INIT_SIZE 1024

char *read_shell_command(){
    int buffer_size = BUFFER_INIT_SIZE;
    int position = 0;
    char *input = malloc(sizeof(char) * buffer_size);
    int c;

    if(!input){
        printf("Failure to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        c = getchar();
        if(c == '\n' | c == EOF){
            input[position] = '\0';
            return input;
        }
        else{
            if(position >= buffer_size){
                buffer_size += BUFFER_INIT_SIZE;
                input = realloc(input, buffer_size);
                if(!input){
                    printf("Failed to reallocate memory\n");
                    exit(EXIT_FAILURE);
                }
            }
            input[position] = c;
            position++;
        }
    }
}