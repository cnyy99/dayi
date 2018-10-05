#include<stdio.h>

struct d {  

   int start;

    int end;

}; 

int main()
{

 struct d a[100],temp;

   int i,j,n,count;

 while(scanf("%d",&n)&&n)
 {

      for(i=0;i<n;i++)    

        scanf("%d%d",&a[i].start,&a[i].end);   

      for(i=0;i<n-1;i++)    

       for(j=0;j<n-1-i;j++)   

      if(a[j].end>a[j+1].end){    

           temp=a[j];                

           a[j]=a[j+1];

     a[j+1]=temp;   

          }    

 temp.end=a[0].end;count=1;  

   for(i=1;i<n;i++)     

 if(a[i].start>=temp.end){    

   count++;      

 temp.end=a[i].end;

     }             

printf("%d\n",count);  

 }  return 0;  

}
