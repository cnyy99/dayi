#include <stdio.h>
#include <string.h>
const int MAXN = 50;

// 长度为n     s1 前序     s2 中序   构造后序s3
void build(int n, char * s1, char * s2, char * s3)
{
	if(n<=0) return;
	int p = strchr(s2, s1[0]) - s2;  //找到根节点在中序遍历中的位置
	build(p, s1+1, s2, s3);          //递归左子树的后序遍历
	build(n-p-1, s1+p+1, s2+p+1, s3+p);  //递归右子树的后序遍历
	s3[n-1] = s1[0];   //把根节点添加到最后
}

int main()
{
	char s1[MAXN], s2[MAXN], s3[MAXN];
	while(scanf("%s%s",s1,s2) == 2)
	{
		int n = strlen(s1);
		build(n,s1,s2,s3);
		s3[n] = '\0';
		printf("%s\n", s3);

	}
	return 0;
}