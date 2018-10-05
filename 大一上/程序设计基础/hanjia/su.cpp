#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#define N 1000000+10
#define min(a,b) ((a)<(b) ? (a):(b))
#define max(a,b) ((a)>(b) ? (a):(b))
bool a[N];
void is_prime()
{
	long long i,j;
	a[0]=false;
	a[1]=false;
	for(i=2;i<N;i++)
	{
		if(a[i])
		{
			if(i*i>N)
				continue;
		}
		for(j=i*i;j<N;j=j+i)
			a[j]=false;
			
	}
}
int main()
{
	long n,t;
	scanf("%ld",&t);
	memset(a,true,sizeof(a));
	is_prime();
	while(t--)
	{
		scanf("%ld",&n);
		if(a[n])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
