#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Command Line Arguments, limit exceeded...");
        exit(0);
    }

    int id = 55;
    printf("My name is Rayan with id: %d, And I am not a terrorist...", id);
    return 0;
}