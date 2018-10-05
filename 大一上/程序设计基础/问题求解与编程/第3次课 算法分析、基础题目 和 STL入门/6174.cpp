#include <stdio.h>
#include <string.h>

int get_next(int x)
{
	int a,b,n;
	char s[10];         //假设x不超过9位
	sprintf(s,"%d",x);  //x转换为字符串
	n = strlen(s);
	//冒泡排序
	for(int i=0;i<n-1;i++)     
		for(int j=i+1;j<n;j++)
			if(s[i]>s[j])
			{
				char t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
	sscanf(s,"%d",&b);
	//字符串反转
	for(i=0;i<n/2;i++)   
	{
		char t = s[i];
		s[i] = s[n-1-i];
		s[n-1-i] = t;
	}
	sscanf(s,"%d",&a);
	return a-b;
}

int num[1010], count;

int main()
{
	scanf("%d", &num[0]);
	printf("%d", num[0]);
	count = 1;
	for(;;)
	{
		num[count] = get_next(num[count-1]);  //生成下一个数
		printf(" -> %d", num[count]);  //输出下一个数
		//在数组中寻找新生成的数
		int found = 0;
		for(int i=0;i<count;i++)
			if(num[i]==num[count])
			{
				found = 1;
				break;
			}
		//如果找到，退出循环
		if(found) break;
		count++;
	}
	printf("\n");	
	return 0;
}