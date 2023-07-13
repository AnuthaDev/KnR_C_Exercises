#include <stdio.h>
/* test getchar != EOF equals 1 or 0 */
main()
{
	int c;
	while (1)
	{
		printf("%d\n", getchar() != EOF);

		if (getchar() == EOF)
		{
			break;
		}
		
	}
}