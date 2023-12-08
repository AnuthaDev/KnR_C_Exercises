#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNC 'A'

int getop(char[]);
void push(double);
double pop(void);
void func(char[]);

int main()
{
	int type;
	double op2, op1;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case FUNC:
			func(s);
			break;
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
			{
				push(pop() / op2);
			}
			else
			{
				printf("error: zero divisor\n");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

void func(char s[])
{
	if (strcmp("sin", s) == 0)
		push(sin(pop()));
	else if (strcmp("cos", s) == 0)
		push(cos(pop()));
	else if (strcmp("exp", s) == 0)
		push(exp(pop()));
	else if (strcmp("pow", s) == 0)
	{
		double val = pop();
		push(pow(pop(), val));
	}
	else
		printf("error: operation not supported");
}
/* Here is another file*/
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* Here is another another */

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	i = 0;

	if (islower(c))
	{
		while (islower(s[++i] = c = getch()))
			;

		s[i] = '\0';
		if (c != EOF)
		{
			ungetch(c);
		}

		if (strlen(s) > 1)
		{
			return FUNC;
		}
		else
		{
			return s[0];
		}
	}

	if (!isdigit(c) && c != '.')
	{
		return c;
	}

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

/* More files incoming */

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}