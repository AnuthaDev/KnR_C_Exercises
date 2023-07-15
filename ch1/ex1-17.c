#include <stdio.h>
/* Print lines longer than 80 characters */
#define MAXLINE 1000 /* maximum input line length */

#define THRESHOLD 80

int get_line(char line[], int maxline);

int main()
{
	int len;						/* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > THRESHOLD)
		{
			printf("%s", line);
		}
	return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;
	int len = 0;

	for (i = 0; ((c = getchar()) != EOF) && c != '\n'; ++i)
	{
		if (i < lim - 1)
		{
			len = i;
			s[len++] = c;
		}
	}

	if (c == '\n')
	{
		if (i == len)
		{
			s[len] = c;
			i = ++len;
		}
	}
	s[len] = '\0';
	return i;
}