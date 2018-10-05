#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
char gamemap[20][40];//?????? 20*40
int score=0;//????
//??????
int x[800];//????????
int y[800];//????????
int len = 0;//????
//??????
int fx=0;//??????d
int fy=0;//??????
int fcount=0;//?????
//??????
void createfood();//????
void PrintgameMap(int x[],int y[]);//?????
void move(int x[],int y[]);//???
int main()
{
	srand(time(NULL));
//???????????,????????2
	x[len] = 9;
	y[len] = 9;
	len++;
	x[len] = 9;
	y[len] = 8;
	len++;
	createfood();
	PrintgameMap(x,y);
	move(x,y);
	return 0;
}
void createfood()
{
	if(0==fcount)
{
	int tfx=rand()%18+1;
	int tfy=rand()%38+1;
	int i,j;	
	int have=0;//?0????????????
	for(i=0;i<len;i++)
{
	for(j=0;j<len;j++)
{
	if(x[i]==fx&&y[j]==fy)
{
	have=1;
	break;
}
else
{
have=0;
}
}
if(1==have)//???????,???????
{
continue;
}
else//????????
{
fcount++;
fx=tfx;
fy=tfy;
break;
}
}
}
}
//????
void PrintgameMap(int x[],int y[])
{
int snake = 0,food=0;
int i, j;
//?????,?????????
for (i = 0; i < 20; i++)
{
for (j = 0; j < 40; j++)
{
if (i == 0 && j >= 1 && j <= 38)
{
gamemap[i][j] = '=';
}
else if (i == 19 && j >= 1 && j <= 38)
{
gamemap[i][j] = '=';
}
else if (j == 0 || j == 39)
{
gamemap[i][j] = '#';
}
else
{
gamemap[i][j] = ' ';
}
//??????????
int k;
for ( k = 0; k < len; k++)
{
if (i == x[k]&&j == y[k])
{
snake = 1;
break;
}
else
{
snake = 0;
}
}
{
if(fcount&&fx==i&&fy==j)
{
food=1;
}
else
{
food=0;
}
}
//???????
if (1==snake )
{
printf("*");
}
else if(1==food)
{
printf("f");
}
//??????????????????
else
{
printf("%c", gamemap[i][j]);
}
}
printf("\n");
}
printf("score:%d",score);
}
//??
void move(int x[],int y[])
{
char s;
s=getch();
int move=0,beat=0;
while (1)
{
int cx[800];
int cy[800];
memcpy(cx, x, sizeof(int)*len);
memcpy(cy, y, sizeof(int)*len);
//?
if (s=='w')
{
x[0]--;
move=1;
if(x[0]<=0)
{
printf("Game over\n");
break;
}
}
else if (s=='s')
{
x[0]++;
move=1;
if(x[0]>=19)
{
printf("Game over\n");
break;
}
}
else if (s=='a')
{
y[0] --;
move=1;
if(y[0]<=0)
{
printf("Game over\n");
break;
}
}
else if (s=='d')
{
y[0]++;
move=1;
if(y[0]>=39)
{
printf("Game over\n");
break;
}
}
//??
int i;
for ( i = 1; i < len; i++)
{
x[i] = cx[i - 1];
y[i] = cy[i - 1];
}
for(i=1;i<len;i++)//???????
{
if(x[0]==x[i]&&y[0]==y[i])
{
beat=1;
}
else
{
beat=0;
}
}
if(1==beat)
{
printf("Game over\n");
break;
}
if(1==move)
{
if(fcount&&x[0]==fx&&y[0]==fy)//???????
{
//??????????????
memcpy(x+1,cx,sizeof(int)*len);
memcpy(y+1,cy,sizeof(int)*len);
len++;
fcount--;
fx=0;
fy=0;
score++;
createfood();
}
Sleep(70);
system("cls");
PrintgameMap( x, y);
}
else
continue;
if(kbhit())//????????
{
s=getch();
}
}
}
