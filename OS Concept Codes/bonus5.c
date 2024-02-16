#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp)
{
    if (argc < 2)
    {
        printf("Command line Arguments limit exceeds....\n");
        exit(0);
    }

    char *newargv[] = {"/bin/ls", NULL, NULL, NULL};
    char *enivp[] = {NULL};

    newargv[0] = argv[1];

    if (argc > 2)
    {
        int j = 2;

        for (int i = 1; i < (argc - 1); i++)
        {
            newargv[i] = argv[j];
            j++;
            // printf(newargv[i]);
            // printf("\n");
        }

        // for (int i = 0; i < (argc - 1); i++)
        // {
        //     printf(newargv[i]);
        //     printf("\n");
        // }
    }

    // printf("Start");
    int cpid = fork();

    if(cpid == 0) {

        execve(argv[1], newargv, enivp);
        // execve("/bin/ls", newargv ,enivp);
        printf("Hello, I am Child\n");
    } else {
        int pid = wait(NULL);
        printf("Hello, I am Parent\n");
        printf("Pid of child is:: %d", pid);
    }
    return 0;
}