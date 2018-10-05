#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<map>
#include<algorithm>
#include <vector>
#define MAXM 25
using namespace std;
char str[MAXM][MAXM];
int save[MAXM][MAXM];
int h[100];
int k;	
int n,m;
map<char,int>ditu;
void jia(int row,int line,int step)
{
	if(row<0||n<=row||line<0||m<=line)
		return;
	if(ditu[str[row][line]])
		return ;
//	if(row==n-1&&line==m-1)
	k=step>k?step:k;
	ditu[str[row][line]]=1;
	jia(row+1,line,step+1);
	jia(row-1,line,step+1);
	jia(row,line+1,step+1);
	jia(row,line-1,step+1);
	ditu[str[row][line]]=0;
}
int main()
{
	int i,j,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int sum=0;
		for(i=0;i<n;i++)
		{
			getchar();	
			for(j=0;j<m;j++)
			{
				scanf("%c",&str[i][j]);
				ditu[str[i][j]]=0;
			}
		}
		k=-1;
		jia(0,0,1);
		printf("%d\n",k);
		
	}
	return 0;
}
