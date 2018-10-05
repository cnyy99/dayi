#include<stdio.h>

int main()
{
	int m,n;
	int a[200][200];
	scanf("%d%d",&m,&n);
	int b[n];
	int c[m];
	int *p;
	for(p=&a[0][0];p<&a[0][0]+sizeof(a)/sizeof(a[0][0]);p++)
		scanf("%d",p);
	for(;;)
	
	return 0;
}
