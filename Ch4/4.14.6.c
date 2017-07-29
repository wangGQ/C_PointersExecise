#include <stdio.h>
#include <string.h>
int substr(char dst[], char src[], int start, int len)
{
	int i = 0;	
	if (start < 0 || len <= 0 || start >= strlen(src)) {
		dst[0] = '\0';
		return 0;
	}
	while (i < len && src[start + i] != '\0') {
		dst[i] = src[start + i];
		++i;
	}
	dst[i] =  '\0';
	return i;
}

int main()
{
	char s1[100];
	char s2[] = "hello world";
	int n = substr(s1, s2, 5, 20);
	printf("get %d chars:%s", n, s1);
	return 0;
}
