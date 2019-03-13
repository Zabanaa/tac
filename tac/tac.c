#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char *filename;
    FILE *file_to_read;

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

    // close the file
    fclose(file_to_read);
}