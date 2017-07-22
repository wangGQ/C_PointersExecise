#include <stdio.h>
#include <string.h>
void copy_n(char dst[], char src[], int n)
{
	int i = 0;	
	while (i < n && src[i] != '\0') {
		dst[i] = src[i];
		++i;
	}
	while (i++ < n)
		dst[i] = '\0';
}

int main()
{
	char s1[100];
	char s2[] = "hello world";
	copy_n(s1, s2, 5);
	puts(s1);
	return 0;
}
