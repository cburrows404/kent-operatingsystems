#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
    int fileDescription;
    char * shmpath;
    struct sharedMem *consumerMem;
    shmpath = argv[1];
    fileDescription = shm_open(shmpath, O_RDWR, 0);



    //Truncate it to the size of the struct, ensures extra is not used
    ftruncate(fileDescription, sizeof(*consumerMem));

    //Maps to local memory space
    consumerMem = static_cast<sharedMem*>(mmap(NULL, sizeof(*consumerMem), PROT_READ | PROT_WRITE, MAP_SHARED, fileDescription, 0));

    for (int i = 4; i >= 0; --i) {
        sem_wait(&(consumerMem->full));
        sem_wait(&(consumerMem->mutex));

        int itemToConsume;
        itemToConsume = consumerMem->table[consumerMem->out];
        std::cout << "item consumed: " <<  itemToConsume << std::endl;
        consumerMem->out = (consumerMem->out + 1) % TABLE_SIZE;

        sem_post(&(consumerMem->mutex));
        sem_post(&(consumerMem->empty));
    }
    shm_unlink(shmpath);
    return 0;
}