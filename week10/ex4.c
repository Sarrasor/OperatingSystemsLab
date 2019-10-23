#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
	// Open the specified directory
	char dir[] = "tmp";
	DIR* dirp = opendir(dir);
	if (dirp == NULL) return -1;

	char fn[64];
	struct dirent *ent;
	struct stat st;

	// Read every enery one by one
	while((ent = readdir(dirp)) != NULL)
	{
		// Remove . and .. 
		if(strcmp(ent->d_name, ".") && strcmp(ent->d_name, ".."))
		{
			// Create full file name for stat
			strcpy(fn, dir);
			strcat(fn, "/");
			strcat(fn, ent->d_name);
			
			// Collect #of hard links
			stat(fn, &st);

			// Select those, which have 2 or more hard links
			if(st.st_nlink > 1)
			{
				printf("File name: %s,  Ilink #%ld\n", ent->d_name, ent->d_ino);
			}

		}
	}
	return 0;
}