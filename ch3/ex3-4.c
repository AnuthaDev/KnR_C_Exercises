#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * In a two's complement system, range of values of an int is -(2^wordsize - 1) to (2^wordsize-1)-1
 * 
 * e.g. -128 to 127, so if we negate -128, the value 128 overflows
 * 
 * To solve this problem we can use abs() function after modules instead of negation
*/
void revstr(char *str1)
{
	// declare variable
	int i, len, temp;
	len = strlen(str1); // use strlen() to get the length of str string

	// use for loop to iterate the string
	for (i = 0; i < len / 2; i++)
	{
		// temp variable use to temporary hold the string
		temp = str1[i];
		str1[i] = str1[len - i - 1];
		str1[len - i - 1] = temp;
	}
}

void itoa(signed char n, char s[])
{
	int i, sign;
	sign = n;
	i = 0;

	do
	{
		s[i++] = abs(n % 10) + '0';

	} while ((n /= 10) != 0);

	if (sign < 0)
	{
		s[i++] = '-';
	}

	s[i] = '\0';
	revstr(s);
}

int main()
{

	char str[100];
	signed char x = -128;
	itoa(x, str);

	printf("%s\n", str);
}