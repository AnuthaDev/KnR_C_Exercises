#include <stdio.h>

#define NUM_OFFSET 0
#define LOWER_OFFSET 10
#define UPPER_OFFSET 36

#define ARRLEN 62

main()
{
	int c;
	int lenarr[ARRLEN];

	for (int i = 0; i < ARRLEN; i++)
	{
		lenarr[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
		{
			lenarr[(c - '0') + NUM_OFFSET]++;
		}
		else if (c >= 'a' && c <= 'z')
		{
			lenarr[(c - 'a') + LOWER_OFFSET]++;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			lenarr[(c - 'A') + UPPER_OFFSET]++;
		}
	}

	for (int i = 0; i < ARRLEN; i++)
	{
		if (i < LOWER_OFFSET)
		{
			putchar('0' + i - NUM_OFFSET);
		}
		else if (i < UPPER_OFFSET)
		{
			putchar('a' + i - LOWER_OFFSET);
		}
		else
		{
			putchar('A' + i - UPPER_OFFSET);
		}

		putchar(':');
		putchar(' ');

		for (int j = 0; j < lenarr[i]; j++)
		{
			putchar('*');
		}

		putchar('\n');
	}
}