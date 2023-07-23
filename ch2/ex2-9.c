#include <stdio.h>

int bitcount(unsigned int x)
{
	int val;

	for (val = 0; x != 0; x &= x - 1)
		val++;

	return val;
}

int main()
{

	printf("%d\n", bitcount(245)); // 6

	return 0;
}