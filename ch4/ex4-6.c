#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

char varray[26] = {0};

/**
 * Example:
 * 10 A = 20 B = A B +
 *    30
*/
int main()
{
	int type, lastvar = 0;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
		{
			push(pop() + pop());
			break;
		}
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
		case '=':
			pop();
			if (isupper(lastvar))
				varray[lastvar - 'A'] = pop();
			else
				printf("error: invalid variable name\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;

		default:
			if (isupper(type))
				push(varray[type - 'A']);
			else
				printf("error: unknown command %s\n", s);
			break;
		}
		lastvar = type;
	}
	return 0;
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

	if (!isdigit(c) && c != '.')
	{
		return c;
	}

	i = 0;

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