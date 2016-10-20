#define _GNU_SOURCE

#include <assert.h>

#include "utils.h"
#include "file.h"

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
