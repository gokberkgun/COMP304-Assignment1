#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
 
int main (int argc, char *argv[]) {
 
  int n = atoi(argv[1]);
  int level = 0;
  
  //initial process
  pid_t pid = getpid();  
  printf("Main Process ID: %d, level: 0\n",pid);
  
  for (int i = 0; i < n+1; i++) {

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
