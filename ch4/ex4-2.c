#include <stdio.h>
#include <ctype.h>

int powered(int exp)
{
	int base = 10;
	int power;
	power = 1;
	while (exp-- > 0)
		power *= base;

	return power;
}

int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	return i;
}

double atof(char s[])
{
	double val, power, exppower;
	int i, sign, expsign, exp;

	for (i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
	{
		i++;
	}

	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;
	}

	expsign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (exp = 0; isdigit(s[i]); i++)
	{
		exp = exp * 10 + s[i] - '0';
	}

	return (expsign == 1) ? (sign * val / power) * powered(exp) : (sign * val / power) / powered(exp);
}

int main(void)
{
	printf("%f\n", atof("100.5e-2"));
}
