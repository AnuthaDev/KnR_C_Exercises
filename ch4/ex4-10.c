#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define MAXLINE 1000
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main()
{
	int type;
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
		case '%':
			op2 = pop();
			if (op2 != 0.0)
			{
				push((int)pop() % (int)op2);
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

int getop(char s[])
{
	static int i, len;         /* using static variables */
	static char line[MAXLINE];

	int j;

	if (i == len)
	{ /* previous line read completely */
		len = getLine(line, MAXLINE);
		if (!len)
			return EOF;
		i = 0; /* reset line index */
	}

	j = 0;

	while (isblank(line[i]))
	{
		++i;
	}
	
	if (!isdigit(line[i]) && line[i] != '.')
	{
		return line[i++];
	}

	if (isdigit(line[i]))
		while (isdigit(line[i]))
		{
			s[j++] = line[i++];
		}

	if (line[i] == '.')
		while (isdigit(line[i]))
		{
			s[j++] = line[i++];
		}

	s[j] = '\0';

	return NUMBER;
}

/* More files incoming */

/* getLine: get line into s, return length of s */
int getLine(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
	{
		s[i++] = c;
	}

	if (c == '\n')
	{
		s[i++] = c;
	}

	s[i] = '\0';

	return i;
}