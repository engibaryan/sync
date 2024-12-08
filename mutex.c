#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
int shared_resource = 0;

void *mutex_thread(void *arg) {
    pthread_mutex_lock(&mutex);
    // Critical Section
    shared_resource++;
    printf("Mutex thread: %d\n", shared_resource);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, mutex_thread, NULL);
    pthread_create(&t2, NULL, mutex_thread, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}

