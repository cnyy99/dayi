#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
struct student{
	char name[21];
	int s;
	int b[11];
	int summ;
};
struct score{
	int already=0;
	int sco;
};
bool cmp(struct student a,struct student b);
struct score scores[17];
struct student stu[1111];
int main()
{
	int i,j,k,n,m,g;
    while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			exit(0);	
		scanf("%d%d",&m,&g);
		k=0;
		for(i=1;i<m+1;i++)
			scanf("%d",&scores[i].sco);
		for(i=0;i<n;i++)
		{
			scanf("%s%d",stu[i].name,&stu[i].s);
			stu[i].summ=0;
			for(j=0;j<stu[i].s;j++)
			{
				scanf("%d",&stu[i].b[j]);
				if(scores[stu[i].b[j]].already==0)
				{
					stu[i].summ+=scores[stu[i].b[j]].sco;
					scores[stu[i].b[j]].already=7;
				}
			}
			if(stu[i].summ>=g)
				k++;
			for(j=0;j<m+1;j++)
			{
				scores[j].already=0;
			}
		}
		sort(stu,stu+n,cmp);
		printf("%d\n",k);
		for(i=0;i<k;i++)
		{
			printf("%s %d\n",stu[i].name,stu[i].summ);
		}
	}
	return 0;
}
bool cmp(struct student a,struct student b)
{ 
	return (a.summ>b.summ)||(a.summ==b.summ&&(strcmp(a.name,b.name)<0));
}



















