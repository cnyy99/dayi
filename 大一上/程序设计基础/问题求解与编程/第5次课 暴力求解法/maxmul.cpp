#include<stdio.h>
#include<string.h>

const int MAXN = 18;
int num[MAXN];

__int64 maxmul(int * array, int length)
{
	int i,j;
	__int64 temp, max = -1;
	//枚举求出所有可能的乘积
	for(i=0;i<length;i++)
	{
		temp = array[i];
		if(temp>max)
			max = temp;
		for(j=i+1;j<length;j++)
		{
			temp *= array[j];
			if(temp>max)
				max = temp;
		}
	}
	return max;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
			scanf("%d", &num[i]);
		printf("%I64d\n",maxmul(num, n));
	}
	return 0;
}
