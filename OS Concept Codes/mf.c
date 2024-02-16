#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    fork();
    fork();
    fork();
    printf("Hello fork...\n");
    return 0;
}