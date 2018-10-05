// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #include <cstring>
// #include <string.h>
// #include <cstdlib>
// #include <iostream>
// #include <functional>
// using namespace std;
// class String {

// private:

// 	char * s;

// public:

// 	String();

// 	String(const char *);

// 	String(const String &);

// 	~String();

// 	String & operator=(const char *);

// 	String & operator=(const String &);

// 	String operator+(const char *);

// 	String operator+(const String &);

// 	String & operator+=(const char *);

// 	String & operator+=(const String &);

// 	friend istream & operator>>(istream &, String &);

// 	friend ostream & operator<<(ostream &, const String &);

// 	friend bool operator==(const String &, const char *);

// 	friend bool operator==(const String &, const String &);

// 	friend bool operator!=(const String &, const char *);

// 	friend bool operator!=(const String &, const String &);

// };

// String::String()
// {
// 	s = NULL;
// }

// String::String(const char *str)
// {
// 	s = new char[strlen(str) + 1];
// 	strcpy(s, str);
// }

// String::String(const String &str)
// {
// 	s = new char[strlen(str.s) + 1];
// 	strcpy(s, str.s);
// }

// String::~String()
// {
// 	if (s != NULL)
// 		delete[]s;
// 	s = NULL;
// }

// String & String::operator=(const char *str)
// {
// 	s = NULL;
// 	s = new char[strlen(str) + 1];
// 	strcpy(s, str);
// 	return *this;
// 	// TODO: 在此处插入 return 语句
// }

// String & String::operator=(const String &str)
// {
// 	s = NULL;
// 	s = new char[strlen(str.s) + 1];
// 	strcpy(s, str.s);
// 	return *this;
// 	// TODO: 在此处插入 return 语句
// }

// String String::operator+(const char *str)
// {
// 	String temp;
// 	temp.s = new char[strlen(s) + strlen(str) + 1];
// 	strcpy(temp.s, s);
// 	strcat(temp.s, str);
// 	return temp;
// }

// String String::operator+(const String &str)
// {
// 	String temp;
// 	temp.s = new char[strlen(s) + strlen(str.s) + 1];
// 	strcpy(temp.s, s);
// 	strcat(temp.s, str.s);
// 	return temp;
// }

// String & String::operator+=(const char *str)
// {
// 	String temp;
	
// 	if(s!=NULL)
// 	{
// 		temp.s = new char[strlen(s) + strlen(str) + 1];
// 		strcpy(temp.s, s);
// 		strcat(temp.s, str);
// 	}
// 	else
// 	{
// 		temp.s = new char[strlen(str) + 1];
// 		strcpy(temp.s, str);
// 	}
// 	if(s!=NULL)
// 		delete[]s;
// 	s = new char[strlen(temp.s) + 1];
// 	strcpy(s, temp.s);
// 	return *this;
// 	// TODO: 在此处插入 return 语句
// }

// String & String::operator+=(const String &str)
// {
// 	String temp;
	
// 	if(s!=NULL)
// 	{
// 		temp.s = new char[strlen(s) + strlen(str.s) + 1];
// 		strcpy(temp.s, s);
// 		strcat(temp.s, str.s);
// 	}
// 	else
// 	{
// 		temp.s = new char[strlen(str.s) + 1];
// 		strcpy(temp.s, str.s);
// 	}
// 	if(s!=NULL)
// 		delete[]s;
// 	s = new char[strlen(temp.s) + 1];
// 	strcpy(s, temp.s);
// 	return *this;
// 	// TODO: 在此处插入 return 语句
// }

// istream & operator>>(istream &is, String &str)
// {
// 	char sch[30];
// 	is >> sch;
// 	str.s = new char[strlen(sch) + 1];
// 	strcpy(str.s, sch);
// 	return is;
// 	// TODO: 在此处插入 return 语句
// }

// ostream & operator<<(ostream &os, const String &str)
// {
// 	os << str.s;
// 	return os;
// 	// TODO: 在此处插入 return 语句
// }

// bool operator==(const String &str1, const char *str)
// {
// 	if (strcmp(str1.s, str) == 0)
// 		return true;
// 	else
// 		return false;
// }

// bool operator==(const String &str1, const String &str2)
// {
// 	if (strcmp(str1.s, str2.s) == 0)
// 		return true;
// 	else
// 		return false;
// }

// bool operator!=(const String &str1, const char *str)
// {
// 	if (strcmp(str1.s, str) == 0)
// 		return false;
// 	else
// 		return true;
// }

// bool operator!=(const String &str1, const String &str2)
// {
// 	if (strcmp(str1.s, str2.s) == 0)
// 		return false;
// 	else
// 		return true;
// }
// int main() {

// 	String s;

// 	s += "hello";

// 	cout << s << endl;

// 	String s1("String1");

// 	String s2("copy of ");

// 	s2 += "String1";

// 	cout << s1 << "\n" << s2 << endl;

// 	String s3;

// 	cin >> s3;

// 	cout << s3 << endl;

// 	String s4("String4"), s5(s4);

// 	cout << (s5 == s4) << endl;

// 	cout << (s5 != s4) << endl;

// 	String s6("End of "), s7("my string.");

// 	s6 += s7;

// 	cout << s6 << endl;

// 	return 0;

// }
// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <cstdlib>
// #include <iostream>
// #include <functional>
// using namespace std;
// int main()
// {
// 	int a;
// 	a=2;
// 	char b=20;
// 	char c;
// 	c=a+'0';
// 	cout<<a<<b<<c;
// 	return 0;
// }
#include <iomanip>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

// template<typename t>
// class Complex;
// template<typename Ta>
// Complex<Ta>  operator+(Complex<Ta> & f1, Complex<Ta> & f2);
 template<typename t>
class Complex
{
public:
	Complex(t a, t b);
	//	 template<typename T>

	Complex<t>  operator+(Complex<t> &f1);
	t Mag()
	{
		return(sqrt(a*a + b*b));
	}
	~Complex() {}

private:
	t a;
	t b;
};
 template<typename t>
 Complex<t>::Complex(t a,t b)
 {
 	this->a=a;
 	this->b=b;
 }
 template<typename t>
 Complex<t> Complex<t>::operator+(Complex<t> & f1)
 {
 	return Complex<t>(f1.a + a, f1.b + b);
	// TODO: 在此处插入 return 语句
 }
int main()

{

	int ir, ii;

	cin >> ir >> ii;

	Complex<int> ci1(ir, ii);

	Complex<int> ci2(2, 3);

	Complex<int> ci = ci1 + ci2;

	cout << ci.Mag() << endl;



	double dr, di;

	cin >> dr >> di;

	Complex<double> cd(dr, di);

	cout << setiosflags(ios::fixed) << setprecision(2);

	cout << cd.Mag() << endl;

	system("pause");
	return 0;

}