#include <cstdio>
#define MAXM 210
//const int MAXM = 200 + 10;
int m,n;
int num[MAXM][MAXM] = {0};
int ans[MAXM*MAXM];
int tempo = 0;

void init()
{
    scanf("%d%d",&m,&n);
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
}

void solve(int beginrow, int beginline, int row, int line)
{
    int i, j;
    if (row == 0 || line == 0) return;
    if (row == 1)
    {
        for (i = 0; i < line; i++)
        {
            ans[tempo] = num[beginrow][beginline];
            beginline++;
            tempo++;
        }
        return;
    }
    if (line == 1)
    {
        for (i = 0; i < row; i++)
        {
            ans[tempo] = num[beginrow][beginline];
            beginrow++;
            tempo++;
        }
        return;
    }
    int v = beginrow, h = beginline;
    ans[tempo] = num[beginrow][beginline];
    tempo++;
    for (i = 0; i < row-1; i++)
    {
        v++;
        ans[tempo] = num[v][h];
        tempo++;
    }
    for (i = 0; i < line-1; i++)
    {
        h++;
        ans[tempo] = num[v][h];
        tempo++;
    }
    for (i = 0; i < row-1; i++)
    {
        v--;
        ans[tempo] = num[v][h];
        tempo++;
    }
    for (i = 0; i < line-2; i++)
    {
        h--;
        ans[tempo] = num[v][h];
        tempo++;
    }
    solve(v+1,h,row-2,line-2);
}

void output()
{
    int cnt = n*m;
    if (cnt == 0) return;
    printf("%d",ans[0]);
    for (int i = 1; i < cnt; i++)
    {
        printf(" %d",ans[i]);
    }
    printf("\n");
}

int main()
{
    init();
    int begin1 = m, begin2 = n;
    solve(0,0,begin1, begin2);
    output();
    return 0;
}
