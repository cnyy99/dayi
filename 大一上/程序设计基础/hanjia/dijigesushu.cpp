#include<stdio.h> 
#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <string>  
#include <queue>  
#include <stack>  
#include <map>  
#include <math.h>  
#include <vector>  
#include <stdlib.h>  
#include <algorithm>  
#define N 1000100
using namespace std; 
bool a[N];
long size;
long long b[N];
void is_prime()
{
	long long i,k,j;
	a[0]=false;
	a[1]=false;
	for(i=2;i<N;i++)
	{
		if(a[i])
		{
			
			if(i*i>N)
			{
				continue;
			}
		}
		for(j=i*i;j<N;j=j+i)
		{
			a[j]=false;
		}
	}
	for(i=2,k=1;i<N;i++)
	{
		if(a[i])
		{
			for(j=i;j<N;j+=i)
			{
				b[j]=k;
			}
			k++;
		}
	}
}
int main()
{
	long long i,t,j,sum,m,step;
//	scanf("%lld",&t);
	memset(a,true,sizeof(a));
	is_prime();
	while(scanf("%lld",&m)!=EOF)
	{
		
		printf("%lld\n",b[m]);
	}
}
