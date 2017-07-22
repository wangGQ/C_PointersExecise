#include <stdio.h>

int main()
{
	char c;
	int cnt = 0;
	while ((c = getchar()) != EOF) {
		if (c == '{') {
			cnt += 1;
		}	
		else if (c == '}') {
			cnt -= 1;
			if (cnt < 0) 
				break;
		}
	}
	if (cnt != 0) 
		printf("error match\n");
	else
		printf("pass\n");
	return 0;
}
		
