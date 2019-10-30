#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    // Open source and destination files
    int from = open("ex1.txt", O_RDONLY);
    int to = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);

    // Find the size of destination file 
    size_t from_fsize = lseek(from, 0, SEEK_END);

    // Resize the destination file to match the source
    ftruncate(to, from_fsize);

    // Open mmaps
    char *from_mmap = mmap(NULL, from_fsize, PROT_READ, MAP_PRIVATE, from, 0);
    char *to_mmap = mmap(NULL, from_fsize, PROT_READ | PROT_WRITE, MAP_SHARED, to, 0);

    // Copy the content from source to destination 
    memcpy(to_mmap, from_mmap, from_fsize);

    // Close mmaps
    munmap(from_mmap, from_fsize);
    munmap(to_mmap, from_fsize);

    // Close files
    close(from);
    close(to);

    return 0;
}