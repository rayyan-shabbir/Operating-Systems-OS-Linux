#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char *argv[], char *envp) {
    int j = 0;
    // int sz = argc - 2;

    char *cmd = argv[1];
    char *lst[3];


    for (int i = 2; i < argc; i++)
    {
        *lst[j] = *argv[i];
        j++;
        printf("\nThe argument at index %d has value %s", i, argv[i]);
        if(i-1 == argc) break;
    }


    printf("\ncmd: %s", cmd);

    for (int i = 0; i < 3; i++)
    {
        printf("\nlst: %s", lst[i]);
    }
    

    // int cpid = fork();

    // if(cpid == 0) {
    //     execve(cmd, lst, envp);
    //     printf("Hello, I am Child\n");
    // } else {
    //     wait(NULL);
    //     printf("Hello, I am Parent\n");
    // }
    return 0;
}