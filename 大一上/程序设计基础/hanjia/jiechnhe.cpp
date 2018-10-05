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
using namespace std;  
int main()
{
	char str[2010];
	while(scanf("%s",str)!=EOF)
	{
		int a[2010];
		memset(a,0,sizeof(a));
		queue<char>s;
		int cnt,i,l=strlen(str);
		cnt=0;
		for(i=0;i<l;i++)
		{
			if(str[i]!='5')
				s.push(str[i]);
			if((str[i]=='5'||i==l-1)&&(!s.empty()))
			{
				int num=0;
				while(!s.empty())
				{
					char pos=s.front();
					s.pop();
					num=num*10+pos-'0';
				}
				a[cnt++]=num;
			}
		}
		sort(a,a+cnt);
		for(i=cnt-1;i>=0;i--)
			printf(i?"%d ":"%d\n",a[i]);
		printf("\n");
	}
	
	return 0;
}

