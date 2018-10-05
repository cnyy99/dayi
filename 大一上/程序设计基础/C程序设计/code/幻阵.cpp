#include<stdio.h>
#define N 16
int main()
{
	int a[N];
	int i;
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=0;i<N;i++)
	{
		if((i+1)%4!=0)
			printf("%-d\t",a[i]);
		else
			printf("%-d\n",a[i]);
	}
	printf("各行的和：%d   %d   %d   %d\n",a[1]+a[2]+a[3]+a[0],a[5]+a[6]+a[7]+a[4],a[9]+a[10]+a[11]+a[8],a[13]+a[14]+a[15]+a[12]);
	printf("各列的和：%d   %d   %d   %d\n",a[0]+a[4]+a[8]+a[12],a[1]+a[5]+a[9]+a[13],a[2]+a[6]+a[10]+a[14],a[3]+a[7]+a[11]+a[15]);
	printf("对角线的和：%d   %d\n",a[0]+a[5]+a[10]+a[14],a[3]+a[6]+a[9]+a[12]);
	return 0; 
}
