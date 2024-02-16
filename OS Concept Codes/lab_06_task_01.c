#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

typedef struct numbers{
    int a, b;
}numbers;

void *power(void *arg) {
    // int r;
    numbers *n1 = (numbers*)arg;

    int *sq = (int*)malloc(sizeof(int));
    *sq = pow(n1->a, n1->b);

    printf("Child sq = %d", *sq);

    pthread_exit(((void*)sq));
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("No. of commands entered are invalid...\n");
        exit(0);
    }

    numbers obj1;
    pthread_t tid;

    obj1.a = atoi(argv[1]);
    obj1.b = atoi(argv[2]); 

    void *res;

    pthread_create(&tid, NULL, power, (void*)&obj1);
    pthread_join(tid, &res);

    printf("\nSquare of %d and %d is: %d", obj1.a, obj1.b, *(int*)res);
    printf("\n");
    free(res);

    while(1) {

    }
    return 0;
}