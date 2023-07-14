#include <stdio.h>
/* copy input to output replacing multiple blanks by single blank */
main()
{
	int prevc = 0;
	int c;
	while ((c = getchar()) != EOF)
	{
		if (c != ' ' || prevc != ' ')
		{
			putchar(prevc = c);
		}
	}
}