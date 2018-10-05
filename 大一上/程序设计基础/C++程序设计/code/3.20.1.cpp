// #include <cstdio>
// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;
// class person {
// protected:
// 	string id;
// 	string name;
// public:
// 	person(string, string);
// 	virtual void display();
// };
// person::person(string id, string name)
// {
// 	this->id = id;
// 	this->name = name;
// }
// void::person::display()
// {
// 	cout << id << " " << name << "\n";
// }
// class student :public person {
// protected:
// 	string no;
// public:
// 	student(string, string, string);
// 	void display();
// };
// student::student(string id, string name, string no) :person(id, name)
// {
// 	this->no = no;
// }
// void student::display()
// {
// 	cout << id << " " << name << " " << no << endl;
// }
// class mclass:public student{
// private:
// 	int nu;
// public:
// 	mclass(string id, string name,string no, int nu);
// 	void display();
// };
// mclass::mclass( string id,string name,string no,int nu) :student( id,name,no)
// {
// 	this->nu = nu;
// }
// void mclass::display()
// {
// 	cout << id << " " << name << " " <<no<<" "<< nu << endl;
// }

// int main()
// {
// 	person m1("10002", "fsadf");
// 	student m2("10003", "asdf", "1212");
// 	mclass m3("sadfads", "fsafsa", "fasdfas",2342);
// 	person *p= &m1;
// 	p->display();
// 	p = &m2;
// 	p->display();
// 	p = &m3;
// 	p->display();
// 	getchar();
// 	return 0;
// }
#include<iostream>
using namespace std;
template<typename T>
void swapd(T &a,T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a, b;
	double c, d;
	char f, g;
	cin >> f >> g;
	swapd(f, g);
	cout << f << " " << g << endl;
	cin >> a >> b;
	swapd(a, b);
	cout << a <<" "<< b << endl;
	cin >> c >> d;
	swapd(c, d);
	cout << c << " "<<d << endl;
	system("pause");
	return 0;
}
