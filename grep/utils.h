#ifndef UTILS_H
#define UTILS_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void showError(char *message);
void *handleNull(void *ptr, char *message);
int handle(int rc, char *message);

#endif
