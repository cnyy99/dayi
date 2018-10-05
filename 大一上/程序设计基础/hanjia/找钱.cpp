/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
int k;
int kl;
int main()
{
	int t,i,j,f,n;
	scanf("%d",&t);
	while(t--)
	{
		f=0;
		kl=0;
		scanf("%d",&n);
		if(n>=50)
		{
			f=n/50;
			n=n-f*50;
		}
		if(n>=20)
		{
			kl=n/20;
			f+=kl;
			n-=kl*20;
		}
		if(n>=5)
		{
			kl=n/5;
			f+=kl;
			n-=kl*5;
		}
		if(n>=1)
		{
			kl=n/1;
			f+=kl;
			n-=kl*1;
		}
		kl=n;
		printf("%d\n",f);
	}
	return 0; 
}*/
#include<stdio.h> 
#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <string>  
#include <queue>  
#include <stack>  
#include <map>  
#include <math.h>  
#include <vector>  
#include <stdlib.h>  
#include <algorithm>  
using namespace std;  
void greedyMoney(int m[],int k,int n); 
int h;
int main(void) 
{ 
	int money[110];
	int k,t,n,m,i,p; 
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&money[i]);
//		k = sizeof(money)/sizeof(money[0]); 
		k=n;
		sort(money,money+k);		
		h=0;	
		greedyMoney(money,k,m); 
	}

 
} 

void greedyMoney(int m[],int k,int n) 
{ 
	int i; 
	for(i=0;i<k;i++) 
	{ 
		if(n>=m[i] && n>0) 
		{ 
			h++;
			n = n-m[i]; 
		} 
	} 
	printf("%d\n",h); 

}

