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
int h[100];
int k;	
int n,m;
void jia(int row,int line,int step)
{
	if(row<0||n<=row||line<0||m<=line)
		return;
	if(save[row][line]||str[row][line]=='#')
		return ;
	if(row==n-1&&line==m-1)
	{
		k=step<k?step:k;
		return;
	}
	
	save[row][line]=1;
	jia(row+1,line,step+1);
	jia(row-1,line,step+1);
	jia(row,line+1,step+1);
	jia(row,line-1,step+1);
	save[row][line]=0;
}
int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int sum=0;
		for(i=0;i<n;i++)
		{
			getchar();	
			for(j=0;j<m;j++)
			{
					
				scanf("%c",&str[i][j]);
			}
		}
		memset(save,0,sizeof(save));
		k=9999999;
		
		
		jia(0,0,0);
			
		printf("%d\n",k);
	}
	return 0;
}
