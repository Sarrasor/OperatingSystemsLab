#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	// Create a string to copy
  	const char *text = "This is a nice day";
  	size_t t_size = strlen(text) + 1;

  	// Open the destination file
	char* filename = "ex1.txt";
	int fd = open(filename, O_RDWR);

	// Resize the destination file to fit the string
  	ftruncate(fd, strlen(text));

  	// Open mmap
  	char *buf = mmap(NULL, t_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0);
  	
  	// Check if everything is ok
  	if(buf == MAP_FAILED)
  	{
  		close(fd);
  		printf("Something went wrong. Exiting.\n");
    	return 1;
  	}

  	// Write the string
  	for (size_t i = 0; i < t_size; i++)
    {
        buf[i] = text[i];
    }

    // Close mmap
	munmap(buf, t_size);

	// Close file
	close(fd);

	return 0;
}