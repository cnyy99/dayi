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
#define p(i) (i)*(i) 
using namespace std;  
int main()
{
    int n,m,i,j,k,sum;
    scanf("%d%d",&m,&n);
    int a[301];
    memset(a,1,sizeof(a));
    for(i=m;i<=n;i++)
    {
    	memset(a,1,sizeof(a));
		for(j=1;j<=i;j++)
    	{
    		for(k=1;k<=i;k++)
    		{
    			sum=p(j)+p(k);
    			if(sum==p(i)&&a[j])
    			{
    				a[k]=0;
					printf("%d %d\n",j,k);
				}
			}
		}
	}
    return 0;
}
