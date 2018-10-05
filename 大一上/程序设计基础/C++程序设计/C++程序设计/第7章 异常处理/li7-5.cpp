#include <iostream>
using namespace std;

void fun()
{
	try{
		throw 'A';
	}
	catch(char)
	{
		cout<<"内部异常处理"<<endl;
		throw 'B';
	}
}

int main()
{
	try{
		fun();
	}
	catch(char)
	{
		cout<<"外部异常处理"<<endl;
	}
	return 0;
}