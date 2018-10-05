#include<stdio.h>
#include<math.h>
int main(void)
{
	int i,j=0;
	int a[10];
	int i1,i2,i3,n,m;
		for(i=100;i<=999;i++)
		{
			i1=i/100;i2=(i-100*i1)/10;i3=(i-100*i1-10*i2);
			if(pow(i1,3)+pow(i2,3)+pow(i3,3)==i)
			{
				a[j]=i;
				j++;
			}
		}
		if(j==0)
			printf("...\n");
		else
			for(i=0;i<j;i++)
				printf("%d\n",a[i]);
	
	return 0;
}
