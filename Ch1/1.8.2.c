#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main()
{
	char ch;
	int isbegin = TRUE, line = 1;
	
	while ((ch = getchar()) != EOF) {
		if (isbegin) {
			printf("%d ", line++);
			isbegin = FALSE;
		}	
		if (ch == '\n') 
			isbegin = TRUE;
		putchar(ch);
	}
	return 0;
}
