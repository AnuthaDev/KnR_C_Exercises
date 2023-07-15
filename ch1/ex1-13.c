#include <stdio.h>
/* Histogram of word lengths */
#define IN 1
#define OUT 2
#define MAXSIZE 10
main()
{
	int lengtharr[MAXSIZE];

	for (int i = 0; i < MAXSIZE; i++)
	{
		lengtharr[i] = 0;
	}

	int state = OUT;

	int c;
	int curlen = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t' || c == ' ' || c == '\n')
		{
			if (curlen > 0 && curlen <= MAXSIZE)
			{
				lengtharr[curlen]++;
			}

			curlen = 0;
			state = OUT;
		}
		else
		{
			curlen++;

			if (state == OUT)
			{
				state = IN;
			}
		}
	}

	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("%d: ", i);
		for (int j = 0; j < lengtharr[i]; j++)
		{
			printf("*");
		}

		printf("\n");
	}
}