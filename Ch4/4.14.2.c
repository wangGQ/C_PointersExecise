#include <stdio.h>

int main()
{
	int i, j, f;
	for (i = 1; i <= 100; ++i) {
		f = 1;
		for (j = 2; j <= i/2; ++j) {
			if (i%j == 0) {
				f = 0;
				break;
			}
		}
		if (f)
			printf("%d\n", i);
	}	
	return 0;
}
