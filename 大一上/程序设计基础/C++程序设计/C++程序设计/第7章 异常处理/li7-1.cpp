#include <iostream>
using namespace std;

int divi(int x, int y)
{
	if(y==0) throw 0;
	return x/y;
}

int main()
{
	int m, n;
	try{
		cout<<"ÇëÊäÈëm,n:";
		cin>>m>>n;
		cout<<"m/n = "<<divi(m,n)<<endl;
	}
	catch(int)
	{
		cout<<"³ýÊýÎª0\n";
	}
	return 0;
}




#include <iostream>
using namespace std;

int main()
{
	try{
		int m, n;
		while (cin >> m >> n)
			if (n != 0)
				cout << m / n << endl;
			else
				throw 0;
	}
	catch (int){
		cout << "divide by zero\n";
	}

	system("pause");
	return 0;
}