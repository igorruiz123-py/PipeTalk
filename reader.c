#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// run this code on backgroud (./reader &)

int main(void){

    int FileDescriptor = open("MyPipe", O_RDONLY);

    int size;

    read(FileDescriptor, &size, sizeof(int));

    char *buffer = malloc(size + 1);

    if (buffer == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    read(FileDescriptor, buffer, size);

    buffer[size] = '\0';

    fprintf(stdout, "Reader process: message received '%s' \n", buffer);

    close(FileDescriptor);
    free(buffer);

    exit(EXIT_SUCCESS);

}