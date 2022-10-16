#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sched.h>
#include <syslog.h>

typedef struct
{
    int threadIdx;
} threadParams_t;

// POSIX thread declarations and scheduling attributes
//
pthread_t threads[1];
threadParams_t threadParams[1];

void *pthread(void *threadp)
{
    syslog(LOG_INFO, "[COURSE:1][ASSIGNMENT:1] Hello World from Thread!\n");
}

int main (int argc, char *argv[])
{
   int rc;
   int i = 0;

   syslog(LOG_INFO, "[COURSE:1][ASSIGNMENT:1] Hello World from Main!\n");

   threadParams[i].threadIdx=i;

    pthread_create(&threads[i],   // pointer to thread descriptor
                    (void *)0,     // use default attributes
                    pthread, // thread function entry point
                    (void *)&(threadParams[i]) // parameters to pass in
                    );

    pthread_join(threads[i], NULL);

    closelog();

    printf("TEST COMPLETE\n");

    return 0;
}

