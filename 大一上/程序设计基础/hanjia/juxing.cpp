#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#define N 10000+10
#define min(a,b) ((a)<(b) ? (a):(b))
#define max(a,b) ((a)>(b) ? (a):(b))
struct juxing{
	double x1;
	double y1;
	double x2;
	double y2;
};
int main()
{
	double minx,miny,maxx,maxy,minx1,minx2,miny1,miny2,maxx1,maxx2,maxy1,maxy2;
	juxing a,b;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x1,&a.y1,&a.x2,&a.y2,&b.x1,&b.y1,&b.x2,&b.y2)!=EOF)
	{
	minx1=min(a.x1,a.x2);
	minx2=min(b.x1,b.x2);
	maxy1=max(a.y1,a.y2);
	maxy2=max(b.y1,b.y2);
	maxx1=max(a.x1,a.x2);
	maxx2=max(b.x1,b.x2);
	miny1=min(a.y1,a.y2);
	miny2=min(b.y1,b.y2);
	minx=max(minx1,minx2);  
    miny=max(miny1,miny2); 
    maxx=min(maxx1,maxx2);
    maxy=min(maxy1,maxy2);
	if(minx>maxx||miny>maxy)
		printf("0.00\n");
	else
		printf("%.2lf\n", (maxx-minx)*(maxy-miny));
	}
	return 0; 
}
