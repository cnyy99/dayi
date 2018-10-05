#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <string>  
#include <queue>  
#include <stack>  
#include <map>  
#include <set> 
#include <math.h>  
#include <vector>  
#include <stdlib.h>  
#include <algorithm> 
using namespace std;  
int main()
{
	unsigned long long a,b,c;
	int t,i;
	scanf("%d",&t);
	for(i=1;i<t+1;i++) 
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a+b==c||b+c==a||a+c==b)
		{
			printf("Case %d: Happy!\n",i);
			continue;
		}
		else if(a-b==c||b-c==a||a-c==b||c-b==a||c-a==b||b-a==c)
		{
			printf("Case %d: Happy!\n",i);
			continue;
		}
		else if(a*b==c||b*c==a||a*c==b)
		{
			printf("Case %d: Happy!\n",i);
			continue;
		}
		else if((b!=0&&a/(b*1.0)==c)||(c!=0&&b/(c*1.0)==a)||(c!=0&&a/(c*1.0)==b)||(a!=0&&b/(a*1.0)==c)||(b!=0&&c/(b*1.0)==a)||(a!=0&&c/(a*1.0)==b))
		{
			printf("Case %d: Happy!\n",i);
			continue;
		}
		else if((b!=0&&a%b==c)||(c!=0&&b%c==a)||(c!=0&&a%c==b)||(a!=0&&b%a==c)||(b!=0&&c%b==a)||(a!=0&&c%a==b))
		{
			printf("Case %d: Happy!\n",i);
			continue;
		}
		else
			printf("Case %d: Kill!\n",i);
	}
}
