#include <stdio.h>
#include <string.h>
int main()
{
	char word[100];
	scanf("%s",word);   // scanf_s 需要三个参数，第三个参数是缓冲区长度
	int len = strlen(word);
	for(int i = 1;i<=len;i++)
		if(len % i == 0)
		{
			int ok = 1;
			for(int j=i;j<len;j++)
				if(word[j] != word[j%i])
				{
					ok = 0;
					break;
				}
			if(ok) 
			{
				printf("%d\n",i);
				break;
			}
		}
	return 0;
}