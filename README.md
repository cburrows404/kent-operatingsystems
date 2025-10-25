# kent-operatingsystems
Charlie Burrows
Operating Systems producer/consumer assignment

Consumer:
The consumer.cpp file initializes a consumer to consume data put into the shared memory by the producer. The consumer accesses the shared memory by waiting until the semaphores signal if the producer is already accessing the table or if the table is full.
The consumer program can be run with : make consumer

Producer:
The producer.cpp file initializes a producer to produce data into the shared memory for the consumer to consume. The producer waits for either the consumer to be done consuming (signaled by the mutex lock semaphore) or for the table to be empty, at which point it will produce more items to go on the table.
The producer program can be run with:  make producer

Shared memory:
The memBuffer.hpp file initializes the sharedMem data structure, used by both the producer and consumer. In the data structure, there are 2 intigers specifiying the data coming in and going out, as well as 3 semaphores for when the table is full, empty, or if another program is accessing it.
The shared memory data structure is used by both the producer and consumer and therefor does not need to be explicitly run.

Makefile:
The makefile for this program contains methods to fully run synchronized producer-consumer processes.

Documentation:
The DocumentationOS.docx contains my documentation for this project, including details on how each process is run and example outputs.