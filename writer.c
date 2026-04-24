#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// ./writer send message <message>
//     0     1     2        3

int main(int argc, char *argv[]){

    if (argc == 4){

        if (strcmp(argv[1], "send") == 0 && strcmp(argv[2], "message") == 0){

            char *buffer = malloc(strlen(argv[3]));

            if (buffer == NULL){
                perror("malloc");
                exit(EXIT_FAILURE);
            }

            strcpy(buffer, argv[3]);

            int FileDescriptor = open("MyPipe", O_WRONLY);

            int size = strlen(buffer);

            write(FileDescriptor, &size, sizeof(int));
            write(FileDescriptor, buffer, size);

            fprintf(stdout, "Writer process: message sent.\n");

            close(FileDescriptor);
            free(buffer);
            exit(EXIT_SUCCESS);

            
        }

        else {
            fprintf(stderr, "fatal: invalid arguments \n");
            exit(EXIT_FAILURE);
        }
    }

    else {
        fprintf(stderr, "fatal: invalid number of arguments \n");
        exit(EXIT_FAILURE);
    }
}