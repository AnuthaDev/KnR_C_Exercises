#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void itoa(int n, char s[], int minwidth)
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

	while (strlen(s)<minwidth)
	{
		s[i++] = ' ';
	}
	
	s[i] = '\0';
	revstr(s);
}

int main()
{

	char str[100];
	int x = -128;
	itoa(x, str, 15);

	printf("%s\n", str);
}