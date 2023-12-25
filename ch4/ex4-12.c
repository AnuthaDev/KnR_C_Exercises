#include <stdio.h>

int itoa(int num, char str[])
{
	static int idx = 0;
	if (num)
	{
		itoa(num / 10, str);
		str[idx++] = num % 10 + '0';
		str[idx] = '\0';
	}
}

int main()
{
	char str[10];
	itoa(12345, str);

	printf("%s\n", str);
	return 0;
}