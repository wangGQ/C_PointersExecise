#include <stdio.h>
#include <math.h>

int main()
{
	float n, old, new;
	printf("enter a number:");
	scanf("%f", &n);
	if (n < 0) {
		printf("can not be negative number!\n");
		return 0;
	}
	new = 1;
	do {
		old = new;	
		new = (old+n/old)/2;
		printf("%.15e\n", new);
	} while (old != new);	
	return 0;
}
