#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; function version */

float fahr2cels(float fahr);

main()
{
	float fahr, celsius;
	float lower, upper, step;
	lower = 0;	 /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20;	 /* step size */
	fahr = lower;
	printf("Fahr Celsius\n");
	while (fahr <= upper)
	{
		celsius = fahr2cels(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

float fahr2cels(float fahr)
{
	return ((5.0 / 9.0) * (fahr - 32.0));
}