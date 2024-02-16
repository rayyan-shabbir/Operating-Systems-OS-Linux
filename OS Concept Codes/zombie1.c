#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int pid = fork();
    if (pid != 0)
    {
        printf("Parent Running, PID=%ld\n", (long)getpid());
        while (1);
    }
    else
    {
        printf("Child Terminating, PID = %ld\n",(long)getpid());
        exit(0);
    }
    return 0;
}
