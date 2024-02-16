#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* Describes what happens when fork() is called
multiple times*/
int main()
{
    fork();
    fork();
    fork();
    printf("Hello fork...\n");
    return 0;
}
