#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<map>
#include<algorithm>
#include <vector>
#define MAXM 110
using namespace std;
char str[MAXM][MAXM];
int save[MAXM][MAXM];
int h[11],a[11];
int k;	
int n,m;
void jia(int row,int line,int step)
{
	if(line<=1)
	{
		for(int p=0;p<step;p++)
		{
			printf(p?"% d":"%d",h[p]);
			
		}
		printf("\n");
		return ; 
	}
	for(int j=row+1;j<n;j++)
	{
		h[step]=a[j];
		jia(j,line-1,step+1);
	}
	return;
}
int main()
{
	int i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		printf("\n");
		for(i=1;i<=n;i++)
		{
			memset(h,0,sizeof(h));
			for(j=0;j<n-i+1;j++)
			{
				h[0]=a[j];
				jia(j,i,1);
			}
		}
			
	}
	return 0;
}
