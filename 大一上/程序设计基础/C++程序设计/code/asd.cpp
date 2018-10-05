#include <iostream>
#include<cstring>
using namespace std;

int maxd(int y, int m)
{
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 2:
		if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
			return 29;
		else
			return 28;
	default:
		return 30;
	}
}

class Date {
private:
	int day, month, year;
	//static Date default_date; //初始化为 1901年1月1日

public:
	Date() { day = month = year = 0; }
	Date(int d, int m, int y); //构造函数
	int get_day() const; // 返回day
	int get_month() const; //返回month
	int get_year() const; // 返回year
	static void set_default(int, int, int);
	static int get_default_day();//返回缺省day
	static int get_default_month();//返回缺省month
	static int get_default_year();//返回缺省year
	Date& add_year(int n); //加n年
	Date& add_month(int n); //加n月，考虑超过12月，考虑闰年
	Date& add_day(int n); //加n天，考虑进位月和年，考虑闰年
};
static Date default_date = Date(1, 1, 1901);
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

int Date::get_day() const
{
	return day;
}

int Date::get_month() const
{
	return month;
}

int Date::get_year() const
{
	return year;
}
void Date::set_default(int d, int m, int y) {
	default_date = Date(1, 1, 1901);
	default_date.day = d;
	default_date.month = m;
	default_date.year = y;
}
int Date::get_default_day() {
	return default_date.get_day();
}
int Date::get_default_month() {
	return default_date.get_month();
}

int Date::get_default_year() {
	return default_date.get_year();
}

Date& Date::add_year(int n)
{
	year += n;
	return *this;
}
Date& Date::add_month(int n)
{
	if (month + n <= 12)
		{
			month += n;
			return *this;
		}
	n = month + n - 12;
	add_year(1);
	month = 0;

	while (n > 12)
	{
		n -= 12;
		add_year(1);
	}
	month += n;
	return *this;
}
Date& Date::add_day(int n)
{
	
	if (day + n <= maxd(year, month))
	{
		day += n;
		return *this;
	}
	n = day + n - maxd(year, month);
	add_month(1);
	day = 0;
	while (n > maxd(year, month))
	{
		n -= maxd(year, month);
		add_month(1);
	}
	day += n;
	return *this;
}


int main(
) {

	char type[110];

	int day, mon, year;

	int addday, addmon, addyear;

	while (cin >> type) {

		if (strcmp(type, "Date") == 0) {

			cin >> day >> mon >> year;

			Date mydate(day, mon, year);

			cin >> addday >> addmon >> addyear;

			mydate.add_day(addday).add_month(addmon).add_year(addyear);
			

			cout << mydate.get_day() << " " << mydate.get_month() << " " << mydate.get_year() << endl;

		}
		else if (strcmp(type, "defaultDate") == 0) {


			cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;

		}
		else if (strcmp(type, "setdefaultDate") == 0) {

			cin >> day >> mon >> year;


			Date::set_default(day, mon, year);

			cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;

		}

	}

	return 0;

}