// Kavya Mohan 2001362917 CS 370
// Assignment 3
// use gcc -pthread smoker.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

// GLOBAL VARIABLES
int         smokeCount;                                             // how many times smokers can smoke before dying
sem_t       table;
sem_t       agent;
sem_t       smokers[3];

void * agentThdFunc() {
    int options[3] = {0, 0, 0};                                     // stores how many times each combo is picked
    int randNum;
    
    // loop will run while smoker(s) is/are alive
    while(options[0] < smokeCount || options[1] < smokeCount || options[2] < smokeCount) {
        sem_wait(&table);                                           // wait until table is free

        randNum = (rand() % 3);                                     // pick a combination of materials

        // display which materials the agent picked if smoker is stil alive, otherwise repick
        if (randNum == 0 && options[0] < smokeCount) {
            printf("agent produced tobacco & paper\n");
            sem_post(&table);                                        // signals that table is open 
            sem_post(&smokers[randNum]);                             // wake appropriate smoker
            sem_wait(&agent);                                        // agent sleeps
            options[0]++;                           
        }
        else if (randNum == 1 && options[1] < smokeCount) {
            printf("agent produced matches & tobacco\n");
            sem_post(&table);                                        
            sem_post(&smokers[randNum]);                            
            sem_wait(&agent);                                        
            options[1]++;
        }
        else if (randNum == 2 && options[2] < smokeCount) {
            printf("agent produced matches & paper\n");
            sem_post(&table);                                        
            sem_post(&smokers[randNum]);                             
            sem_wait(&agent);                                       
            options[2]++;
        }
        else {
            sem_post(&table);
        }
    }
  
    return(0);
}

void * smokersThdFunc(void *i) {
    int     id = *(int *)i;                                                    // maintains 3 smokers using IDs
    int     timesSmoked = 0;
    
    if (timesSmoked == 0) {
        printf("Smoker %d starts...\n", id);
    }
    
    // loop runs while smoker is alive
    while (timesSmoked < smokeCount) {
        sem_wait(&smokers[id]);                                                 // sleep until signaled by agent
        sem_wait(&table);                                                       // wait for open table

        usleep(rand()%1500000);                                                 // smoke for rand period of time
        
        // print message for respective smoker after done smoking
        if (id == 0) {
            printf("\033[0;31mSmoker %d completed smoking\033[0m\n", id);
        }
        else if (id == 1) {
            printf("\033[0;32mSmoker %d completed smoking\033[0m\n", id);
        }
        else {
            printf("\033[0;34mSmoker %d completed smoking\033[0m\n", id);
        }
      
        // update smoke counts and signal table & agent
        if (timesSmoked++ < smokeCount) {
            sem_post(&table);
            sem_post(&agent);
        }                                                          
    }

    printf("Smoker %d dies of cancer.\n", id);                  
    
    pthread_exit(NULL);                                                         // terminate thread
   
    return(0);
}

int main(int argc, char **argv) {
    // variable declarations
    unsigned long int   agentThdErr, smokersThdErr[3], semRet;
    pthread_t           agentThd, smokersThd[3];
    int                 smokerID[3];

    // usage checking
    if (argc == 1) {
        printf("Usage: ./smoker <smokeCount>\n");
        exit(EXIT_FAILURE);
    }

    // proper command line usage checking
    if (argc != 2) {
        printf("Error, invalid number of command line arguments.\n");
        exit(EXIT_FAILURE);
    }

    smokeCount = atoi(argv[1]);                                      // convert argv[2] into an int

    // check that smokeCount is in valid range
    if (smokeCount < 3 || smokeCount > 10) {
        printf("Error, smokeCount must be >= 3 and <= 10\n");
        exit(EXIT_FAILURE);
    }

    // initialize table semaphore
    semRet = sem_init(&table, 0, 1);
    
    if (semRet != 0) {
        perror("Fail to initialize table semaphore\n");
        exit(EXIT_FAILURE);
    }

    // initialize agent semaphore
    semRet = sem_init(&agent, 0, 0);
    
    if (semRet != 0) {
        perror("Fail to initialize agent semaphore\n");
        exit(EXIT_FAILURE);
    }

    // initialize smokers semaphore
    for (int i = 0; i < 3; i++) {
        semRet = sem_init(&smokers[i], 0, 0);
        
        if (semRet != 0) {
            perror("Fail to initialize smokers semaphore\n");
            exit(EXIT_FAILURE);
        }
    }

    // create agent thread
    agentThdErr = pthread_create(&agentThd, NULL, &agentThdFunc, NULL);
    
    if (agentThdErr != 0) {
        perror("Agent thread fail to create.\n");
        exit(EXIT_FAILURE);
    }

    // create smokers threads and pass an ID to each 
    for (int i = 0; i < 3; i++) {
        smokerID[i] = i;
        
        smokersThdErr[i] = pthread_create(&smokersThd[i], NULL, &smokersThdFunc, &smokerID[i]);
       
        if (smokersThdErr[i] != 0) {
            perror("Smoker thread fail to create.\n");
            exit(EXIT_FAILURE);
        }
    }

    // wait for threads to complete
    pthread_join(agentThd, NULL);
    
    for (int i = 0; i <3; i++) {
        pthread_join(smokersThd[i], NULL);
    }
    
    exit(EXIT_SUCCESS);
}
