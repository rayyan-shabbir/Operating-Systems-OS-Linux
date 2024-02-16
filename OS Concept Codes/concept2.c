#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{

    if (fork() || fork())
        fork();
    printf("1 ");

    return 0;
}