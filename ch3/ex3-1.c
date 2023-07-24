#include <stdio.h>

/* Not a measurable performance difference on modern systems for tested values */
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	if (x == v[mid])
	{
		return x;
	}

	return -1; /* no match */
}

int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
							 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
							 26, 27, 28, 29, 30};

	int val = binsearch(12, arr, 31);

	printf("%d\n", val);
}