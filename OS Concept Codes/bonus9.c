#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **envp)
{
    for (int idx = 0; envp[idx] != NULL; idx++)
    {
        printf("%s\n", envp[idx]);
    }
    return 0;
}