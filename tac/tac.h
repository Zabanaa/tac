#ifndef _TACH_
#define _TACH_

#include <stdio.h>
#include <stdlib.h>

void print_usage_and_exit(void);

void tac(char buf[], size_t bufsize, FILE* fd);

FILE* open_file(char *filename);

#endif