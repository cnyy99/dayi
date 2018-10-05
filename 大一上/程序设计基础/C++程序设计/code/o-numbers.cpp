#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
class Date {

public:

	Date(int d = 0, int m = 0, int y = 0); //构造函数

	int get_day() const;// 返回day

	int get_month() const; //返回month

	int get_year() const; // 返回year

	static void set_default(int, int, int);

	static int get_default_day(); //返回缺省day

	static int get_default_month(); //返回缺省month

	static int get_default_year(); //返回缺省year

	Date & add_year(int n); //加n年

	Date & add_month(int n); //加n月，考虑超过12月，考虑闰年

	Date & add_day(int n); //加n天，考虑进位月和年，考虑闰年

private:

	int day, month, year;



};
//static Date default_date;//初始化为 1901年1月1日
bool isrun(int n)
{
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
		return true;
	else
		return false;
}
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
static Date default_date(1, 1, 1901);
void Date::set_default(int x, int y, int z)
{
	default_date.day = x;
	default_date.month = y;
	default_date.year = z;
}

int Date::get_day() const
{
	return day;
}
Date& Date::add_day(int n)
{
	day = day + n;

	if (month>12)
		{
			
			year = year + month / 12;
			month = month - month / 12 * 12;
			if(month%12==0)
			{

				year--;
				month=12;
			}
        }
	
	while (day>28)
	{

		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day>31)
		{
			day = day - 31;
			if (month == 12)
			{
				month = 1;
				year++;
			}
			else
				month++;

		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && day>30)
		{
			month++;
			day = day - 30;
		}
		else if (month == 2 && isrun(year) && day>29)
		{
			month++;
			day = day - 29;
		}
		else if (month == 2 && !isrun(year) && day>28)
		{
			month++;
			day = day - 28;
		}
		else
			break;
	}

return *this;
}
Date& Date::add_month(int n)
{
	month = month + n;
	if (month>12)
	{	
		year = year + month / 12;
		month = month - month / 12 * 12;
		if(month % 12 == 0)
		{
			year--;
			month = 12;
		}
   	}
	
	return *this;
}
Date& Date::add_year(int n)
{
	year = year + n;
	return *this;
}
int Date::get_month() const
{
	return month;
}
int Date::get_year()const
{
	return year;
}
int Date::get_default_day()
{
	return default_date.day;
}
int Date::get_default_year()
{
	return default_date.year;
}
int Date::get_default_month()
{
	return default_date.month;
}
int main() {

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