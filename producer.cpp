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
    
}

