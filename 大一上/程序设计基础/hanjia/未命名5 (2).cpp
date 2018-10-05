#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
int k;
int kl;
int sum(int n);
int main()
{
	int t,i,j,k,n;
	scanf("%d",&t);
	while(t--)
	{
		k=0;
		scanf("%d",&n);
		k=sum(n);
		printf("%d\n",k);
	}
	return 0; 
}
int sum(int n)
{
	int i,mm;
	if(n<=0)
	{
		
		return k;
	}
	if(n>=50)
	{
		k+=n%50;
		kl=n-50*(n%50);
		sum(kl);
	}
	if(n>20)
	{
		k+=n%20;
		kl=n-5*(n%20);
		sum(kl);
	}
	if(n>=5)
	{
		k+=n%5;
		kl=n-5*(n%5);
		sum(kl);
	}
	if(n>=1)
	{
		k+=n%1;
		kl=n-1*(n%1);
		sum(kl);
	}	
}
