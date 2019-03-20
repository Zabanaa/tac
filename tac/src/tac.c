#include "tac.h"

void print_usage_and_exit(void)
{
    printf("Usage: tac [FILENAME]\nWhere FILENAME is a path to a file you wish to concatenate\n");
    exit(EXIT_FAILURE);
}

FILE* open_file(char *filename)
{
    FILE *fd;
    fd = fopen(filename, "r");

    if(fd == NULL)
    {
        printf("tac: %s: No such file or directory\n", filename);
        exit(EXIT_FAILURE);
    }

    return fd;
}

void tac(char buf[], size_t bufsize, FILE* fd)
{
    ssize_t total_bytes_read;
    while((total_bytes_read = fread(buf, sizeof(char), bufsize + 1, fd) ) != 0)
    {
        buf[total_bytes_read] = '\0';
        fprintf(stdout, "%s", buf);
    }
}