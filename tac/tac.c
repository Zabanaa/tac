#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
    char file_content_buf[8096];
    FILE *file_to_read;

    // if nothing is passed, print the usage
    if(argc < 2)
    {
        print_usage_and_exit();
    }

    // attempt to open the file
    file_to_read = open_file(argv[1]);

    // read the file in chunks
    tac(file_content_buf, sizeof(file_content_buf), file_to_read);

    // TODO:
    // [] do this for multiple files 
    // [] handle standard input 
    // [] handle -E (to add a $ at the end of each line) [read each buffer line by line and append a $]   
    // [] handle -b (same as above => but prepend the line number )
    // [] handle pootential errors with fread
    // [] then lookup a better a way to do it
    // ask for a code review on discord ? 
    // write to a buffer OR use fprintf ? ask the question
    // [] push 

    // close the file
    fclose(file_to_read);
}