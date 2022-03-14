#include "types.h"
#include "stat.h"
#include "user.h"
#include "date.h"

int 
main(int argc, char *argv[])
{
  // Check for proper usage
  if(argc == 1 || ((argc == 2) && (strcmp(argv[1], "-s") == 0))) {
    printf(2, "Usage: time command\nUsage: time -s command\n");
    exit();
  }
    
  // Checking if measuring time in ticks or seconds
  // argvIter will point to command the user wishes to time
  int argvIter = 0;
  if(strcmp(argv[1], "-s") == 0)
    argvIter = 2;
  else
    argvIter = 1;
    
  // Get current time using uptime
  int startTime = uptime();
  
  // Fork a child process
  int pid = fork();
  if(pid > 0) {
    // Parent waits for child to exit
    pid = wait();
  }
  else if(pid == 0) {
    // Child executes the command the user wishes to time
    if(exec(argv[argvIter], argv + argvIter) < 0) {
      printf(2, "Error: Child failed to execute %s\n", argv[argvIter]);
      exit();
    }
  } 
  else {
    printf(2, "Error: fork() failed\n");
    exit();
  }
    
  // Get current time after returning from exec
  int endTime = uptime();
  
  // Calculate runtime
  int runTime = endTime - startTime;
  
  // Convert to seconds and output time if necessary
  if(argvIter == 2) {
    int wholeSeconds = runTime/100;
    int decimalSeconds = runTime%100;
    printf(2, "Real Time in seconds: %d.%d second(s)\n", wholeSeconds, decimalSeconds);
  }
  else {
    // Output time in ticks
    printf(2, "Real Time in tick(s): %d tick(s)\n", runTime);
  }
  
  exit();
}
