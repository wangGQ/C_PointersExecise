#include <stdio.h>
#define DEL_CH '*' 
#define NUL '\0'
void my_deblank(char string[] ) 
{
	int i, k, t, d;
	int endIdx = 0;
	for (endIdx = 0; string[endIdx] != '\0'; ++endIdx) 
		;
	for (i = 0; i != endIdx; ++i) {
		if (string[i] == DEL_CH ) {
			k = i;
			while (string[++k] == DEL_CH);	
			if (k == i + 1) continue;
			t = i + 1;
			d = k - t;
			while (k <= endIdx) 
				string[t++] = string[k++];
			endIdx -= d;	
		}
	}
}

int is_white(int ch)
{
	return ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\n'
		|| ch == '\r';
}

void deblank(char string[]) //two pointers
{
	char *dest;	
	char *src;
	int ch;
	src = string;
	dest = string++;
	
	while ( (ch = *src++) != NUL ) {
		if (is_white(ch) ) {
			if (src == string || !is_white(dest[-1]))
				*dest++ = ' ';
		}
		else {
			*dest++	= ch;
		}
	}
	*dest = NUL;
}

int main()
{
	char *s = "ab  defg   h ijk ";
	deblank(s);
	puts(s);
	return 0;
}
