#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// return time it took the parameter function to run
int
sys_time(void)
{
  return 0;
}

// Project 4
int sys_getProcessStats(void)
{
    uint *creationTime;
    uint *startTime;
    uint *runTime;
    uint *ioTime;
    uint *endTime;
    
    if (argptr(0, (char**)&creationTime, sizeof(uint)) < 0)
        return -1;
        
    if (argptr(1, (char **)&startTime, sizeof(uint)) < 0)
        return -1;
        
    if (argptr(2, (char **)&runTime, sizeof(uint)) < 0)
        return -1;
        
    if (argptr(3, (char **)&ioTime, sizeof(uint)) < 0)
        return -1;
        
    if (argptr(4, (char **)&endTime, sizeof(uint)) < 0)
        return -1;
        
    return getProcessStats(creationTime, startTime, runTime, ioTime, endTime);
}

int sys_updateIOTime(void)
{
  int time;

  if(argint(0, &time) < 0)
    return -1;
    
  return updateIOTime(time);
}
