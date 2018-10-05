#include<stdio.h>
#include<string.h>
#include<stdbool.h> 
//#define N 10
int N;
int main(void)
{
	int t,i,j;
	printf("Please input a natural number:");
	void gets(int *p);
	void gets_number(int n,int *p);
	void puts_number(int n,int *p);
	void rule_number(int m,int *p);
	gets(&N);
	int number[N]; 
	gets_number(N,number);
	rule_number(N,number);
	puts_number(N,number);
	return 0; 
}
void gets(int *p)
{
	scanf("%d",p);
}
void gets_number(int n,int *p)
{
	int i;
	for(i=0;i<N;i++)
		scanf("%d",p++);
}
void rule_number(int n,int *p)
{
	int t,*q;
	q=p;
	for(int j=0;j<N-1;j++)
	{
		p=q;
		for(int i=0;i<N-j-1;i++,p++)
		{
			if(*p>*(p+1))
			{ 
				t=*p;
				*p=*(p+1);
				*(p+1)=t;
			}		
		}
	}
}
void puts_number(int n,int *p)
{
	int i;
	for(i=0;i<N;i++)
		printf("%d\t",*p++);
}
