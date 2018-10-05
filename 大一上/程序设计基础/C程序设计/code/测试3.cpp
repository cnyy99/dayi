#include<stdio.h>
#include <Windows.h>
#include <math.h>
#define Maxnum 1800
#define PI 3.1415926
int Nownum;
char *buff[Maxnum];
extern double __cdecl pow(_In_ double _X, _In_ double _Y);
int main()
{
void SetToNum(int SetNum);//300M 每格子 共9个格子

Nownum=0;
int SetNum;SetNum=0;
// while(1){
// //scanf("%d",&SetNum);
// 
// SetToNum(1800);
// printf("now:%d\n" ,Nownum);
// Sleep(1000);
// SetToNum(0);
// Sleep(1000);
// printf("now:%d\n" ,Nownum);
// }
int ix;ix=0;
DWORD startTime = 0; 
double x=-1.11;
double y=0;
startTime = GetTickCount(); //毫秒数


while(1)
{ 
if ( ((GetTickCount() - startTime)%1000) <= 100){//定时循环

//SetNum=(int)Maxnum/2*(1+sin(ix*2*PI/(50)*cos(ix*2*PI/(50))));//5s 一个小格，1s一个步进，5个小格一个pi,1O个小格一个正弦周期，=50ix

if (ix%2==1){
y=((pow(abs(x),2.0/3)+sqrt(pow(abs(x),4.0/3)-4*(x*x-1)))/2);// x^(2)^(1/3)/2+sqrt(x^(4)^(1/3)-4*(x^2-1))/2;//y+
}
else{
y=((pow(abs(x),2.0/3)-sqrt(pow(abs(x),4.0/3)-4*(x*x-1)))/2);// x^(2)^(1/3)/2-sqrt(x^(4)^(1/3)-4*(x^2-1))/2;//y-
}
//printf("y:%f(%f)\n" ,y,x);

SetNum=(int)Maxnum/2*(1+y/1.3);
SetToNum(SetNum);

x=x+0.1;ix++;
if (x>1.11){SetNum=0;SetToNum(SetNum);x=-1.11;printf("Pauseing:10s\n");Sleep(10000);}
printf("Nownum:%d(%f)\n" ,Nownum,x);
}
}




getchar();
for (int i;i<Maxnum;i++)
{
delete buff[i];
}

}


void SetToNum(int SetNum)
{
if (SetNum>Maxnum){printf("Error:SetNum>MaxNum!\n");return;}
if (Nownum<SetNum)
{
for (Nownum++;Nownum<=SetNum;Nownum++)
{
buff[Nownum]= new char[1024*1024];
}
Nownum--;
}
else if (Nownum>SetNum) 
{
for (;Nownum>SetNum;Nownum--)
{
delete buff[Nownum];
}
}
}


