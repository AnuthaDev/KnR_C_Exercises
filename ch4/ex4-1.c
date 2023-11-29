#include <stdio.h>
#include <string.h>

int strindex(char *s, char *t)
{
	int len_s = strlen(s);
	int len_t = strlen(t);

	int i, j, k;

	for (i = len_s - len_t; i >= 0; i--)
	{
		for (j = i, k = 0; j < len_s && s[j] == t[k]; j++, k++)
		;

		if (k>0 && t[k] == '\0')
		{
			return i;
		}
	}

	return -1;
}

int main(void)
{

	int y = strindex("assist", "s"); // y = 4

	printf("y: %d\n", y);
	return 0;
}