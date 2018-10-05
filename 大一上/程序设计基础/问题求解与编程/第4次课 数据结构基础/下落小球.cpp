#include<stdio.h>
#include<string.h>
const int MAXD = 20;
int s[1<<MAXD];  //最大节点个数 2^MAXD - 1

int main()
{
	int D, I;	
	while(scanf("%d%d", &D, &I) == 2)
	{
		memset(s,0,sizeof(s));  //开关初始全0，表示关闭
		int k, n = (1<<D)-1;    //k表示下落到的节点的开关下标
		for(int i=0;i<I;i++)    //共下落I个小球
		{
			k = 1;
			while(1)
			{
				s[k] = !s[k];
				k = s[k] ? 2*k : 2*k+1;  //根据开关选择左右子树
				if(k > n) break;  //落到树外，出界
			}
		}
		printf("%d\n", k/2); //出界前叶子节点编号
	}

	return 0;
}