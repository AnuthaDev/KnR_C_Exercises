#include <stdio.h>
/* word count program testing */
#define IN 1
#define OUT 0

main()
{
	int state = OUT;
	int lines, words, chars;
	int c;
	lines = words = chars = 0;

	while ((c = getchar()) != EOF)
	{
		chars++;

		if (c == '\n')
			lines++;

		if (c == '\t' || c == ' ' || c == '\n')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			words++;
		}
	}

	printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);
}

/* Inputs most likely to uncover bugs:
	- Empty Input
	- Input not ending with newline
	- Unicode Input
*/