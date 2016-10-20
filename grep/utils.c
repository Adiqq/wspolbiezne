#include "utils.h"

void showError(char *message){
  perror(message);
  printf("Error code: %d\n", errno);
  exit(1);
}

void *handleNull(void *ptr, char *message){
  if(!ptr) showError(message);
  return ptr;
}

int handle(int rc, char *message){
  if(rc == -1) showError(message);
  return rc;
}
