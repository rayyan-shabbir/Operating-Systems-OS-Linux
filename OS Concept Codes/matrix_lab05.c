#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define ROWS 3
#define COLS 4
#define MAX_THREAD 3

typedef struct mystruct{
    int matA[4];
    int matB[4];
}mystruct;

void* mat_sum(void* arg) {
    mystruct* obj = (mystruct*) arg;

    int *result = (int *)malloc(4 * sizeof(int));
    for(int i = 0; i < 4; i++) {
        result[i] = obj->matA[i] + obj->matB[i];
    }

    pthread_exit((void*)result);

}

int main()
{
    int mat_A[ROWS][COLS] = {1, 2, 3, 4, 1, 6, 3, 2, 9, 2, 3, 4};
    int mat_B[ROWS][COLS] = {5, 4, 6, 2, 4, 1, 2, 1, 0, 7, 5, 2};
    int sum[ROWS][COLS];

    mystruct arg1[MAX_THREAD];
    pthread_t arr[MAX_THREAD];

    for(int i = 0; i < MAX_THREAD; i++) {
        for (int j = 0; j < 4; j++)
        {
            arg1[i].matA[j] = mat_A[i][j];
            arg1[i].matB[j] = mat_B[i][j];
        }
        pthread_create(&arr[i], NULL, mat_sum, (void*)&arg1[i]);
        
    }


    for (int i = 0; i < 3; i++) {
        void **res;
        pthread_join(arr[i], res);

        for (int j = 0; j < 4; j++)
        {
            sum[i][j] = (*(int**)res)[j];
        }

        free(*(int**)res);    
    }

    return 0;
}
