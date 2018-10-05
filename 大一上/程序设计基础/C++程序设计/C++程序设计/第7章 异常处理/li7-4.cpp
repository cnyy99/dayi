#include <iostream>
using namespace std;

void fun(int x)
{
	try{
		if(x>0) throw 5;
		if(x==0) throw 'A';
		if(x<0) throw 5.55;
	}
	catch(int n)
	{	cout<<"输入的是正数："<<x<<endl;}
	catch(char c)
	{	cout<<"输入的是0:"<<x<<endl;}
	catch(...)
	{	cout<<"输入的数字为："<<x<<endl;}

}

int main()
{
	fun(3);
	fun(0);
	fun(-3);
	return 0;
}