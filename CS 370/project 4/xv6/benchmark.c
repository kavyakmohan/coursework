// Kavya Mohan
// CS 370 Fall 2020
// Project #4

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    uint fd;          // file descriptor
    char buf[1];
    uint numProcs;           // num of child processes to fork
    //uint input;      // file input after converted from char
    char str[5];
    uint ctr = 0;
    char curr;
    uint sTime;
    uint currentTime;
    uint creationTime, startTime, runTime, ioTime, endTime;
    uint tat, response, avgtat, avgresponse;
    uint counter;
    int CPU_ITERATIONS = 10000000;
    
    // Usage Checking
    if (argc != 2)
    {
        printf(2, "Usage: benchmark processes.txt\n");
        exit();
    }

    // use open syscall to get file descriptor 
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        printf(1, "failed to open %s\n", argv[1]);
        exit();
    }
  
    // initialize input variables
    for (int i = 0; i < 5; i++) {
        str[i] = '\0';
    }
    ctr = 0;
    buf[0] = '\0';
    
    // read in numProcs
    while (buf[0] != ' ' && buf[0] != '\n') {
        read(fd, buf, 1);
        curr = buf[0];
        str[ctr] = curr;
        ctr++;
    }
    numProcs = atoi(str);
 
    // create arrays
    uint arrivalTime[numProcs];     
    uint data[numProcs][9];
    uint ctimes[numProcs];
    uint stimes[numProcs];
    uint etimes[numProcs];
    uint rtimes[numProcs];
    uint iotimes[numProcs];
    
    for (int i = 0; i < numProcs; i++) {
        // reset input variables
        ctr = 0;
        for (int k = 0; k < 5; k++) {
            str[k] = '\0';
        }
        buf[0] = '\0';
        
        // read arrival time
        while (buf[0] != ' ' && buf[0] != '\n') {
            read(fd, buf, 1);
            curr = buf[0];
            str[ctr] = curr;
            ctr++;
        }
        arrivalTime[i] = atoi(str);
        
        // reset input variables
        ctr = 0;
        for (int k = 0; k < 5; k++) {
            str[k] = '\0';
        }
        buf[0] = '\0';
        
        //read in numCPUbursts and store in [i][0]
        while (buf[0] != ' ' && buf[0] != '\n') {
            read(fd, buf, 1);
            curr = buf[0];
            str[ctr] = curr;
            ctr++;
        }
        data[i][0] = atoi(str);
        
        uint bursts = data[i][0] * 2;
        
        for (int j = 0; j < bursts - 1; j++) {
            // reset input variables
            ctr = 0;
            for (int k = 0; k < 5; k++) {
                str[k] = '\0';
            }
            buf[0] = '\0';
            
            // read in each burst time
            while (buf[0] != ' ' && buf[0] != '\n') {
                read(fd, buf, 1);
                curr = buf[0];
                str[ctr] = curr;
                ctr++;
            }
            // store in data[i][j]
            data[i][j + 1] = atoi(str);
        }
    }
    
    //PARENT 
    int pids[numProcs];
    //uint tats[numProcs];
    //uint responses[numProcs];
    int pid;
    
    sTime = uptime();                                   // startTime
    
    for (int i = 0; i < numProcs; i++) {
        //printf(2, "loop num %d\n", i);
        currentTime = uptime();                         //check that arrival time > currT - sT before forking child
        
        //printf(2, "arrival time is %d\n", arrivalTime[i]);
        if (arrivalTime[i] <= (currentTime - sTime)) {
            uint sleepTime = currentTime - sTime;
            sleepTime = sleepTime - arrivalTime[i];
            sleep(sleepTime);
        }
        
        //printf(2, "forking child\n");
        pid = fork();                               // fork child
        
        if (pid > 0) {
            pids[i] = getProcessStats(&creationTime, &startTime, &runTime, &ioTime, &endTime);
            
            ctimes[i] = creationTime;
            stimes[i] = startTime;
            rtimes[i] = runTime;
            iotimes[i] = ioTime;
            etimes[i] = endTime;
            
           // printf(2, "Child[%d]: Creation Time[%d] - Start Time[%d] - End Time[%d] - Run Time[%d] - IO Time[%d]\n", pids[i], creationTime, startTime, endTime, runTime);  
            
           // tat = endTime - creationTime;
           // avgtat += tat;
            
           // response = startTime - creationTime;
           // avgresponse += response;
            
           // printf(2, "Turnaround Time[%d] - Response Time[%d]\n\n", tat, response);
        }
        
        if (pid == 0) {
            // CHILD PROCESS
            //printf(2, "inside child process\n");
            counter = 0;
            pid = getpid();
            //printf(2, "pid: %d\n", pid);
            
            // first CPU burst
            for (int j = 0; j < data[i][1] * CPU_ITERATIONS; j++) {
                counter++;
            }
            //printf(2, "exited first CPU BURST\n");
            
            uint totalBursts = data[i][0];
            //printf(2, "total bursts %d\n", totalBursts);
            
            if (totalBursts > 1) {
                for (int j = 2; j < data[i][0] * 2; j++) {
                    if (j % 2 == 0) {
                        for (int k = 0; k < data[i][j]; k++) {
                            printf(2, "Child[%d]: Prints for the [%d] time\n", pid, k);
                        }
                    }
                    
                    if (j % 2 != 0) {
                        for (int k = 0; k < data[i][j] * CPU_ITERATIONS; k++) {
                            counter++;
                        }
                    }
                }
            }
            exit();  
        }
    }
  
    
    
    for (int i = 0; i < numProcs; i++) {
        //print process timing info 
          printf(2, "Child[%d]: Creation Time[%d] - Start Time[%d] - End Time[%d] - Run Time[%d] - IO Time[%d]\n", pids[i], ctimes[i], stimes[i], etimes[i], rtimes[i], iotimes[i]);  
            
           tat = etimes[i] - ctimes[i];
           avgtat += tat;
            
           response = stimes[i] - ctimes[i];
           avgresponse += response;
            
           printf(2, "Turnaround Time[%d] - Response Time[%d]\n\n", tat, response);
    }
    
    
    // print avg tat
    avgtat = avgtat / numProcs;
    printf(2, "Avg TAT: %d\n", avgtat);
    
    // print avg response
    avgresponse = avgresponse / numProcs;
    printf(2, "Avg Response: %d\n", avgresponse);


    close(fd);
    exit();
}

