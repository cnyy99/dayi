#include <stdio.h>
#include <string.h>
const int MAXN = 1000;
int n, m, Relation[MAXN][MAXN]; //n个变量,m条关系,数组Relation存放关系
int c[MAXN]; //取0时表示结点还未被遍历过；取1时表示已扩展完毕；取-1表示正在被扩展
int topo[MAXN], t; //数组topo存放最后得到的序列；t是访问序列的指针

bool dfs(int u)
{
	c[u] = -1;
	for(int v=0;v<n;v++)
		if(Relation[u][v])
		{
			if(c[v]<0) return false; //存在有向环，失败退出
			else if(!c[v] && !dfs(v)) return false; //如果v还没被扩展，扩展v
		}
	c[u] = 1; //u已被深度优先扩展完毕
	topo[--t] = u; //把u添加到队列
	return true;
}

bool toposort()
{
	t = n;
	memset(c, 0 ,sizeof(c));
	for(int u = 0;u<n;u++)
		if(!c[u]) //依次深度优先扩展结点，如果u还没被扩展过，那么扩展它
			if(!dfs(u)) return false;  //无合理顺序
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(Relation,0,sizeof(Relation));
	int u, v;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d", &u, &v);
		Relation[u][v] = 1;
	}
	if(toposort())
		for(int i=0; i<n; i++)
			printf("%d\n", topo[i]);
	else
		printf("no path\n");

	return 0;
}