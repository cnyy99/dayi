#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,k,m,n;
	map<int,char>color;
	map<int,int>color2;
	map<int,char>::iterator iter;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<2*n;i++)
		{
			color[i]='G';
			color2[i]='G';
		}
	/*	for(;;)
		{
			
		}*/
		int count=0;
		while(color.size()!=n)
		for(  iter = color.begin();iter != color.end(); )
    	{
	        std::map<int, char>::iterator it_back = iter;
	        bool is_first_element = false;
	        if(it_back != color.begin())
	        it_back --;
	        else
	        is_first_element = true;
	        
	        // delete the element that matches the specific condition
	        if( iter->first % 2 == 0)
	        {
	            color.erase(iter);
	            if(is_first_element)
	             iter = color.begin();
	            else
	                iter = ++ it_back;
	       }else iter ++;      
        		count++;
   		 }
	}
}
