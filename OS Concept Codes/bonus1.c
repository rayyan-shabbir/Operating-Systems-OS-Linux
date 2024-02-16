#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Enter 2 command line arguments...");
        exit(0);
    } 

    printf("The value of argc is %d\n", argc);

    int sum = 0;

    for (int i = 1; i < argc; i++)
    {
        // sum = sum + (*argv[i] - '0');
        sum = sum + atoi(argv[i]);
        // printf("\nThe argument at index %d has value %s", i, argv[i]);
    }

    printf("\nSum = %d", sum);
    printf("\n");
    
    return 0;
}