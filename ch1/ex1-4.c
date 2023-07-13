#include <stdio.h>
/* print Celsius-Fahrenheit table
for celsius = -40, 0, ..., 120; floating-point version */
main()
{
	float fahr, celsius;
	float lower, upper, step;
	lower = -40;	 /* lower limit of temperatuire scale */
	upper = 120; /* upper limit */
	step = 20;	 /* step size */
	celsius = lower;
	printf("Celsius Fahr\n");
	while (celsius <= upper)
	{
		fahr = ((9.0 / 5.0) * celsius) + 32.0;
		printf("%3.0f %8.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
