#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int counter = 0;
sem_t sem; // semaphore

void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        sem_wait(&sem);     // P(): saidn critical section
        counter++;          // critical section
        sem_post(&sem);     // V(): aan
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    sem_init(&sem, 0, 1);    // semaphore = 1 (binary semaphore)

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Counter = %d\n", counter);

    sem_destroy(&sem);
    return 0; 
}