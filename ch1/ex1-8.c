#include <stdio.h>
/* count blanks, tabs, newlines */
main()
{
	long blanks, tabs, newlines;
	blanks = 0;
	tabs = 0;
	newlines = 0;

	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ')
		{
			blanks++;
		}else if (ch == '\t')
		{
			tabs++;
		}else if (ch == '\n')
		{
			newlines++;
		}
	}

	printf("Blanks: %ld\nTabs: %ld\nNewlines: %ld\n", blanks, tabs, newlines);
}