#include <stdio.h>
/* Remove trailing blanks */
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);

int main()
{
	int len;						/* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = get_line(line, MAXLINE)) > 0)
		printf("%s", line);

	return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;
	int count = 0;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		s[i] = c;
		if (c == '\t' || c == ' ')
		{
			count++;
		}else
		{
			count = 0;
		}
	}

	while (count--)
	{
		s[i--] = '\0';
	}
	
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}