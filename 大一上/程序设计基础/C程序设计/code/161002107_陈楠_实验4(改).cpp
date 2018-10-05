#include<stdio.h>
int main(void)
{
	int n;
	printf("Please input a natural number:");
	unsigned long long factorial(int m);
	unsigned long long summ(int n);
	scanf("%d",&n);
	printf("%lld",summ(n));
	return 0;	
}
unsigned long long factorial(int m)
{
	if(m==1||m==0)
		return 1;
	else
		return factorial(m-1)*m;
}
unsigned long long summ(int n)
{
	if(n==1||n==0)
		return 1;
	else
		return factorial(n)+summ(n-1);
}

