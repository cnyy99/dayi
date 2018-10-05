#include <stdio.h>
#include <string.h>
const int maxn = 3000;
int f[maxn];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	f[0] = 1;
	for(i=2;i<=n;i++)  //乘以i
	{
		int c = 0;    //上一次剩余部分的数
		for(j=0;j<maxn;j++)
		{
			int s = f[j]*i+c;
			f[j] = s%10;
			c = s/10;
		}
	}
	for(i=maxn-1;i>=0;i--) if(f[i]) break;  //忽略前导0
	for(j=i;j>=0;j--) printf("%d",f[j]);
	printf("\n");
	return 0;
}