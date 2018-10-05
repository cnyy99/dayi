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
struct juzhen
{
	int a[31][31];
};
int main()
{
	long long n,m,i,j,k,sum,d,f;
	struct juzhen b[6];
	scanf("%lld%lld",&n,&m);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lld",&b[0].a[i][j]);
		}
	}
	if(m==0)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j==0)
				{
					if(i==j)
						printf("1");
					else
						printf("0");
				}
				else
				{
					if(i==j)
						printf(" 1");
					else
						printf(" 0");
				}
			}
			printf("\n");
		}
		return 0;
	}
	for(k=1;k<m;k++)
	{
		for(j=0;j<n;j++)
		{
			for(d=0;d<n;d++)
			{
				b[k].a[j][d]=0;
				for(f=0;f<n;f++)
				{
					b[k].a[j][d]+=b[k-1].a[j][f]*b[0].a[f][d];	
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(j?" %lld":"%lld",b[m-1].a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
