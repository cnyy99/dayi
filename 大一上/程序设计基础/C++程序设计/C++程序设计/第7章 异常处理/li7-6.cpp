#include <iostream>
using namespace std;

class Demo
{
public:
	int x;
	Demo(int y)
	{
		x = y;
		cout<<"进入Demo类的构造函数"<<endl;
		if(x<0) throw x;
		else
			cout<<"调用Demo类的构造函数，构造对象"<<y<<endl;
	}
	~Demo()
	{
		cout<<"调用Demo类的析构函数，析构对象"<<x<<endl;
	}
};

void fun()
{
	cout<<"进入函数fun"<<endl;
	Demo d1(4),d2(-5);  // fun中止执行
	throw 'A';
}

int main()
{
	cout<<"主函数开始执行"<<endl;
	try{
		cout<<"调用fun函数"<<endl;
		fun();
	}
	catch(int n)
	{
		cout<<"对象"<<n<<"发生错误"<<endl;
	}
	catch(char)
	{
		cout<<"在函数中抛出异常"<<endl;
	}
	cout<<"主函数执行完毕"<<endl;
	return 0;
}