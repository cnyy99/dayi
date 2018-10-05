#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int t,k;
	scanf("%d",&t);		
	map<string,string>color;
	map<string,string>color2;
	map<string,string>::iterator iter;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			exit(0);
		int number;
		string name;
		char str[17];
		color.clear();
		color2.clear();
		for(k=0;k<n;k++)
		{
			scanf("%s",str);
			color[str]=str;
			color2[str]=str;
			
		}
		iter=color.begin();
		k=color2.count(*iter);
		strcpy(name,*iter);
		for(iter=color.begin()+1;iter!=color.end();iter++)
		{
			number=color2.count(*iter);
			if(number>k)
			{
				strcpy(name,*iter);
			}
		}
		printf("%s",name);
	}
	return 0;
}
