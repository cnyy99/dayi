#include <stdio.h>
const int MAXN = 1000;
int n, ball[MAXN];

int find(int X)
{
	for(int i=1;i<=n;i++)
		if(ball[i]==X)
			return i;
	return 0;
}

void shift_circular_left(int n1, int n2)
{
	int temp = ball[n1];
	for(int i=n1;i<n2;i++)
		ball[i] = ball[i+1];
	ball[n2] = temp;
}

void shift_circular_right(int n1, int n2)
{
	int temp = ball[n2];
	for(int i=n2-1;i>=n1;i++)
		ball[i+1] = ball[i];
	ball[n1] = temp;
}


int main()
{
	int m, X, Y, p1, p2;
	char command[10];
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		ball[i] = i;
	for(i=0;i<m;i++)
	{
		scanf("%s%d%d", command, &X, &Y);
		p1 = find(X);
		p2 = find(Y);
		if(command[0] == 'A')
			if(p1<p2)
				shift_circular_left(p1,p2-1);
			else
				shift_circular_right(p2,p1);
		else
			if(p1<p2)
				shift_circular_left(p1,p2);
			else
				shift_circular_right(p2+1,p1);
	}	
	for(i=1;i<=n;i++)
		printf("%d ", ball[i]);
	printf("\n");
	return 0;
}