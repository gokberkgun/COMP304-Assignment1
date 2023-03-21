#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_NUMBERS 1000

int main(int argc, char *argv[]) {
 
  int x = atoi(argv[1]);
  int n = atoi(argv[2]);
 
  int sequence[MAX_NUMBERS];
  int count = 0;
  pid_t pids[n];
  int status;
  char buffer[1024];
  while (fgets(buffer,1024,stdin) != NULL) {
    int number = atoi(buffer);
    sequence[count] = number;
    count++;
  }
  int portion = count / n;
  int remainder = count % n;
  int flag = 0;

  for (int i = 0 ; i < n ; i++) {
    pids[i] = fork();
    
    if (pids[i] == 0) {
       int start = i * portion;
       int end = (i + 1) * portion;
       for (int j = start ; j < end ; j++) {
         if (sequence[j] == x) {
           printf("Found at index %d\n", j);
           flag = 1;
           exit(0);
         }
       }
     exit(1);
    }
  }  
  for (int i = 0 ; i < n ; i++) {
    waitpid(pids[i], &status, 0);
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
      for (int k = 0 ; k < n ; k++) {
        if (k != i) {
          kill(pids[k], SIGTERM);
         }
      }
    }
  }
  if (flag == 0) {
    printf("Number not found.");
  }
  
  return 0;
}
