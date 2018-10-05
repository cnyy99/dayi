#include<stdio.h>
struct children{
	int number;
	int a;
};
struct children stu[500];
int n,m;
int i;
void caluate();
int main()
{
	int j,t,k;
	while(scanf("%d%d",&t,&k)!=EOF)
	{
		i=0;
		n=t;
		m=k;
		for(j=0;j<n;j++)
		{
			stu[j].number=j+1;
			scanf("%d",&stu[j].a);
		}
		caluate();
		printf("%d\n",stu[i-1].number);
	}
	return 0;
}
void caluate()
{
	int temp;
	stu[i].a=stu[i].a-m;
	temp=stu[i].a;
	if(temp<=0)
		i++;
	else if(temp>0)
		{
			stu[n]=stu[i];
			i++;
			n++;
		}
	if(n==i)
		return;
	else
		caluate();
}












