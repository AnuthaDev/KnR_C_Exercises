#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main()
{
	int a = htoi("cafe");
	printf("%d\n", a);

	return 0;
}

int htoi(char s[])
{
	int retval = 0;
	int i = 0;

	if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
		i += 2;

	while (isxdigit(s[i]))
	{
		retval *= 16;

		// retval += isalpha(s[i]) ? tolower(s[i]) - 'a' + 10 : s[i] - '0';
		if (isalpha(s[i]))
			retval += tolower(s[i]) - 'a' + 10;
		else
			retval += s[i] - '0';

		i++;
	}

	return retval;
}