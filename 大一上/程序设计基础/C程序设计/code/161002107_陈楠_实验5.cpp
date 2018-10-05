#include<stdio.h>
#define pi 3.1415926
int main(void)
{
	float area,volume,k;
	int t;
	void sphere(float *area,float *volume);
	void cube(float *area,float *volume);
	void cylinder(float *area,float *volume);
	for(;;){
		do{
		printf(	"Please input the request object shapes:  \n"
				"1 stands for sphere.                     \n"
				"2 stands for cube.                       \n"
				"3 stands for cylinder.                   \n"
				"4 quit.                                  \n"	);
		scanf("%f",&k);
		if(k==4)
			return 0;
		}while(k!=1&&k!=2&&k!=3);
	t=(int)k;
	switch(t)
		{
			case 1:sphere(&area,&volume);break; 
			case 2:cube(&area,&volume);break;
			case 3:cylinder(&area,&volume);break;
		}
			printf("The surface area of this object is %.2f£¬volume is %.2f.\n\n",area,volume);
	}
	return 0;
}
void sphere(float *area,float *volume)
{
	float r;
	printf("Please input the radius of the sphere:");
	scanf("%f",&r);
	*area=4*pi*r*r;
	*volume=4.0/3*pi*r*r*r;
}
void cube(float *area,float *volume)
{
	float a;
	printf("Please input the length of side of the cube:");
	scanf("%f",&a);
	*area=6*a*a;
	*volume=a*a*a;
}
void cylinder(float *area,float *volume)
{
	float r,h;
	printf("Please input the radius of zhe cylinder base and high:");
	scanf("%f%f",&r,&h);
	*area=2*pi*r*r+2*pi*r*h;
	*volume=pi*r*r*h;
}











