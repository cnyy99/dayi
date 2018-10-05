#include<stdio.h>
const int MAXN = 1000;
int n, left[MAXN], right[MAXN];

void link(int X, int Y)
{
	right[X] = Y;
	left[Y] = X;
}

int main()
{
	int m, X, Y;
	char command[10];
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
	{
		left[i] = i-1;
		right[i] = i+1;
	}
	for(i=0;i<m;i++)
	{
		scanf("%s%d%d", command, &X, &Y);
		link(left[X], right[X]);
		if(command[0]=='A')
		{
			link(left[Y],X);
			link(X,Y);
		}
		else
		{
			link(X, right[Y]);
			link(Y, X);
		}
	}
	for(i=right[0];i!=n+1;i=right[i])
		printf("%d ",i);
	printf("\n");
	return 0;
}