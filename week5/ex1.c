#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

void* thread_function(void *thread_id)
{
   int tid = *(int*)thread_id;
   printf("Hello from thread #%d\n", tid);
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   for(int i = 0; i < NUM_THREADS; ++i)
   {
      printf("Creating a thread #%d\n", i);
      rc = pthread_create(&threads[i], NULL, thread_function, (void *)&i);
      if(rc)
      {
         printf("Can't create a thread.\n");
         exit(-1);
      }
      pthread_join(threads[i], NULL); // Fixes the program
   }
   pthread_exit(NULL);
}