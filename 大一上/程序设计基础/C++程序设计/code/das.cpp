/*#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <functional>
using namespace std;

class bign
{
public:
	bign();
	bign(char*s);
	bign(int num);
	~bign();
	bign &operator+(const bign &number1);
	friend ostream & operator<<(ostream & out, bign & nu);
private:
	int number[10000];
	int length;
};

bign::bign()
{
	length = 0;
}

bign::bign(char * s)
{
	length = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		number[i] = s[i] - '0';
		i++;
	}
	length = i;
}

bign::bign(int num)
{
	char s[10000];
	itoa(num, s, 10);
	int i = 0;
	while (s[i] != '\0')
	{
		number[i] = s[i] - '0';
		i++;
	}
	length = i;
}

bign::~bign()
{
	length = 0;
}
bign & bign::operator+(const bign & number1)
{

	int i, j, k;
	int c[10000];
	int len1 = length;
	int len2 = number1.length;
	k = (len1 > len2) ? len1 : len2;
	memset(c, 0, sizeof(c));
	int carry = 0, temp;
	for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--, k--)
	{
		temp = carry;
		if (i >= 0) temp += this->number[i];
		if (j >= 0) temp += number1.number[j];

		if (temp >= 10) {
			c[k] = temp - 10 ;
			carry = 1;
		}
		else {
			c[k] = temp;
			carry = 0;
		}
	}
	c[k] = carry;
	int *p=c;
	if (c[k] == 0)
		p++;
	memcpy(number, p,k*sizeof(int));
	return *this;	// TODO: 在此处插入 return 语句
}
ostream & operator<<(ostream & out, bign & nu)
{
	for (int i = 0; i < nu.length; i++)
	{
		out << nu.number[i];
	}
	return out;
	// TODO: 在此处插入 return 语句
}
int main()
{
	char str[100];
	cin>>str;
	bign a(str);
	int b=23423432;
	cout<<a+b<<endl;
	return 0;
}*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <functional>
using namespace std;
template <typename T,int size>
int find(T(&array)[size],T b)
{
	for (int i = 0; i <size; i++)
	{
		if (b == array[i])
			return i;
	}
	return -1;
}

template<typename T>

{
	T h[999];
	int a;
	for (int i = 0; i < a; ++i)
	{
		cin>>h[i];
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	int *sum = new int[a];
	for (int i = 0; i < a; i++)
	{
		cin >> sum[i];
	}
	cout << find(sum,b) << endl;
	double b1;
	cin >> a >> b1;
	double *sum2=new double[a];
	for (int i = 0; i < a; i++)
	{
		cin >> sum2[i];
	}
	cout << find(sum2,b1) << endl;
	char c;
	cin >> a >> c;
	char *str=new char[a];
	for (int i = 0; i < a; i++)
	{
		cin >> str[i];
	}
	cout << find(str,c) << endl;
	delete[]sum;
	delete[]sum2;
	delete[]str;
	system("pause");
	return 0;
}