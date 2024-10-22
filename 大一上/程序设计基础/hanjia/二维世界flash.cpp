#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#define N 10000+10
#define min(a,b) (a<b ? a:b)
using namespace std;

int n,m;
int vis[N];

typedef struct{
	int x;		// 存当前位置
	int step;	// 存当前移动次数
}Walk;

int bfs()
{
	Walk t,t1;
	queue<Walk> q;
	t.x = n;
	t.step = 0;
	q.push(t);
	
	while(!q.empty())
	{
		t = q.front();
		q.pop();
		
		if(t.x == m)	break;
		
		// 每次放入状态要判断是否遍历过
		if(0<=t.x-1 && vis[t.x-1]!=1)
		{
			vis[t.x-1] = 1;
			t1.x = t.x-1;
			t1.step = t.step+1;
			q.push(t1);
		}
		if(t.x+1<N && vis[t.x+1]!=1)
		{
			vis[t.x+1] = 1;
			t1.x = t.x+1;
			t1.step = t.step+1;
			q.push(t1);
		}
		if(t.x*2<N && vis[t.x*2]!=1)
		{
			vis[t.x*2] = 1;
			t1.x = t.x*2;
			t1.step = t.step+1;
			q.push(t1);
		}
	}
	return t.step;
}

int main()
{
	int i,j,k;
	while(scanf("%d %d",&n,&m) != EOF)
	{
		memset(vis,0,sizeof(vis));
		printf("%d\n",bfs());
	}
	return 0;
}
