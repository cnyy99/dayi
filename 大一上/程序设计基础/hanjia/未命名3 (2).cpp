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
	int t,k,i,m;	
	map<string,int>color;
	map<string,int>::iterator iter;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			exit(0);
		int number;
		string name;
		color.clear();
		for(k=0;k<n;k++)
		{
			string str;
			cin>>str;
			color[str]++;
		}
		n=0;
		for(iter=color.begin();iter!=color.end();iter++)
		{
			i=iter->second;
			if(i>n)
			{
				n=i;
				name=iter->first;
			}
		}
		cout<<name<<endl;
	}
	return 0;
}
