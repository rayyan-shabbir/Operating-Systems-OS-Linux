#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    fork() && fork();
    fprintf(stderr, "%s\n", "PUCIT");
    return 0;
}