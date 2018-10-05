#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int a[100]={};
	//memset(a,0,sizeof(a));
	for(auto &c:a)
	{
		cout<<c<<endl;
	}
	return 0;
}
