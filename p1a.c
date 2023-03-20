#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


void recursive_fork (int level, int n) {

  //base case
  if (n==0) {
    return;
  }
 
  printf("Process ID: %d, Parent ID: %d, level: %d\n",getpid(),getppid(), level);

  for (int i = 0; i < n; i++) {
    pid_t pid = fork();

    if (pid < 0) {
      //incorrect fork
      exit(1);
    } else if (pid == 0) {
       //child process
       recursive_fork(level + 1, n - 1);
       exit(0);
    }
  }
  
  //parent process waits for all child processes to exit
  for (int i = 0; i < n; i++) {
    wait(NULL);
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
