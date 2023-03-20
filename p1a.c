#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
 
int main (int argc) {
 
  int n = argc;
  int level = 0;
  
  //initial process
  pid_t pid = getpid();  
  printf("Main Process ID: %d, level: 0\n",pid);
  
  for (int i = 0; i < n; i++) {

    pid_t pid = fork();

    if (pid == 0) { 
     
      level++;

      printf("Process ID: %d, Parent ID: %d, level: %d \n", getpid(), getppid(), level);

    } else {
      wait(NULL);
    }
  }

  return 0;

} 
