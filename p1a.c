#include <stdio.h>
#include <unistd.h>

int main (int argc) {
 
  int pid;
  
  //initial process
  pid = getpid();  
  printf("Main Process ID: %d, level: 0\n",pid);

  //argc is command line input n
  recursive_fork(1,argc);

} 

void recursive_fork (int level, int n) {

  //base case
  if (n==0) {
    return;
  }

  int pid = fork();
  int ppid = getppid();
  
  if (pid == 0) {
    //child process
    printf("Process ID: %d, Parent ID: %d, level: %d\n",pid,parentid, level);
    recursive_fork(level+1,n-1);
  }
}  
