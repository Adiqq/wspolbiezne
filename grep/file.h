#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <string.h>

FILE *openFile(char *filename);
void readLines(FILE *stream, char *pattern, FILE* outStream);

#endif
