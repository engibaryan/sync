#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t semaphore;
int shared_resource = 0;

void *semaphore_thread(void *arg) {
    sem_wait(&semaphore);
    // Critical Section
    shared_resource++;
    printf("Semaphore thread: %d\n", shared_resource);
    sem_post(&semaphore);
    return NULL;
}

int main() {
    sem_init(&semaphore, 0, 1); // Binary semaphore (initial value = 1)

    pthread_t t1, t2;
    pthread_create(&t1, NULL, semaphore_thread, NULL);
    pthread_create(&t2, NULL, semaphore_thread, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&semaphore);
    return 0;
}

