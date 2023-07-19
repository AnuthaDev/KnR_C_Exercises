#include <stdio.h>

/* subsqueeze: delete all c from s */
void subsqueeze(char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

void squeeze(char s1[], char s2[])
{
	for (int i = 0; s2[i] != '\0'; i++)
		subsqueeze(s1, s2[i]);
}

int main()
{
	char str1[] = "Test String";
	char str2[] = "te";

	squeeze(str1, str2);

	printf("%s\n", str1);
}
