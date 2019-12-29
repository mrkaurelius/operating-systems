#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *functionC();
pthread_mutex_t mutex_1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;


int main(int argc, char *argv[])
{
    int rc1, rc2;
    pthread_t thread_1, thread_2;

    // Create independent threads each of will execute functionC

    if (( rc1 = pthread_create ( &thread_1, NULL, &functionC, NULL ) )) {
        printf("thread creation failed");
        
    }

    if (( rc2 = pthread_create ( &thread_2, NULL, &functionC, NULL ) )) {
        printf("thread creation failed");
    }

    pthread_join( thread_1, NULL );
    pthread_join( thread_2, NULL );


    exit(0);
}

void *functionC()
{
    pthread_mutex_lock( &mutex_1 );
    counter++;
    printf("Counter value: %d\n", counter);
    pthread_mutex_unlock( &mutex_1 );
}
