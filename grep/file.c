#include "file.h"

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
