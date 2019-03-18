#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char *filename;
    FILE *file_to_read;
    char *file_content_buf;
    long file_size;

    // if nothing is passed, print the usage
    if(argc < 2)
    {
        printf("Usage: tac [FILENAME]\nWhere FILENAME is a path to a file you wish to concatenate\n");
        exit(EXIT_FAILURE);
    }

    // parse command line arguments to extract the filename
    filename = argv[1];

    // attempt to open the file
    file_to_read = fopen(filename, "r");

    // if an error occurs 
    // exit with an error message 

    if(file_to_read == NULL)
    {
        printf("tac: %s: No such file or directory\n", filename);
        exit(EXIT_FAILURE);
    }

    // get the file size
    fseek(file_to_read, 0L, SEEK_END);
    file_size = ftell(file_to_read);
    rewind(file_to_read);

    // then malloc
    file_content_buf = malloc(sizeof(char) * (file_size + 1));

    // if malloc fails, exit
    if(file_content_buf == NULL)
    {
        printf("Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }

    // read the file into the buffer
    fread(file_content_buf, sizeof(char), file_size, file_to_read);

    fprintf(stdout, "%s\n", file_content_buf);

    free(file_content_buf);

    // then do the buffered thing
    // aka read until the file size has been reached

    // close the file
    fclose(file_to_read);
}