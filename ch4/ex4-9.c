#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

/* Needs to be declared array of int as EOF does not fit in char */
int buf[BUFSIZE]; 
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}

int main()
{

	int ch = getch();

	printf("%c\n", ch);

	ungetch(ch);

	printf("%c\n", getch());
	printf("%c\n", getch());

	return 0;
}