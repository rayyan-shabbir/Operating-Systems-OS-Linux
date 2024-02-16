#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int cpid;
    cpid = fork();
    switch (cpid)
    {
    case 0:
        printf("I am not a zombie process");
        break;
    default:
        while (1);
    }
}