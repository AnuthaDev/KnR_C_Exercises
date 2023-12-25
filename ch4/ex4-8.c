#include <stdio.h>

int buf = -1;

int getch(void)
{
	if (buf >= 0)
	{
		/* If buf is a valid character, return and reset it */
		int retval = buf;
		buf = -1;
		return retval;
	}
	else
	{
		return getchar();
	}
}

void ungetch(int c)
{
	buf = c;
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