#include <string.h>
#define LINE_SIZE 129

int main()
{
	char preLine[LINE_SIZE];
	char curLine[LINE_SIZE];
	int printed = 0;
	if (gets(preLine)) {
		while (gets(curLine)) {
			if (strcmp(preLine, curLine) != 0) {
				printed = 0;
				strcpy(preLine, curLine);
			}
			else if (!printed) {
				puts(curLine);
				printed = 1;
			}
		}
	}
	return 0;
}
