#include<stdio.h>
int main(void)
{
	int i,j,n,m;
	void quiksort(int a[],int low,int high);
	scanf("%d",&m);
	for(;m>0;m--)
	{
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		quiksort(a,0,n-1);
		if(n%2==0)
			j=a[n/2-1]>a[n/2]?a[n/2]:a[n/2-1];
		else
			j=a[n/2];
		printf("%d\n",j);
	}
	return 0;
}
void quiksort(int a[],int low,int high)
{
    int i = low;
    int j = high;  
    int temp = a[i]; 
  
    if( low < high)
    {          
        while(i < j) 
        {
            while((a[j] >= temp) && (i < j))
            { 
                j--; 
            }
            a[i] = a[j];
            while((a[i] <= temp) && (i < j))
            {
                i++; 
            }  
            a[j]= a[i];
        }
        a[i] = temp;
        quiksort(a,low,i-1);
        quiksort(a,j+1,high);
    }
    else
    {
        return;
    }
}
