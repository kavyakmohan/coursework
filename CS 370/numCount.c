// Kavya Mohan 2001362917 CS 370
// Assignment 2
// use:     gcc -Wall -pedantic -g -pthread -o numCount numCount.c 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

// GLOBAL VARIABLES 
pthread_mutex_t             cntrLock;       // mutex for global counter declaration
pthread_mutex_t             resultsLock;    // mutex for result counters declaration
int                         cntr = 2;       // global counter
int                         pCnt = 0;       // perfect num counter
int                         aCnt = 0;       // abundant num counter
int                         dCnt = 0;       // deficient num counter
int                         limit = 0;      // limit entered by user

// Thread function
void * calculationFunct() {
    int                     n = 0;
    int                     sum = 0;
    while (cntr <= limit) {
        // Each thread receives a unique number from 2 to limit
        pthread_mutex_lock(&cntrLock);
        n = cntr;               
        cntr++;
        pthread_mutex_unlock(&cntrLock);

        // Calculate sum of proper positive divisors of n
        sum = 0;
        for (int i = 1; i < n; i++){
            if (n % i == 0) {
                sum = sum + i;
            }
        }

        // update counters
        pthread_mutex_lock(&resultsLock);
        if (sum == n)
            pCnt++;

        if (sum > n)
            aCnt++;

        if (sum < n)
            dCnt++;
        pthread_mutex_unlock(&resultsLock);
    }
    return     NULL;
}

int main(int argc, char **argv)
{
    unsigned long int       thdErr1, thdErr2, thdErr3, thdErr4, mtxErr1, mtxErr2;
    pthread_t               thd1, thd2, thd3, thd4;

    // proper usage checking
    if (argc == 1) {
        printf("Usage: ./numCount <s|p> <limitValue>\n");
        exit(0);
    }

    // check that sequential or parallel execution is selected
    if ((strcmp(argv[1], "s") != 0) & (strcmp(argv[1], "p") != 0)) {
        printf("Error, invalid command line arguments.\n");
        exit(0);
    }

    // Check that limitValue input is an int
    for (int i = 0; i < strlen(argv[2]); i++)
        if (argv[2][i] < '0' || argv[2][i] > '9') {
            printf("Error, invalid limit value.\n");
            exit(0);
        }

    // convert argv[2] into an integer
    limit = atoi(argv[2]);

    // Check that limitValue is valid
    if (limit < 100) {
        printf("Error, limit must be >= 100.\n");
        exit(0);
    }

    // Initialize mutexes
    mtxErr1 = pthread_mutex_init(&cntrLock, NULL);
    if (mtxErr1 != 0)
        perror("Global counter mutex initialization failed.\n");

    mtxErr2 = pthread_mutex_init(&resultsLock, NULL);
    if (mtxErr2 != 0)
        perror("Result counters mutex initialization failed.\n");

    // Before begining the calculations
    printf("Count of Perfect, Abundant, and Deficient numbers from %d to %d\nPlease wait. Running...\n\n", 1, limit);
    
    // create thread(s) for parallel or sequential execution and wait for their return
    if (strcmp(argv[1], "p") == 0) {
        thdErr1 = pthread_create(&thd1, NULL, &calculationFunct, NULL);
        if (thdErr1 != 0)
            perror("Thread 1 fail to create.\n");

        thdErr2 = pthread_create(&thd2, NULL, &calculationFunct, NULL);
        if (thdErr2 != 0)
            perror("Thread 2 fail to create.\n");

        thdErr3 = pthread_create(&thd3, NULL, &calculationFunct, NULL);
        if (thdErr3 != 0)
            perror("Thread 3 fail to create.\n");

        thdErr4 = pthread_create(&thd4, NULL, &calculationFunct, NULL);
        if (thdErr4 != 0)
            perror("Thread 4 fail to create.\n");

        pthread_join(thd1, NULL);
        pthread_join(thd2, NULL);
        pthread_join(thd3, NULL);
        pthread_join(thd4, NULL);
    }
    else {
        thdErr1 = pthread_create(&thd1, NULL, &calculationFunct, NULL);
        if (thdErr1 != 0)
            perror("Thread fail to create.\n");

        pthread_join(thd1, NULL);
    }

    // output results
    printf("Count of Perfect Numbers = %d\n", pCnt);
    printf("Count of Abundant Numbers = %d\n", aCnt);
    printf("Count of Deficient Numbers = %d\n", dCnt);
    printf("Total = %d\n\n", pCnt + aCnt + dCnt);
    return(0);
}