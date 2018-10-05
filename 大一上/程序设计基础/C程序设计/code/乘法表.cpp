#include<stdio.h>
int main()
{
	int m,n,i,j,k;
	scanf("%d",&m);
	for(n=1;n<=m;n++)
	{ 
		scanf("%d%d",&i,&k);
		if(i>0&&k>=i&&k<10)
		{	
			for(;i<=k;i++)
			{
				for(j=1;j<=i;j++)
				printf("%d*%d=%d\t",j,i,i*j);	
			if(i!=k)
				printf("\n");
			}
		if(n!=m)
			printf("\n\n");
		}
		else
			{
			printf("Input Error!");
			if(n!=m)
				printf("\n\n");
			}
	}
	return 0;
} 
