#include <stdio.h>

int main (int argc) {
 
  int value, pid, parentid,level=0;
  int i;
  
  parentid = getpid();  
  printf("Main Process ID: %d, level: %d",parentid, level);

  for(i=0 ; i<argc ; i++) {
    level += 1
    value = fork();
    pid = getpid();
    parentid = getppid();
    if (value == 0) {
      printf("Process ID: %d, Parent ID: %d, level: %d",pid,parentid, level);
    }
  }
} 

  
