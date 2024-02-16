#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int cake = 11;
int another[3];
int calendar[4] = {1, 2, 3, 4};
int main(int argc, char **argv, char **envp)
{
    int x[5] = {1, 2, 3, 4, 5};
    int hello = 0x10;
    int *writer = (int *)malloc(sizeof(int) * 10);

    // printf(hello);

    printf("Value: %d", writer[4]);
    return 0;
}
