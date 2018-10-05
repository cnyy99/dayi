#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,k,n,m;
	int t,len,ok;
	stack<char>mystack;
	scanf("%d",&t);
	while(t--)
	{
		ok=0;
		char str[10007];
		scanf("%s",str);
		len=strlen(str);	
		for(i=0;i<len;i++)
		{
			switch(str[i])
			{
				case '[':mystack.push(str[i]);break;
				case '(':mystack.push(str[i]);break;
				case ']':if(!mystack.empty()&&mystack.top()=='[')
						{
							mystack.pop();
							ok=1;
						}
						else
							mystack.push(str[i]);	
						break;
				case ')':if(!mystack.empty()&&mystack.top()=='(')
						{
							mystack.pop();
							ok=1;
						}
						else
							mystack.push(str[i]);
						break;
				default:break;
			}
			
		}
		if(ok&&mystack.empty())
			printf("Yes\n");
		else
			{
				printf("No\n");
				while(!mystack.empty())
					mystack.pop();
			}
		
	}
	return 0;
}
