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
int a[N];
int n,m;
struct walk{
	int pos;
	int step;
};
using namespace std;
int bfs(void)
{
	struct walk t,tf;
	queue<walk>q;
	t.pos=n;
	t.step=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.pos==m)
			break;
		if(t.pos-1>=0&&a[t.pos-1])
		{
			tf.pos=t.pos-1;
			tf.step=t.step+1;
			q.push(tf);
			a[t.pos-1]=0;
		}
		if(t.pos+1<=N&&a[t.pos+1])
		{
			tf.pos=t.pos+1;
			tf.step=t.step+1;
			q.push(tf);
			a[t.pos+1]=0;
		}
		if(t.pos*2<=N&&a[t.pos*2])
		{
			tf.pos=t.pos*2;
			tf.step=t.step+1;
			q.push(tf);
			a[t.pos*2]=0;
		}
	}
	return t.step;
}
int main()
{
	int i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(a,1,sizeof(a));
		printf("%d\n",bfs());
	}
	return 0;
}
