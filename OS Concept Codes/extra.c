#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

typedef struct numbers {
    int a, b;
}numbers;

void* power(void *args) {
    numbers* n1 = (numbers*)args;

    int *res = (int*)malloc(sizeof(int));

    *res = pow(n1->a, n1->b);

    pthread_exit((void*)*res);
}

int main(char* argc, char* argv[]) {
    if(argc != 3) {
        printf("Invalid no. of arguments\n");
        ecit(0);
    }

    numbers n;
    n.a = atoi(argv[1]);
    n.b = atoi(argv[2]);


    pthread_t tid;
    int* res;

    pthread_create(&tid, NULL, power, (void*)&n);
    pthread_join(tid, (void*)&res);

    printf("Square is: %d", (int*)*res);
    return 0;
}