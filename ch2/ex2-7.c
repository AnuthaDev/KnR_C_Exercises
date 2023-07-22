#include <stdio.h>

unsigned int invert(unsigned x, int p, int n)
{
	return x ^ ((~(~0 << n)) << (p - n + 1));
}

int main()
{
	unsigned int ret = invert(205, 5, 3);

	printf("%d\n", ret);
	return 0;
}