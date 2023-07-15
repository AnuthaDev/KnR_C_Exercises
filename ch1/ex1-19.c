#include <stdio.h>
/* Reverse input linewise */
#define MAXLINE 1000 /* maximum input line length */

void reverse(char line[], int len);
int get_line(char line[], int maxline);

int main()
{
	int len;						/* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = get_line(line, MAXLINE)) > 0)
	{
		reverse(line, len);
		printf("%s", line);
	}

	return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

void reverse(char line[], int len)
{
	int start = 0;
	int end = len - 2;

	while (start < end)
	{
		char temp = line[start];
		line[start] = line[end];
		line[end] = temp;
		start++;
		end--;
	}
}