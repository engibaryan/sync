#include <pthread.h>
#include <stdio.h>

pthread_spinlock_t spinlock;
int shared_resource = 0;

void *spinlock_thread(void *arg) {
    pthread_spin_lock(&spinlock);
    // Critical Section
    shared_resource++;
    printf("Spinlock thread: %d\n", shared_resource);
    pthread_spin_unlock(&spinlock);
    return NULL;
}

int main() {
    pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, spinlock_thread, NULL);
    pthread_create(&t2, NULL, spinlock_thread, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_spin_destroy(&spinlock);
    return 0;
}

