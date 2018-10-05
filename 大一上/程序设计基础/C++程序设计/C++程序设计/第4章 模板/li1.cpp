#include <iostream>
using namespace std;

template <typename T>
T & max(T & a,T & b)
{
	return a>b ? a : b;
}

int main()
{
	int i1 = 30, i2 = 50;
	double d1 = 3.33, d2 = 4.44;
	char c1 = 'A', c2 = 'B';
	cout<<"较大的整数为："<<max(i1,i2)<<"\n";
	cout<<"较大的浮点数为："<<max(d1,d2)<<"\n";
	cout<<"较大的字符为："<<max(c1,c2)<<endl;
	return 0;
}
