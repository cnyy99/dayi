/*#include<stdio.h>
int main(void)
{
	int isprime(int n);
	int i,n,k,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=2;i<=n;i++)
		{
			if(isprime(i))
				sum+=i;
		}
		printf("%d\n",sum);
	}
 } 
int isprime(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return 0;
			
	}	
	return 1;
}*/
/*#include<stdio.h>
int main(void)
{
	__int64 a,b,c,sum,n,j;
	scanf("%I64d",&n);
	for(j=1;j<=n;j++)
	{
		sum=0;
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		sum=a+b;
		if(sum==c)
			printf("Case %I64d: Happy!\n",j);
		else
			printf("Case %I64d: Kill!\n",j);
	}
	return 0;
}
#include<stdio.h>
int main(void)
{
	int a,b;
	for(;;)
	{
		scanf("%d%d",&a,&b);
		a^=b;
		printf("%d\t%d",a,b);
	}
}*/
/*#include<stdio.h>   
int main()   
{   
    int n,a;   
    scanf("%d",&n);   
    while(n>0)   
    {   
        scanf("%d",&a);   
        scanf("%d",&a);   
        printf("1.0000000000\n");   
        n--;
    }   
    return 0;   
} */
/*#include<stdio.h>
int main(void)
{
	int n,i,sum,m,j,t;
	while(scanf("%d",&m)!=EOF)
	{	int sum[m];
		for(i=0;i<m;i++)
			sum[i]=0;
		t=m;
		j=0;
		while(t>0){
			scanf("%d",&n);
			int a[n];
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
				sum[j]+=a[i];
			}
			t--;
			j++;
		}	
		for(i=0;i<m;i++)
			printf(i<m-1?"%d,":"%d\n",sum[i]);
	}	
	return 0;
}*/


/*#include<stdio.h>
int main()
{
    int a,b,i,j,site,ret,sum;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a==0&&b==0)
        {
            break;
        }
        int temp[50000]= {1};
        site=0;
        for(i=1;i<=b;i++)
        {
            for(j=0;j<=site;j++) temp[j]*=a;
            for(j=0;j<=site;j++)
            {
                temp[j+1]+=temp[j]/10;
                temp[j]%=10;
                if(temp[site]>0||temp[site+1]>0) ++site;
            }
        }
        ret = 0;
        sum = 0;
        while(site--) ret+=temp[site];
        while(ret!=0||sum/10!=0)
        {
            sum+=ret%10;
            ret/=10;
            if(ret==0&&sum/10!=0)
            {
                ret = sum;
                sum = 0;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}*/
/*#include<stdio.h>
int main(void)
{
	long long n,i,sum,j,m;
	while(scanf("%lld",&n)!=EOF)
	{
		j=0;
		while(n--)
		{
			scanf("%lld",&m);
			j++;
			sum=0;
			long long a[m];
			for(i=0;i<m;i++)
			{
				scanf("%lld",&a[i]);
				sum+=a[i];
			}
			printf(j==1?"%lld\n":"\n%lld\n",sum);
		}
	}
	return 0;
 } */
/*#include<stdio.h>
int main(void)
{
	int n,i,j,k,m;
	void print1(int n);
	void print2(int n);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("#\n");
			continue;
		}
		print1(n);
		print2(n);
		print1(n);
	}
}
void print1(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf(i<(n-1)?"#":"#\n");	
	} 
}
void print2(int n)
{
	int i,j;
	for(j=0;j<n-2;j++)
	{
		for(i=0;i<n-1;i++)
		{
			printf(i==0?"#":" ");
		}
		printf("#\n");
	}
}*/
/*#include<stdio.h>
int main(void)
{
	int n,t;
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:t=2;break;
			case 2:t=7;break;
			case 3:t=1;break;
			case 4:t=8;break;
			case 5:t=2;break;
			case 6:t=8;break;
			case 7:t=1;break;
			case 8:t=8;break;
			case 9:t=2;break;
			case 10:t=8;break;
			case 11:t=4;break;
			case 12:t=5;break;
			case 13:t=9;break;
			case 14:t=0;break;
			case 15:t=4;break;
		}
		printf("%d\n",t);
	}
	return 0;
} */
/*#include<stdio.h>
int main(void)
{
	int a,b,c,n,s,ac,bc;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{	s=c*c;
		ac=a%c;
		bc=b%c;
		if(ac==0&&bc==0)
		{
			n=a*b/s;
		}
		else if(ac==0&&bc!=0)
			{
				n=a*(b-bc)/s;
				n=n+a/c;
			}
		else if(bc==0&&ac!=0)
			{
				n=b*(a-ac)/s;
				n=n+b/c;
			}
		else if(bc!=0&&ac!=0)
			{
				n=(b-bc)*(a-ac)/s;
				n=n+(a-ac)/c+(b-bc)/c+1;
			}
		printf("%d\n",n);
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str1[101],str2[101];
	void change(char str[]);
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",str1);
		scanf("%s",str2);
		change(str1);
		change(str2);
		if(strcasecmp(str1,str2)==0)
			printf("YES\n");
		else
			printf("NO\n");	
	}
	return 0;
 }
 void change(char str[])
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='b'||str[i]=='B')
			str[i]='p';
		if(str[i]=='i'||str[i]=='I')
			str[i]='e';
	 } 
} 
 
 
 
 
 
 
 
 
 
 
 









