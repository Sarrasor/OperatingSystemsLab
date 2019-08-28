#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_SIZE 1024

char* reverse(const char in[]);

int main(int argc, char const *argv[])
{
	char word[STR_MAX_SIZE];

	printf("Enter a string: ");
	fgets(word, sizeof(word), stdin);
	char *res = reverse(word);

	printf("%s\n", res);
	free(res);
	return 0;
}

char* reverse(const char in[])
{
	char *res = malloc(strlen(in) + 1);
	int len = strlen(in);
	int j = 0;
	for (int i = len - 1; i >= 0; --i)
	{
		res[j++] = in[i];
	}
	res[++j] = '\0'; 
	return res;
}