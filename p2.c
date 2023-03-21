#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>

int main (int argc, char *argv[]) {
  
  int n = atoi(argv[1]);
  float min=0,max=0;
  float total = 0;
  struct timeval start, end;
  long int runtime;
  
  if (argc == 3) {
    char *args[] = {argv[2], NULL};
  } else if (argc == 4) {
      char *args[] = {argv[2], argv[3], NULL};
  }
  for (int i = 0 ; i < n ; i++) {
      
    pid_t pid = fork();
      
    if (pid == 0) {
      //child process
      execvp(args[0], args);
      exit(1);
    } else {
        gettimeofday(&start, NULL);
        wait(NULL);
        gettimeofday(&end, NULL);
        runtime = (end.tv_sec * 1000 + end.tv_usec / 1000) - (start.tv_sec * 1000 + start.tv_usec / 1000);
        if (runtime > max) {
        max = runtime;
        } 
        if (min == 0) {
          min = runtime; 
        } else if (runtime < min) {
            min = runtime;
        }
        total += runtime;
        printf("Child %d Executed in %.2f millis", i+1, runtime);
    }
  }
  float average = total / n;
  printf("Max: %.2f millis", max);
  printf("Min: %.2f millis", min);
  printf("Average: %.2f millis", average);
  return 0;
}
  

