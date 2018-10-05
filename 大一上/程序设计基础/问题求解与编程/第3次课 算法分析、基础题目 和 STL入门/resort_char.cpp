#include <stdio.h>
#include <stdlib.h>   //qsort()函数，使用qsort函数必须自己写一个比较函数
#include <string.h>

//字符比较函数，使用qsort标准写法
int cmp_char(const void * _a, const void * _b)  
{
	char * a = (char *)_a;
	char * b = (char *)_b;
	return *a - *b;
}

//字符串比较函数
int cmp_string(const void * _a, const void * _b)
{
	char * a = (char *)_a;
	char * b = (char *)_b;
	return strcmp(a,b);
}

char word[1000][10], sorted[1000][10];

int main()
{
	int n=0;

	for(;;)
	{
		scanf("%s",word[n]); // scanf_s("%s", word[n], 10);
		if(word[n][0]=='*') break; //遇到结束标志终止循环
		n++;
	}

	qsort(word, n, sizeof(word[0]), cmp_string);  //给字典中的所有单词排序

	for(int i=0;i<n;i++)
	{
		strcpy(sorted[i], word[i]);
		qsort(sorted[i], strlen(sorted[i]), sizeof(char), cmp_char); //把字典备份中的每个单词字母重排
	}

	char s[10];
	while(scanf("%s", s)==1)  // scanf_s("%s", s, 10) == 1
	{
		qsort(s, strlen(s), sizeof(char), cmp_char); //把输入单词字母重排
		int found = 0;
		for(i=0;i<n;i++)
		{
			if(strcmp(sorted[i],s)==0)
			{
				found = 1;
				printf("%s ", word[i]);  //输出原始单词
			}
		}
		if(!found) printf("-1");
		printf("\n");
	}
	return 0;
}