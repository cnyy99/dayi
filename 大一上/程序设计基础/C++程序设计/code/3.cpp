#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9,0};
	v.push_back(200);
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		*i=2**i;
	}
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		cout<<*i<<"\t";
	}


	return 0;
}