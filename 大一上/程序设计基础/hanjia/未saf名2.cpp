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
int main()
{
	int i,j,k,t,n,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				sum+=i;
				if(i==n/i)
					continue;
				sum+=n/i;
			}
		}
		printf("%d\n",sum+1);
	}
}
