#include <stdio.h>

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main()
{
	char ch = 'D';
	char ret = lower(ch);

	printf("%c\n", ret);
	return 0;
}