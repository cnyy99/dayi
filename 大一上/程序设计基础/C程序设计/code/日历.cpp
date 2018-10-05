#include<stdio.h>
int main()
{
	int i,j,k,m;
	i=1;
	printf("Enter number of days in month:");
	scanf("%d",&j);
	printf("Enter starting day of thr week:");
	scanf("%d",&k);
	switch(k)
	{
		case 1:printf("\t%d\t",i),m=2;break;
		case 2:printf("\t\t%d\t",i),m=3;break;
		case 3:printf("\t\t\t%d\t",i),m=4;break;
		case 4:printf("\t\t\t\t%d\t",i),m=5;break;
		case 5:printf("\t\t\t\t\t%d\t",i),m=6;break;
		case 6:printf("\t\t\t\t\t\t%d\n",i),m=7;break;
		case 7:printf("%d\t",i),m=1;break;
		default:printf("Worng\n");break;
	}
	for(i=2;i<=j;i++,m++)
	{
		if((m+1)%7!=0)
			printf("%d\t",i);
		else
			printf("%d\n",i);
	}
	return 0;
}
