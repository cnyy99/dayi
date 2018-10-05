#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
class String {
private:
	char *s;
public:
	String();
	String(const char *str);
	String( const String &str);
	~String();
	String & operator=(const String &str);
	friend ostream & operator<<(ostream&os, const String &str);
	friend istream & operator>>(istream&is,String &str);
};
String::String()
{
	s = NULL;
}
String::String(const char *str)
{
	s = new char[strlen(str) + 1];
	strcpy(s,str);
}
String::String(const String &str)
{
	s = new char[strlen(str.s) + 1];
	strcpy(s,str.s);
}
String::~String()
{
	if (s != NULL)
	{
		delete[]s;
		s = NULL;
	}
		
}
String& String::operator=(const String &str)
{
	if (s == str.s)
		return *this;
	else
	{
		delete[]s;
		s = new char[strlen(str.s) + 1];
		strcpy(s,str.s);
		return *this;
	}
		
}

ostream & operator<<(ostream & os, const String & str)
{
	os << str.s;
	return os;

}

istream & operator>>(istream & is,  String & str)
{
	if (str.s != NULL)
	{
		delete[]str.s;
		str.s = NULL;
	}
	str.s=new char [225];
	is >> str.s;
	return is;
}
int main()
{
	String s1("hello"), s2;
	cin >> s2;
	String s3(s1);
	cout << s1 << " " << s2 << " " << s3 << endl;
	s1 = s2;
	cout << s1 << endl;
	system("pause");
}