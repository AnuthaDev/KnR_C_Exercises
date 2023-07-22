#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	/* Rightmost n-bits of y are copied over to x starting at position p */
	return (x & ~(~(~0 << n) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
}

int main()
{
	// 100 0000 0000
	unsigned int a = 1024;
	// 11 1111
	unsigned int b = 63;

	// 111 1110 0000 = 2016
	unsigned r = setbits(a, 9, 5, b);

	printf("Result: %d\n", r);
}