#include<stdio.h>
#include<string.h>
#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int>a;
	set<int>b;
	set<int>::iterator iter;
	int k,t,i,j,n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		a.clear();
		b.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			a.insert(t);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&t);
			b.insert(t);
		}
		for(iter=a.begin();iter!=a.end();iter++)
		{
			if(b.count(*iter)==0)
			{
				b.insert(*iter);
				m++;	
			}
		}
		for(iter=b.begin();iter!=b.end();iter++)
		{
			printf(iter==b.begin()?"%d":" %d",*iter);
		}
		printf("\n");
	}
	return 0;
}
