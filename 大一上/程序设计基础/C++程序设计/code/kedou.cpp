#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define maxm 110
char map[maxm][maxm];	
bool t[maxm][maxm];
int r,c,k;
int mx;
void dfs(char str,int line,int colum)
{
	if (line >= r||colum >= c||line < 0||colum < 0)
	{
		return;
	}
	if(str=='.'&&t[line][colum])
	{
		k++;
		t[line][colum]=false;
	}
	else
		return;
	mx = mx > k ? mx : k;
	dfs(map[line + 1][colum],line + 1,colum);
	dfs(map[line - 1][colum],line - 1,colum);
	dfs(map[line][colum + 1],line,colum + 1);
	dfs(map[line][colum - 1],line,colum - 1);
	t[line][colum] = true;
	k = 0;
	return;
}
int main()
{

	while(scanf("%d%d",&r,&c)!=EOF)
	{
		k=0,mx=0;
		memset(t,true,sizeof(t));
		void dfs(char str,int line,int colum);
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin>>map[i][j];
			}
			getchar();
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				dfs(map[i][j],i,j);
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}