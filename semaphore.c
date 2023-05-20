#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <threads.h>

void* producer(sem_t* sem) {
    for(int i = 0;i < 100;i++) {
        sem_post(sem);
    }
}

void* consumer(sem_t* sem) {
    for(int i = 0;i < 100;i++) {
        sem_wait(sem);
    }
}

int main (int argc, char** argv) {
    sem_t sem;
    pthread_t foo, bar;
    pthread_create(&foo, NULL, producer, sem);


    return 0;
}