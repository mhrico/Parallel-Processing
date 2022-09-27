#include <stdio.h>
#include <pthread.h>

#define MAX 16
#define MAX_THREAD 4

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
int sum[4] = { 0 };
int part = 0;

void* sum_array(void* arg)
{

    int thread_part = part++;

    for (int i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++) // max er value joto, otogula jinish array e thaka lagbe, nahole somossa hobe
        sum[thread_part] += a[i]; // 4 ta process tai max(16) ke 4 diye bhag kore index ber kora
}

int main()
{

    pthread_t threads[MAX_THREAD];

    for (int i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);

    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);

    int total_sum = 0;
    for (int i = 0; i < MAX_THREAD; i++)
        total_sum += sum[i];

    printf("Sum: %d\n", total_sum);

    return 0;
}
