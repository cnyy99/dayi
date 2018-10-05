#include<stdio.h>
int main()
{
	int i,j,k,m,n;
	printf("Please input the number of lines:");
	scanf("%d",&m);
	if(m%2!=0)
{
	for(i=1;i<=(m+1)/2;i++)
	{	
		for(j=1;j<=(m+1)/2-i;j++)	
			printf(" ");
		for(j=1;j<=2*i-1;j++)
			printf("*");
		printf("\n");
	}
	for(i=(m+1)/2-1;i>0;i--)
	{
		for(j=1;j<=(m+1)/2-i;j++)	
			printf(" ");
		for(j=1;j<=2*i-1;j++)
			printf("*");
		printf("\n");
	}
}
	else
{
	for(i=1;i<=m/2;i++)
	{	
		for(j=1;j<=m/2-i;j++)	
			printf(" ");
		for(j=1;j<=2*i-1;j++)
			printf("*");
		printf("\n");
	}
	for(i=m/2;i>0;i--)
	{
		for(j=1;j<=m/2-i;j++)	
			printf(" ");
		for(j=1;j<=2*i-1;j++)
			printf("*");
		printf("\n");
	}
}
	return 0;
}
