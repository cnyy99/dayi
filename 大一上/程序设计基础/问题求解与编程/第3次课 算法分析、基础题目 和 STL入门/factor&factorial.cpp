#include<stdio.h>
#include<string.h>

//素数判定，n不能太大
int is_prime(int n)
{
	for(int i = 2;i*i<=n;i++)
		if(n%i==0) return 0;
	return 1;
}

int prime[100], count=0; //素数表

int main()
{
	int n, p[100]; //n和各个素数的指数
	
	for(int i=2;i<=100;i++) 
	{

		if(is_prime(i)) prime[count++] = i;
	} //构造素数表

	while(scanf("%d",&n)==1)
	{
		memset(p,0,sizeof(p));
		int maxp = 0;
		for(int i=2;i<=n;i++)
		{
			int m = i;  //不能直接用i，因为m会变化
			for(int j=0;j<count;j++)
				while(m % prime[j]==0)  //反复除以prime[j]，并累加p[j]
				{
					p[j]++;
					m /= prime[j];
					if(j>maxp)              //更新最大因子下标
						maxp = j;
				}
		}
		printf("%d! = ", n);
		//只循环到最大因子的下标处
		for(int i=0;i<=maxp;i++)
			printf("%d ", p[i]);
		printf("\n");
	}
  
	return 0;
}