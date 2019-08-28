#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char const *argv[])
{
	int integer = INT_MAX;
	float flt = FLT_MAX;
	double dbl = DBL_MAX;
	
	printf("Int size: %lu Int value: %d\n", sizeof(integer), integer);
	printf("Float size: %lu Float value: %f\n", sizeof(flt), flt);
	printf("Double size: %lu Double value: %f\n", sizeof(dbl), dbl);
	return 0;
}