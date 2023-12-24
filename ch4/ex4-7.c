#include <stdio.h>
#include <string.h>

#define BUFSIZE 1000
#define MAXLEN 1000

char buf[BUFSIZE];
int bufp = 0;


int getch(void){
	return (bufp>0)? buf[--bufp]:getchar();
}

int ungetch(int c)
{
	if(bufp>=BUFSIZE){
		printf("ungetch: too many characters\n");
		return 1;
	}else{
		buf[bufp++] = c;
		return 0;
	}
}


void ungets(char* chr){
	int len = strlen(chr);

	while(len){
		/* Ungetch in reverse order */
		ungetch(chr[--len]);
	}

	chr[0] = '\0';

}

int getstr(char* line, int limit)
{
  int i = 0, c;

  while (limit - 1 > 0 && (c = getch()) != EOF && c != '\n')
  {
    line[i++] = c;
  }

  if (c == '\n')
  {
    line[i++] = c;
  }

  line[i] = '\0';

  return i;
}


int main(){
	char str[MAXLEN];

	getstr(str, MAXLEN);

	printf("%s", str);

	ungets(str);

	getstr(str, MAXLEN);
	printf("%s", str);

	return 0;
}

/* NOTE: The ungets function doesn't need access to buf and bufp. Only the ungetch
 * function is enough */