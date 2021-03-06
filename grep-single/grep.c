#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

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

FILE *openFile(char *filename)
{
  FILE *file = fopen(filename, "r");
  return file;
}

void readLines(FILE *stream, char *pattern, FILE* outStream){
  const int n = 255;
  char line[n];
  
  while(fgets(line, n, stream)){
    if(strstr(line, pattern)){
      fputs(line, outStream);
    }
  }
}

int main(int argc, char** argv)
{
  int rc;
  FILE *stream;
  
  assert(argc == 3);
  char *pattern = argv[1];
  char *filename = argv[2];
  
  stream = handleNull(openFile(filename), "Opening file");
  readLines(stream, pattern, stdout);
  rc = handle(fclose(stream), "Closing file");
  return rc;
}
