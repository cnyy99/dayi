#include<stdio.h>
int main()
{
	unsigned long long t,a,b,c,i;
	scanf("%lld",&t);
	for(i=1;i<t+1;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a+b==c)
			printf("Case %lld: Happy!\n",i);
		else
			printf("Case %lld: Kill!\n",i);	
	}
	return 0;
}
