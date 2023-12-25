#include <stdio.h>
#include <string.h>

void reverse_r(char str[], int l, int r)
{
	if (l < r)
	{
		int temp = str[l];
		str[l] = str[r];
		str[r] = temp;

		reverse_r(str, l+1, r-1);
	}
}

void reverse (char str[]){
	reverse_r(str, 0, strlen(str)-1);
}

int main()
{
	char str[] = "hello";
	reverse(str);

	printf("%s\n", str);
	return 0;
}