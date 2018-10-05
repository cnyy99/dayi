/*#include<stdio.h>
int main(void)
{
	int sum;
	scanf("%d",&sum);
	printf("%d\n",sum/10);
	return 0;
 } */
/*#include<stdio.h>
int main()
{
	long long k,i,j;
	k=1;
	scanf("%lld",&i);
	if(i==0)
		printf("%lld\n",k);
	else
	{
			for(j=0;j<i;j++)
      		k*=2;
	printf("%lld\n",k);
}
	return 0;
}*/
/*#include<stdio.h>
int main(void)
{
	int i,j,k,n;
	while(scanf("%d",&n)!=EOF){
	int a[n];
	k=1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(a[i]==a[j])
			{
				k=0;
			}
		}
	}

	}
	return 0;
}*/
#include<stdio.h> 
#include<math.h>
int main(void)
{
	long a,b,i,sum;
//	long cheng(int n,int m);
	while(scanf("%d%d",&a,&b)!=EOF){
		sum=0;
		for(i=1;i<=a;i++)
		{
			sum+=pow(i,b);
		}
		printf("%d\n",sum%a);
	}
}
/*long cheng(int n,int m)
{
	int i;
	long ji=1;
	for(i=1;i<=m;i++)
	{
		ji*=n;
	}
	return ji;
}*/



























