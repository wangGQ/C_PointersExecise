#include <stdio.h>

int main()
{
	float a,b,c, maxL;
	printf("please enter 3 numbers for a triangle:\n");
	scanf("%f%f%f", &a, &b, &c);
	maxL = a>b?a:b;	
	maxL = maxL>c?maxL:c;
	if (maxL >= a+b+c-maxL) {
		printf("it is not a triangle!");
		return 0;
	}
	if (a == b && b == c)
		printf("equilateral triangle");
	else if (a == b || a == c || b == c)
		printf("isosceles triangle");
	else
		printf("normal triangle");
	return 0;
}
