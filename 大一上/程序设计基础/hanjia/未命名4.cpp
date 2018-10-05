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
struct menu{
	int beginl;
	int endl;
};
struct menu times[110];
struct menu mm;
bool cmp(struct menu x,struct menu y)
{
	return x.endl<y.endl;
}
int main()
{
	int i,j,k,l,t,number;
	while(scanf("%d",&t)!=EOF)
	{
		if(t==0)
			return 0;
		for(i=0;i<t;i++)
		{
			scanf("%d%d",&times[i].beginl,&times[i].endl);
		}
		for(i=0;i<t-1;i++)        
        {            
            for(j=0;j<t-i-1;j++)            
            {                
                if(times[j].endl>times[j+1].endl)                
                {                    
                    mm=times[j];
					times[j]=times[j+1];
					times[j+1]=mm;             
                }            
            }        
        }        
//		sort(times,times+t,cmp);
		mm=times[0];
		number=1;
		k=times[0].endl;
		for(i=1;i<t;i++)
		{
			if(times[i].beginl>=mm.endl)
			{
				number++;
				mm=times[i];
			}
		}
		printf("%d\n",number);
	}
	return 0;	
}
















