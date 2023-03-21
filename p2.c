#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <fcntl.h>

int main (int argc, char *argv[]) {
  
  int n = atoi(argv[1]);
  float min=0,max=0;
  float total = 0;
  struct timeval start, end;
  float runtime;
   
  char *args[3] = {NULL};
  
  if (argc == 3) {
    args[0] = argv[2];
  } else if (argc == 4) {
    args[0] = argv[2];
    args[1] = argv[3];
  }
 
  int fd = open("/dev/null", O_WRONLY);
  
  for (int i = 0 ; i < n ; i++) {
      
    pid_t pid = fork();
      
    if (pid == 0) {
      //child process
      dup2(fd, STDOUT_FILENO);
      dup2(fd, STDERR_FILENO);
      execvp(args[0], args);
      exit(1);
    } else {
        gettimeofday(&start, NULL);
        wait(NULL);
        gettimeofday(&end, NULL);
        runtime = (float) (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        if (runtime > max) {
        max = runtime;
        } 
        if (min == 0) {
          min = runtime; 
        } else if (runtime < min) {
            min = runtime;
        }
        total += runtime;
        printf("Child %d Executed in %.2f millis\n", i+1, (float) runtime);
    }
  }
  float average = total / n;
  printf("Max: %.2f millis\n", max);
  printf("Min: %.2f millis\n", min);
  printf("Average: %.2f millis\n", average);
  return 0;
}
  

