#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
// #include <pthread.h>

int main()
{
    time_t t1, t2;
    time(&t1);
    // <Your Code Here>

    pid_t pid[100000];

    for (int i = 0; i < 100000; i++)
    {
        pid[i] = fork();

        if (pid[i] == 0)
        {
            // printf("I am child\n");
            fprintf(stderr, "PID=%ld, PPID=%ld\n",(long)getpid(), (long)getppid());
            exit(0);
        }
    }

    for (int i = 0; i < 100000; i++)
    {
            // printf("I am parent\n");
            wait(NULL);
    }
    
    time(&t2);
    printf("It took us %ld seconds to complete the task\n", t2 - t1);
    return 0;
}