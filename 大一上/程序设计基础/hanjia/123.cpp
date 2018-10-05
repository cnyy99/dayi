#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<map>
#include<algorithm>
#include <vector>
using namespace std;
static void getPrime(int n, vector<int> &primes);
bool isPrime(int n);
int main()
{
	int i,j,k,n,m;
	vector<int>color;
	vector<int>::iterator iter;
	scanf("%d%d",&n,&m);
	for(i=n;i<=m;i++)
	{
	getPrime(i,color);
	for(iter=color.begin();iter!=color.end();iter++)
		iter==color.begin()?printf("%d=%d",i,*iter):printf("*%d",*iter);
	printf("\n");
	}
	return 0;
}
bool isPrime(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}
static void getPrime(int n, vector<int> &primes)
{  	
	if (isPrime(n)) 
	{  	
		primes.push_back(n); 		
		return; 
	}  	
	int k = 2; 
	while (k <= (int) sqrt((double) n))
	{  		
		if (n % k == 0)
		{  		
			if (isPrime(k)) 
			{  			
				primes.push_back(k); 		
			} 
			else 
			{  
				getPrime(k, primes); 	
			}  		
			int j = n / k;  
			if (isPrime(j))
			{  	
				primes.push_back(j); 		
			} 
			else 
			{ 			
				getPrime(j, primes); 		
			}  	
			return; 	
		}  	
		k++; 
	}
}
