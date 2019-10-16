// Program usage: ./ex1 "#of_page_frames" "filename"
// I'm assuming that clock interrupt occurs at every page request arrival.

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

// Max length of input string
#define MAX_LENGTH_TO_READ 10000
// Max # of input processes
#define MAX_LENGTH 1000
// Bit size of age field. Char is used
// "Memory" depends on the data type of age
// If you want to increase the size:
// 1) Change the type of "age" to int
// 2) Change AGE_SIZE to 32
#define AGE_SIZE 8

// Input file
FILE *input;

// Page table entry structure
typedef struct page
{
	int name;
	unsigned char age;
	int R;
} Page;

// Aging algorithm simulation. Takes input processes queque "in"
// Size of the queue "s" and number "npf" of records in the page table
float aging_algorithm(int in[], int s, int npf);

// Function that checks whether the page "name" is presented in "pages". 
// If it is, R bit is set and 1 is returned. 
int check_hit(Page *pages, int n, int name);

// Function that finds the oldest page and replaces it with page "name". 
// New page has age of 0 and R set.
int evict_page(Page *pages, int n, int name);

// Clock propogation simulation.
// Updates ages of every page entry and resets R bit
void propogate_clock(Page *pages, int n);

int main(int argc, char const *argv[])
{
	int npf = 10;
	char const *filename;

	if (argc != 3)
	{
		printf("Wrong input. Usage: ./ex1 '#ofpages' 'filename'\n");
		return -1;
	}
	else
	{
		npf = atoi(argv[1]);
		filename = argv[2];
	}

	int input_queue[MAX_LENGTH];
	int input_size;

	input = fopen(filename, "r"); 

	char l[MAX_LENGTH_TO_READ];

	if(input == NULL)
    {
        printf("Invalid input or file does not exist. Usage: ./ex1 '#ofpages' 'filename'\n");
        return -1;
    }
    
    fgets(l, MAX_LENGTH_TO_READ, input);

    char *token = strtok (l, " ");
    for(int i = 0;token != NULL; ++i)
    {
    	char *ptr;
    	int n = strtol(token, &ptr, 10);
    	input_queue[i] = n;
    	token = strtok(NULL, " ");
    	input_size++;
    }

    float result = aging_algorithm(input_queue, input_size, npf);

    printf("Hit/Miss: %f\n", result);

	return 0;
}

int check_hit(Page *pages, int n, int name)
{
	for (int i = 0; i < n; ++i)
	{
		if (pages[i].name == name)
		{
			pages[i].R = 1;
			return 1;
		}
	}
	return 0;
}

int evict_page(Page *pages, int n, int name)
{
	for (int i = 0; i < n; ++i)
	{
		if(pages[i].name == -1)
		{
			pages[i].name = name;
			pages[i].age = 0;
			pages[i].R = 1;
			// printf("Have free space\n");
			return 1;
		}
	}

	int indx = 0;
	for (int i = 1; i < n; ++i)
	{
		if (pages[i].age < pages[indx].age)
		{
			indx = i;
		}
	}

	// printf("Oldest age name: %d\n", pages[indx].name);
	pages[indx].name = name;
	pages[indx].age = 0;
	pages[indx].R = 1;
}

void propogate_clock(Page *pages, int n)
{
	// printf("Page table: \n");
	for (int i = 0; i < n; ++i)
	{
		// printf("Name: %d Age:  %d R: %d\n",pages[i].name, pages[i].age, pages[i].R);
		pages[i].age = pages[i].R << (AGE_SIZE - 1) | pages[i].age >> 1;
		pages[i].R = 0;
	}
	// printf("\n");
}

float aging_algorithm(int in[], int s, int npf)
{
    Page pages[npf];
    int nhit = 0, nmiss = 0;

    // Page table initialization
    for (int i = 0; i < npf; ++i)
    {
    	pages[i].name = -1;
    	pages[i].age = 0;
    	pages[i].R = 0;
    }

    // Page request arrival pipeline
    for (int i = 0; i < s; ++i)
    {
    	// printf("Requesting: %d\n", in[i]);
    	// Check if page is in the page table
    	if (check_hit(pages, npf, in[i]))
    	{
    		// Increment # of hits. R is set in check_hit
    		nhit++;
    	}
    	else
    	{
    		// Insert requested page
    		evict_page(pages, npf, in[i]);
    		// Increment # of misses
    		nmiss++;
    	}

    	propogate_clock(pages, npf);
    }

    // printf("Hits: %d Misses: %d\n", nhit, nmiss);

	return (float)nhit/nmiss;
}