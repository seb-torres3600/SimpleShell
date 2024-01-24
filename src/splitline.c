#include "../include/splitline.h"

#define SPLIT_LINE_BUFFER_SIZE 64
#define DELIMITERS " \t"

char **split_shell_command(char* input){
    int buffer_size = 0;
    int position = 0;
    char **tokens = malloc(sizeof(char) * SPLIT_LINE_BUFFER_SIZE);
    char *token;

    if (!tokens){
        printf("Failed to allocate memory for tokens");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, DELIMITERS);
    while(token != NULL){
        if(position >= buffer_size){
            buffer_size += SPLIT_LINE_BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char));
            if(!tokens){
                printf("Failed to allocate memory for tokens");
                exit(EXIT_FAILURE);
            }
        }
        tokens[position] = token;
        position++;
        token = strtok(NULL, DELIMITERS);
    }
    tokens[position] = NULL;
    return tokens;
}