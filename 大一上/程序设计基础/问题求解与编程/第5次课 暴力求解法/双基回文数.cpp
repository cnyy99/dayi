#include <stdio.h>   
//判断回文数函数
bool isPal(int num, int radix)
{
	int temp = num;
	int pal = 0;
	while(num!=0)
	{
		pal *= radix;
		pal += num%radix;	
		num /= radix;
	}
	return temp == pal;
}

int main()  
{  
	int n, count, flag;
	while(scanf("%d",&n)==1)
	{
		for(;;n++)
		{
			count = 0;
			flag = 0;
			for(int i=2;i<=10;i++)
			{
				if(isPal(n,i)) 
					count++;
				if(count>=2)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
			{
				printf("%d\n", n);
				break;
			}
		}
	}
    return 0;  
}  
