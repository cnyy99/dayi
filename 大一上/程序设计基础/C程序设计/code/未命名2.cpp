#include<stdio.h>
int main()
{
	int i,j,k,m,N;
	printf("请输入班级人数：");
	scanf("%d",&N);
	int scores[N-1];
	for(i=0;i<N;i++)
		scanf("%d",&scores[i]);
		printf("学生的成绩为：");
	for(i=0;i<N;i++)
		printf("%d\t",scores[i]);
	printf("\n");
	for(j=0;j<N;j++)
	{
		for(i=0;i<N-j;i++)
			if(scores[i]>scores[i+1])
				{
				k=scores[i];
				scores[i]=scores[i+1];
				scores[i+1]=k;
				}
	}
	printf("学生的成绩从小到大排序为："); 
	for(i=0;i<N;i++)
		printf("%d\t",scores[i]);
	return 0;
} 
