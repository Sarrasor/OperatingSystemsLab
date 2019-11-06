#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>

#define SIZE 1024

int my_tee(int append, char *fileName);

int main(int argc, char *argv[]) 
{
    // Check arguments
    if (argc < 2 && argc > 3) 
    {
        printf("Usage: %s [-a] <filename>\n", argv[0]);
        return -1;
    }

    char *fileName;
    int append = 0;

    // Read command line option
    if (argc == 2)
    {
        // No option
        fileName = argv[1];
    }
    else
    {
        // Option
        if(strcmp(argv[1], "-a"))
        {
            printf("Wrong argument. -a is only supported\n");
            printf("Usage: %s [-a] <filename>\n", argv[0]);
            return -1;
        }

        append = 1;
        fileName = argv[2];
    }

    return my_tee(append, fileName);
}

int my_tee(int append, char *fileName)
 {
    char buffer[SIZE];
    memset(buffer, 0, SIZE);

    // Open output file
    FILE *out;
    if(append)
    {
        out = fopen(fileName,"a");
    }
    else
    {
        out = fopen(fileName,"w");
    }

    if (out < 0) 
    {
        printf("Error when opening the output file: %s\n", fileName);
        return -1;
    }

    int in = 0;
    ssize_t numBytes;

    // While input from pipe exists
    while ((numBytes = read(in, buffer, SIZE)) > 0)
    {
        // Write to file
        if (fputs(buffer, out) == -1) 
        {
            printf("Error when writing to the output file: %s\n", fileName);
            return -1;
        }

        // Write to stdout
        fprintf(stdout, "%s", buffer);

        // Clear buffer
        memset(buffer, 0, sizeof(buffer));
    }

    if (numBytes == -1) 
    {
        printf("Error when reading from pipe\n");
        return -1;
    }

    return fclose(out);
}
