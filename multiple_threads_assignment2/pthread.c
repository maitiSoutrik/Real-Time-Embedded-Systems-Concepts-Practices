#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sched.h>
#include <syslog.h>

#define COUNT  128  // number of threads to spin

typedef struct
{
    int threadIdx;
} threadParams_t;


// POSIX thread declarations and scheduling attributes
//
pthread_t threads[COUNT];
threadParams_t threadParams[COUNT];


// Unsafe global
int gsum=0;

void *incThread(void *threadp)
{
    threadParams_t *threadParams = (threadParams_t *)threadp;

    for(int i = 0; i <= threadParams->threadIdx; i++)
    {
        gsum += 1;
    }


    // printf("Increment thread idx=%d, gsum=%d\n", threadParams->threadIdx, gsum);
    syslog(LOG_INFO, "[COURSE:1][ASSIGNMENT:2]: Thread idx=%d, sum[1...%d]=%d\n",
            threadParams->threadIdx, threadParams->threadIdx, gsum);

}


// void *decThread(void *threadp)
// {
//     int i;
//     threadParams_t *threadParams = (threadParams_t *)threadp;

//     for(i=0; i<COUNT; i++)
//     {
//         gsum=gsum-i;
//         printf("Decrement thread idx=%d, gsum=%d\n", threadParams->threadIdx, gsum);
//     }
// }




int main (int argc, char *argv[])
{
//    int rc;

    for(int i = 0; i < COUNT; i++)
    {
        threadParams[i].threadIdx=i;
        pthread_create(&threads[i],   // pointer to thread descriptor
                        (void *)0,     // use default attributes
                        incThread, // thread function entry point
                        (void *)&(threadParams[i]) // parameters to pass in
                        );
    }

   for(int i=0; i<COUNT; i++)
   {
        pthread_join(threads[i], NULL);
   }

   printf("TEST COMPLETE\n");
}
