#include<stdio.h>
struct children{
	int number;
	int a;
};
struct children stu[300];
struct children mmm;
int n,m;
int i=0;
void clear();
void home();
void caluate();
int main()
{
	int j,t,k;
	while(scanf("%d%d",&t,&k)!=EOF)
	{

		n=t;
		m=k;
		for(j=0;j<n;j++)
		{
			stu[j].number=j+1;
			scanf("%d",&stu[j].a);
		}
		caluate();
		printf("%d\n",stu[0].number);
	}
	return 0;
}
void caluate()
{
	int temp;
	stu[0].a=stu[0].a-m;
	temp=stu[0].a;
	if(temp<=0)
		home();
	else if(temp>0)
		clear();
	if(n==i)
		return;
	else
		caluate();
}
void clear()
{
	int i;
	mmm=stu[0];
	for(i=0;i<n-1;i++)
	{
		stu[i]=stu[i+1];
	}
	stu[n-1]=mmm;
	return;
}
void home()
{
	int i;
	for(i=0;i<n-1;i++)
	{
		stu[i]=stu[i+1];
	}
	n--;
	return ;
}











