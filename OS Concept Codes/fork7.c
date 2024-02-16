#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int cpid = fork();
    if (cpid == 0)
    {
        while(1)
            printf("Running child, PID=%ld PPID=%ld\n", (long)getpid(), (long)getppid());
        
    }
    else
        printf("Terminating parent, PID=%ld PPID=%ld\n", (long)getpid(), (long)getppid());
    exit(0);
    return 0;
}