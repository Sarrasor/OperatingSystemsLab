// Usage: ./ex3 N O

// N - integer
// O - Figure options. 

// Available options:
// a: Rectangle
// b: Right triangle
// c: Arrow
// d: Right-side-up triangle 

#include <stdio.h>

void rectangle(int n);
void right_triangle(int n);
void iso_triangle(int n);
void arrow(int n);


int main(int argc, char const *argv[])
{
	if(argc == 3)
	{
		int n = -1000;
		char task;

		sscanf(argv[1], "%d", &n);
		sscanf(argv[2], "%c", &task);

		if (n == -1000)
		{
			printf("You didn't provide a number as the first argument\n");
			return 0;
		}

		if (n <= 0)
		{
			printf("Your number is not positive. I'll do nothing\n");
			return 0;
		}

		if (task == 'a')
		{
			rectangle(n);	
		}
		else if (task == 'b')
		{
			right_triangle(n);
		}
		else if(task == 'c')
		{
			arrow(n);
		}
		else if(task == 'd')
		{
			iso_triangle(n);
		}
		else
		{
			printf("Unknown option. Available options are:\n");
			printf("a: Rectangle, b: Right triangle, c: Arrow, d: Right-side-up triangle\n");
		}
	}
	else
	{
		printf("Wrong number of arguments. I need exactly 2 of them: \n");
		printf("N - number\n");
		printf("O - option. Available options are:\n"); 
		printf("a: Rectangle, b: Right triangle, c: Arrow, d: Right-side-up triangle\n");
	}
	return 0;
}

void rectangle(int n)
{
	for(int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}

void right_triangle(int n)
{
	for(int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}

void arrow(int n)
{
	for(int i = 0; i <= n/2; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}

	for(int i = n/2; i > 0; --i)
	{
		for (int j = i; j > 0; --j)
		{
			printf("*");
		}
		printf("\n");
	}
}

void iso_triangle(int n)
{
	for(int i = 1; i <= n; ++i)
    {
        for(int space = 1; space <= n-i; ++space)
        {
            printf(" ");
        }

        int star = 0;
        while(star != 2*i-1)
        {
            ++star;
            printf("*");
        }

        printf("\n");
    }
}