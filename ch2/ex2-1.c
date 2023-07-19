#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("\nBits of type char: %d\n", CHAR_BIT);
	printf("Range of type char: %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("Range of type signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Range of type unsigned char: 0 to %u\n\n", (unsigned)UCHAR_MAX);

	printf("Range of type short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("Range of type unsigned short: 0 to %u\n\n", (unsigned)USHRT_MAX);

	printf("Range of type int: %d to %d\n", INT_MIN, INT_MAX);
	printf("Range of type unsigned int: 0 to %u\n\n", UINT_MAX);

	printf("Range of type long: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("Range of type unsigned long: 0 to %lu\n\n", ULONG_MAX);

	printf("Positive Range of type float: %e to %e\n", FLT_MIN, FLT_MAX);
	printf("Negative Range of type float: %e to %e\n\n", -FLT_MAX, -FLT_MIN);

	printf("Positive Range of type double: %e to %e\n", DBL_MIN, DBL_MAX);
	printf("Negative Range of type double: %e to %e\n\n", -DBL_MAX, -DBL_MIN);

	return 0;
}