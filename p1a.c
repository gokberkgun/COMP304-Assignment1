#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void recursive_fork (int level, int n) {

  //base case
  if (n==0) {
    return;
  }

  for (int i = 0; i<3 ; i++) {
 
    int pid = fork();
    int ppid = getppid();

    if (pid == 0) {
      //child process
      printf("Process ID: %d, Parent ID: %d, level: %d\n",getpid(),getppid(), level);
      recursive_fork(level+1,n-1);
      exit(0);
    }        
  }
}

int main (int argc) {
 
  int pid;
  int n = argc;
  
  //initial process
  pid = getpid();  
  printf("Main Process ID: %d, level: 0\n",pid);

  recursive_fork(1,n);

  return 0;

} 
