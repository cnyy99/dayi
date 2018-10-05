#include <stdio.h>
#include <math.h>
int main()
{
    unsigned long long n,m,x;
    while(scanf("%llu",&n)!=EOF)
    {
        for(m=sqrt(2)*sqrt(n);((m/2.0)*((m+1)/2.0))<n/2.0;m++);
        x = n-(m*(m-1)/2);
        if(m&1)printf("(%llu,%llu)\n",m-x+1,x);
        else printf("(%llu,%llu)\n",x,m-x+1);
    }
    return 0;
}

