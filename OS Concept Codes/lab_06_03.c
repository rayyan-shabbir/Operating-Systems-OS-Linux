#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

typedef struct numbers {
    int a, b;
    // int sq;
}numbers;

int sq = 0;

void *f1(void *arg)
{
    numbers obj1 = *(numbers*)arg;

    // printf("num1: %d", obj1.a); 
    // printf("num2: %d", obj1.b);

    sq = pow(obj1.a, obj1.b);
    printf("I am child thread\n");
    pthread_exit((void*)&sq);
}


int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("No. of arguments are invalid\n");
    }

    // printf(argv[1]);
    // printf(argv[2]);
    numbers obj;

    pthread_t tid;

    obj.a = atoi(argv[1]);
    obj.b = atoi(argv[2]);
    // obj.sq = 0;

    pthread_create(&tid, NULL, f1, (void*)&obj);
    pthread_join(tid, NULL);

    printf("Square of %d and %d is: %d", obj.a, obj.b, sq);
    printf("\n");

    while(1) {

    }
    // printf("I am Parent thred");
    return 0;
}