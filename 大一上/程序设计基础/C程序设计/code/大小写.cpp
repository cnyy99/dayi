#include<stdio.h>
#include<ctype.h>
int main()
{
	char ch;
	while(ch=getchar())
	{
		ch=toupper(ch);
		putchar(ch);
		printf("\n");
	}
	return 0;
}
