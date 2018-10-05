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
	catch(double d)
	{	cout<<"输入的是负数："<<x<<endl;}
}

int main()
{
	fun(3);
	fun(0);
	fun(-3);
	return 0;
}



#include <iostream>
using namespace std;

int main()
{
	int n;
	
	while (cin >> n){
		try{
			if (n > 0)
				throw 1;
			else
				if (n < 0)
					throw 'c';
				else
					throw 2.0;
		}
		catch (int){
			cout << "positive number: " << n << "\n";
		}
		catch (char){
			cout << "negative number: " << n << "\n";
		}
		catch (double){
			cout << "zero " << n << "\n";
		}
	}

	system("pause");
	return 0;
}