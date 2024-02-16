#include <string.h>
#include <stdio.h>
#include <pthread.h>

void *f1(void *arg)
{
    printf("I am child thread\n");
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    time_t t1, t2;
    time(&t1);
    // <Your Code Here>
    time(&t2);
    // int* msg[100];
    // for(int i = 0; i < 100; i++) {
    //     *msg[i] = (i+1);
    // }

    pthread_t tids[1000];

    for (int i = 0; i < 1000; i++)
    {
        pthread_create(&tids[i], NULL, f1, NULL);
        pthread_join(tids[i], NULL);
    }

    printf("It took us %ld seconds to complete the task\n", t2 - t1);
    return 0;
}