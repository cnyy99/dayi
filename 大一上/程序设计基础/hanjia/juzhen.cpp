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
	int n,m,i,j,k,sum,d,f;
	struct juzhen b[6];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[0].a[i][j]);
		}
	}
	for(k=1;k<m;k++)
	{
	//	for(i=0;i<n;i++)
		{
			
			for(j=0;j<n;j++)
			{
				
					
				for(d=0;d<n;d++)
				{
					sum=0;	
					for(f=0;f<n;f++)
					{
						sum+=b[k-1].a[d][f]*b[0].a[f][d];	
						
					}printf("%d\t",sum);
					b[k].a[d][f]=sum;
				}
				
				
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(j?" %d":"%d",b[m-1].a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
