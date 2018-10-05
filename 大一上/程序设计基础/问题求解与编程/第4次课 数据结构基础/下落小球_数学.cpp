#include<stdio.h>

int main()
{
	int D, I;	
	while(scanf("%d%d", &D, &I) == 2)
	{
		int k = 1;
		for(int i=0; i<D-1; i++)
			if(I%2)                  //ÆæÊý
			{
				k = 2*k;
				I = (I+1)/2;
			}else{
				k = 2*k + 1;
				I = I/2;
			}
		printf("%d\n", k);
	}

	return 0;
}