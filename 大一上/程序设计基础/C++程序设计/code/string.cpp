#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	string s1;
	getline(cin,s1);
	decltype(s1.size()) cnt=0;
	for(auto c: s1)
	{
		if(isdigit(c))
		{
			++cnt;
		}
	} 
	cout<<cnt<<" "<<s1<<endl;
	return 0;
}