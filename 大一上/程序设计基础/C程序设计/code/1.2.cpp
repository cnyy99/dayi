#include<stdio.h>
int main(void)
{
	int i,j,k,n,t,b,m;
	void quiksort(int a[],int low,int high);
	scanf("%d",&m);
	while(m>0){
		int a[100000]={0};
		scanf("%d",&n);
		for(i=0;i<n;i++)
			{
				scanf("%d",&k);
				a[k]=1;
			}
		for(i=0,b=0;i<100000;i++)
			if(a[i])
			{
				a[b]=i;
				b++;
			}
		quiksort(a,0,b-1);	
		for(j=0;j<b;j++)	
			printf("%d\n",a[j]);
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
