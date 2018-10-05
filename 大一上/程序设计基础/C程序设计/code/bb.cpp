#include<stdio.h>
int main(void)
{
	int n;
	int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	int search(int a[],int n,int k);
	int k;
	n=sizeof(a)/sizeof(a[0]);
	printf("Please input the number you want to find:");
	scanf("%d",&k);
	if(search(a,n,k)!=-1)
		printf("is the %d number.\n",search(a,n,k)+1);
	else
		printf("Not find.\n");
	return 0; 
 } 
int search(int a[],int n,int k)
{
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==k)
			return mid;
		else if(a[mid]<k)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}

















