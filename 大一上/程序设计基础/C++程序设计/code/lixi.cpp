#include <cstdio>
#include <iostream>
using namespace std;
class money_rate
{
private:
	string owner;
	double money;
	static double rate;
	static double inputrate();
public:
	money_rate(string owner,double money);
	money_rate(){}
	double get_rate();
	double get_money();
	string get_owner();
	void caulc();
	
};
money_rate::money_rate(string owner,double money)
{
	this->owner=owner;
	this->money=money;
}
double money_rate::get_rate()
{
	return rate;
}
double money_rate::get_money()
{
	return money;
}
string money_rate::get_owner()
{
	return owner;
}
void money_rate::caulc()
{
	money = money + money * rate;
}
double money_rate::rate=inputrate();
double money_rate::inputrate()
{
	double s;
	cin>>s;
	return s;
}
int main()
{
	money_rate s1("feiyang",900);
	s1.caulc();
	string name;
	double no;
	cin>>name>>no;
	money_rate s2(name,no);
	s2.caulc();
	cout<<s1.get_owner()<<" "<<s1.get_money()<<endl;
	cout<<s2.get_owner()<<" "<<s2.get_money()<<endl;
	return 0;
}