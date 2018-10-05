#include<stdio.h>

int main()
{
	int n,k;
	while(scanf("%d",&n)==1)
	{
		k=1;
		while(k<n)  //µÚkÐÐ
		{
			n -= k;
			k++;
		}
		if(k % 2 == 0)
			printf("%d/%d\n",n,k+1-n);
		else
			printf("%d/%d\n",k+1-n,n);
	}
  
	return 0;
}