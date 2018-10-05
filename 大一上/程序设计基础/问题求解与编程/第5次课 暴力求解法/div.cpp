#include<stdio.h>
#include<string.h>

bool bits[10]; //分别代表0~9这10个数字是否被用过
//choose = 1时判断是否用了5位，choose = 2时判断是否用了10位，num用来接收除数和被除数
bool check(int num, int choose) 
{
	if(choose == 1)
		memset(bits,0,sizeof(bits));
	int i,j,k,l,m;
	i = num/10000;
	j = num/1000%10;
	k = num/100%10;
	l = num/10%10;
	m = num%10;
	bits[i] = bits[j] = bits[k] = bits[l] = bits[m] = 1;
	int count = 0;
	for(int x=0;x<=9;x++)
		if(bits[x])
			count++;
	if(choose==1 && count<5 || choose==2 && count<10)
		return false;
	return true;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int b=1234;b<=98765;b++)
			if(check(b,1) && b*n>10000 && b*n<99999 && check(b*n,2))
				printf("%d/%d = %d\n",b*n,b,n);
	}
	return 0;
}
