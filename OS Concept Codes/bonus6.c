#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp)
{
    for(char **environ = envp; *environ != 0; environ++) {
        char *newEnv = *environ;
        printf("%s\n", newEnv);
    }
    return 0;
}