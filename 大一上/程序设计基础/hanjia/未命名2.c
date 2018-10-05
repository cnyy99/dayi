#include<stdio.h>
#include<math.h>
int main()
{
	int i,n,m;
	int a[110];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=ceil(a[i]/(1.0*m));
		}
		int pos=0,t=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]>t)
			{
				pos=i;
				t=a[i];
			}
		}
		printf("%d\n",pos+1);
	}
	return 0;
}











