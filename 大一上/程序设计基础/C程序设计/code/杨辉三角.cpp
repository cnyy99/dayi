#include <stdio.h>

/*int c(int x,int y)        //求杨辉三角形的第x行第y列的值
 {
  int z;
  if((y==1)||(y==x+1))    //若为x行的第1或第x+1列，刚输出1
  return (1);
  else 
  	z=c(x-1,y-1)+c(x-1,y);//否则，其值为前一行中第y-1列与第y列值之和
  return (z);
 }

int main()
{
 	int i,j,n=100;
	printf("N=");
	while(n>12)
	scanf("%d",&n);    //控制输入正确的值以保证屏幕显示的图形正确
	for(i=0;i<=n;i++)    //控制输出N行
	{
   		for(j=0;j<12-i;j++)    //控制输出第i行前面的空格
		   	printf(" ");
		for(j=1;j<i+2;j++)    //输出第i行的第j个值
			printf("%6d",c(i,j));
		  printf("\n");
	}
}*/

int main() 
{ 
     int i,j,x,y,n=0,a[20]={0,1}; 
     while(n<1 || n>19) 
     { 
       scanf("%d",&n); 
     } 
     for(i=1;i<=n;i++) 
    { 
       x=0; 
       for(j=1;j<=i;j++) 
       { 
         y=a[j]; 
         a[j]=x+y; 
         x=y; 
         printf("%5d",a[j]); 
       } 
       printf("\n"); 
    } 
}
