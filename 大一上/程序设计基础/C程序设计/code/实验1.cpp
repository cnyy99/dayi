#include<stdio.h>
int main()
{
	double a,b,c;
	printf("请输入三个数：") ;
	scanf("%lf%lf%lf",&a,&b,&c); 
	if(a<=0||b<=0||c<=0)
		printf("三角形的边长必须大于0\n"); 
	else 
		if((a==b&&a+b>c)||(a==c&&a+c>b)||(b==c&&b+c>a))
			printf("是等腰三角形\n");
		else
			printf("不是等腰三角形\n");
	return 0;
}
