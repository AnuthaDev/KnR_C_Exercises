#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

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

void itob(int n, char s[], int b)
{
	int sign = n;
	int i = 0;
	do
	{
		s[i++] = digits[abs(n % b)];
	} while (n /= b);

	if (sign < 0)
	{
		s[i++] = '-';
	}

	s[i++] = '\0';

	revstr(s);
}

int main()
{
	int x = 123;

	char str[100];

	itob(x, str, 8);

	printf("%s\n", str);
}