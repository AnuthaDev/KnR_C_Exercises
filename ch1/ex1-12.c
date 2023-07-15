#include <stdio.h>
/* Program that prints input 1 word per line */
main()
{
	int c;
	while ((c = getchar()) != EOF)
	{
		// putchar((c == ' ' || c == '\t') ? '\n' : c);
		if (c == ' ' || c == '\t')
		{
			putchar('\n');
		}
		else
		{
			putchar(c);
		}
	}
}