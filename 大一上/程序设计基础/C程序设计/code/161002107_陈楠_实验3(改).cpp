#include<stdio.h>
#define N 200 
int main()
{
	int i,j,k,n;
	printf("请输入班级人数：");
	scanf("%d",&n);
	printf("请输入每个人的成绩："); 
	int scores[N];
	for(i=0;i<n;i++)
		scanf("%d",&scores[i]);
	printf("学生的成绩为:            ");
	for(i=0;i<n;i++)
		printf("%d\t",scores[i]);
	printf("\n");
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-1-j;i++)
			if(scores[i]>scores[i+1])
				{
				k=scores[i];
				scores[i]=scores[i+1];
				scores[i+1]=k;
				}
	}
	printf("学生的成绩从小到大排序为："); 
	for(i=0;i<n;i++)
		printf("%d\t",scores[i]);
	return 0;
} 
