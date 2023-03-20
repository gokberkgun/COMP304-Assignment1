#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
 
int main (int argc) {
 
  int pid;
  int n = argc;
  
  //initial process
  pid = getpid();  
  printf("Main Process ID: %d, level: 0\n",pid);
  
  for (int i = 0 ; i<n ; i++) {
    fork();
  }

  printf("Process ID: %d, Parent ID: %d, level: %d\n",getpid(),getppid(), level);
  wait(NULL);

  return 0;

} 
