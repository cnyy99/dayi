#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	stack<char>s;
	while(1)
	{
		char c[110];
		cin>>c;
		s.push(c[0]);
		for (int i = 1; i < strlen(c); ++i)
		{
			switch(c[i])
			{
				case')':if(s.top()=='(')
							s.pop();
						else
							s.push(c[i]);
							break;
				case']':if(s.top()=='[')
							s.pop();
						else
							s.push(c[i]);
							break;
				case'(':s.push(c[i]);break;
				case'[':s.push(c[i]);break;
			}

		}
		if(s.empty())
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		while(!s.empty())
		{
			s.pop();
		}
	}
	return 0;
}
