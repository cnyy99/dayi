#include<stdio.h>   
int main(void)   
{   
    int n,a,b,i;   
    while(scanf("%d",&n)!=EOF)   
    {   
        if(n%2==0)   
      		continue;   
        b=0;   
        for(i=0;i<n;i++)   
        {   
        	scanf("%d",&a);   
			b^=a;   
		}   
        printf("%d\n",b);   
        }   
    return 0;   
}  

