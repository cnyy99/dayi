#include<stdio.h>
int main(void)
{
	int n,i,j,sum;
	j=1;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			return 0;
		int a[n];
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i]; 
		}
		printf("%d\n",sum);
		if(j%2==0)
			printf("\n");
		j++;
	} 
	return 0; 
}
