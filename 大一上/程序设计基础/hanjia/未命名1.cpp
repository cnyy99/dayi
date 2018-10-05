#include<stdio.h>
struct user{
	char name[13];
	int n;
	float a;
};
int main()
{
	int t,T,n;
	int i,j,k;
	user stu[103];
	user temp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s%d%f",stu[i].name,&stu[i].n,&stu[i].a);
		}
		for(j=0;j<n-1;j++)
			for(i=0;i<n-1-j;i++)
			{
				if(stu[i].n<stu[i+1].n||(stu[i].n==stu[i+1].n&&stu[i].a<stu[i+1].a))
				{
					temp=stu[i];
					stu[i]=stu[i+1];
					stu[i+1]=temp;
				}
			}
		for(i=0;i<n;i++)
		{
			printf("%s %d %.2f\n",stu[i].name,stu[i].n,stu[i].a);
		}
	}
	return 0;
}
