#include <stdio.h>
#include <ctype.h>

#define SIZE 1000

int expand(char s1[], char s2[])
{
	int i = 0, j = 0;

	while (s1[i] != '\0')
	{
		switch (s1[i])
		{
		case '-':
			if (isalnum(s1[i - 1]) && isalnum(s1[i + 1]))
			{
				for (char ch = s1[i - 1] + 1; ch < s1[i + 1]; ch++)
				{
					if (isalnum(ch))
					{
					s2[j++] = ch;
					}
				}
				i++;
			}
			else
			{
				s2[j++] = s1[i++];
			}

			break;

		default:
			s2[j++] = s1[i++];
			break;
		}
	}
	s2[j++] = '\0';

	return 0;
}

int main()
{

	char s1[] = "A-z";
	char s2[SIZE];

	if (expand(s1, s2))
	{
		printf("Malformed Input\n");
	}
	else
	{
		printf("%s\n", s2);
	}
}