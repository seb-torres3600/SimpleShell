#include "../include/helpers.h"

char *get_working_directory(){
    char *current_directory;
    size_t size = 1024;
    current_directory = malloc(sizeof(char) * size); 
    if (getcwd(current_directory, size) == NULL) {
      perror("getcwd() error");
    }
    return current_directory;
}

char *get_current_user() {
    char *username;
    size_t size = 1024;
    username = malloc(sizeof(char) * size);
    if (getlogin_r(username, size) == 0) {
        return username;
    }
    return "default";
}

char *get_current_hostname(){
    char *hostname;
    size_t size = 1024;
    hostname = malloc(sizeof(char) * size);
    if(gethostname(hostname, size) != 0){
        perror("gethostname error");
    }
    return hostname;
}
