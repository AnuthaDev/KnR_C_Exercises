#include <stdio.h>

unsigned int rightrot(unsigned x, int n)
{
	// Find leftmost set bit, and wrap around to that position
	int pos = 0;
	int temp = x;
	while (temp >>= 1)
		pos++;

	return (x >> n) | ((x & ~(~0 << n)) << pos - 1);
}

int main()
{
	unsigned int ret = rightrot(10, 2);

	printf("%d\n", ret);
	return 0;
}