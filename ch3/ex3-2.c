#include <stdio.h>

#define SIZE 100

/* Convert newline and tab to visible escape sequences */
void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
	{
		switch (s[i])
		{
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;

		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;

		default:
			t[j++] = s[i];
			break;
		}
	}

	t[j] = '\0';

	return;
}

/* Convert escape sequences into real characters */
void epacse(char s[], char t[])
{
	int i = 0, j = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '\\')
		{
			switch (s[i + 1])
			{
			case 't':
				t[j++] = '\t';
				i += 2;
				break;

			case 'n':
				t[j++] = '\n';
				i += 2;
				break;

			default:
				t[j++] = s[i++];
				break;
			}
		}
		else
		{
			t[j++] = s[i++];
		}
	}

	t[j] = '\0';

	return;
}

int main()
{

	char s[] = "This	is\nthe	test	\nstring";
	char t[SIZE];

	escape(s, t);
	printf("%s\n", t);

	epacse(t, s);
	printf("%s\n", s);
}