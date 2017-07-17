#include <stdio.h>
#include <string.h>
#define MAX_CHAR 1000
char line[MAX_CHAR + 1];
char longest[MAX_CHAR + 1];
int main()
{
	int max = 0;
	while (gets(line) != NULL) {
		int len = strlen(line);
		if (len > max) {
			max = len;
			strcpy(longest, line);
		}
	}
	puts(longest);
	return 0;
}
