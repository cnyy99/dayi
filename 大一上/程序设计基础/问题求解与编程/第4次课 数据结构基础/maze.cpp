#include <stdio.h>
#include <string.h>
const int MAXN = 100;
int n, m, xs, ys, xt, yt; //n*m的矩阵，(xs,ys)为起点,(xt,yt)为终点

//下面的二维数组分别表示矩阵，结点是否被访问过，父结点，从父结点扩展来的方向以及距离起点的长度
int maze[MAXN][MAXN], vis[MAXN][MAXN], father[MAXN][MAXN], fa_dir[MAXN][MAXN], distance[MAXN][MAXN];

int dx[] = {-1,1,0,0}; //上下左右扩展时横坐标x的变化值
int dy[] = {0,0,-1,1}; //上下左右扩展时纵坐标y的变化值
char dir[] = {'U','D','L','R'};

int queue[MAXN*MAXN];  //表示队列
//从起点开始扩展
void bfs(int x, int y){
	// front和rear控制扩展的队列,rear用来往队列中添加结点,front用来取结点;
	//d表示上下左右方向;num表示结点的编号(取值从0到n*m)
	int front = 0, rear = 0, d, num; 
	num = x*m + y;
	vis[x][y] = 1;
	father[x][y] = num;
	distance[x][y] = 0;
	queue[rear++] = num; //把起点添加到队列中
	while(front<rear)  //front == rear时，扩展完毕，循环结束
	{
		num = queue[front++]; //取结点
		x = num/m;
		y = num%m;
		//上下左右四个方向扩展
		for(d = 0;d < 4; d++)
		{
			int nx = x+dx[d];
			int ny = y+dy[d];
			//如果(nx,ny)结点合法并且没被扩展过并且是可通的
			if(nx>=0 && nx<n && ny>=0 && ny<n && maze[nx][ny] && !vis[nx][ny])
			{
				int v = nx*m + ny;
				queue[rear++] = v; //往队列添加结点
				vis[nx][ny] = 1;
				father[nx][ny] = num;
				fa_dir[nx][ny] = d;
				distance[nx][ny] = distance[x][y] + 1;
			}
		}
	}
}

//从终点开始往回找路径,使用递归
void print_path(int x, int y)
{
	int fx = father[x][y]/m;
	int fy = father[x][y]%m;
	//没回到起点时
	if(fx != x || fy != y)
	{
		print_path(fx,fy);
		putchar(dir[fa_dir[x][y]]);
	}
}

//从终点开始往回找路径,使用循环
int path[MAXN*MAXN]; //记录路径
void print_path2(int x, int y)
{
	int n = 0; 
	for(;;)
	{
		int fx = father[x][y]/m;
		int fy = father[x][y]%m;
		//回到起点时
		if(fx == x && fy == y) break;
		path[n++] = fa_dir[x][y];
		x = fx;
		y = fy;
	}
	while(n--)
	{
		putchar(dir[path[n]]);
	}
}

int main()
{
	FILE * file;
	file = fopen("maze.in", "rb");
	fscanf(file,"%d%d%d%d%d%d", &n, &m, &xs, &ys, &xt, &yt);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			fscanf(file, "%d", &maze[i][j]);
	bfs(xs,ys);
	print_path(xt,yt);
	printf("\n");
	print_path2(xt,yt);
	printf("\n");
	printf("%d\n",distance[xt][yt]);
	fclose(file);
	return 0;
}

