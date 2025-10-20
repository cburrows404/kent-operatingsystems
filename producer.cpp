#include <semaphore.h>
#include <iostream>
#include <pthread.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <unistd.h>
#include <fcntl.h>
#include <memoryapi.h>
#define TABLE_SIZE 2
 struct sharedMem {

        int table[TABLE_SIZE];

        int in;
        int out;

        sem_t mutex;
        sem_t empty;
        sem_t full;

    };
int main(int argc, char *argv[]) {
    int fileDescription;
    char * shmpath;
    struct sharedMem *producerMem;
    shmpath = argv[1];
    fileDescription=shm_open(shmpath, O_CREAT | O_RDWR, 0600);

    ftruncate(fd, sizeof(*producerMem))
    producerMem = static_cast<sharedMem*>(CreateFileMapping(NULL, NULL, PAGE_EXECUTE_READWRITE, sizeof(*producerMem), fileDescription, 0));

    sem_init(&(producerMem->mutex),1,1);
    sem_init(&(producerMem->full),1,0);
    sem_init(&(producerMem->empty),1,TABLE_SIZE);
    producerMem->in, producerMem->out=0;
    for(int i = 4; i >= 0; --i) {
        sem_wait(&producerMem->empty);
        sem_wait(&producerMem->mutex);

        int produced = rand();
        std::cout << "item produced: " << produced << std::endl;

        producerMem->table[producerMem->in] = produced;
        producerMem->in = (producerMem->in + 1) % TABLE_SIZE;

        sem_post(&producerMem->mutex);
        sem_post(&producerMem->full);
    }
    shm_unlink(shmpath);
    return 0;
}

