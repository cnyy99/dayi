#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
class date{
	private:
		int year;
		int mon;
		int day;
	public:
		friend int date_ans(date &s1,date &s2);
		int get_year(){return year;}
		int get_mon(){return mon;}
		int get_day(){return day;}
		date();
};
date::date()
{
	scanf("%d-%d-%d",&year,&mon,&day);
}
int date_ans(date &s1,date &s2)
{
	int a,b,c,a1,b1,d,c1,d1;
	a1=s1.get_year();
	b1=s2.get_year();
	a=(s1.get_year()-1)/4-(s1.get_year()-1)/100+(s1.get_year()-1)/400;
	b=(s2.get_year()-1)/4-(s2.get_year()-1)/100+(s2.get_year()-1)/400;
	c=366*a+(a1-a)*365;
	d=366*b+(b1-b)*365;
	if(!(s1.get_year()%400==0||(s1.get_year()%4==0&&s1.get_year()%100!=0))&&!(s2.get_year()%400==0||(s2.get_year()%4==0&&s2.get_year()%100!=0)))
	{
		switch(s1.get_mon())
		{
			case 2:c+=31;break;
			case 3:c+=59;break;
			case 4:c+=90;break;
			case 5:c+=120;break;
			case 6:c+=151;break;
			case 7:c+=181;break;
			case 8:c+=212;break;
			case 9:c+=243;break;
			case 10:c+=273;break;
			case 11:c+=304;break;
			case 12:c+=334;break;
			case 1:;break;
		}
		switch(s2.get_mon())
		{
			case 2:d+=31;break;
			case 3:d+=59;break;
			case 4:d+=90;break;
			case 5:d+=120;break;
			case 6:d+=151;break;
			case 7:d+=181;break;
			case 8:d+=212;break;
			case 9:d+=243;break;
			case 10:d+=273;break;
			case 11:d+=304;break;
			case 12:d+=334;break;
			case 1:;break;
		}
		c+=s1.get_day();
		d+=s2.get_day();
		return abs(c-d);
	}
	else if(!(s1.get_year()%400==0||(s1.get_year()%4==0&&s1.get_year()%100!=0))&&(s2.get_year()%400==0||(s2.get_year()%4==0&&s2.get_year()%100!=0)))
	{
		switch(s1.get_mon())
		{
			case 2:c+=31;break;
			case 3:c+=59;break;
			case 4:c+=90;break;
			case 5:c+=120;break;
			case 6:c+=151;break;
			case 7:c+=181;break;
			case 8:c+=212;break;
			case 9:c+=243;break;
			case 10:c+=273;break;
			case 11:c+=304;break;
			case 12:c+=334;break;
			case 1:;break;
		}
		switch(s2.get_mon())
		{
			case 2:d+=31;break;
			case 3:d+=60;break;
			case 4:d+=91;break;
			case 5:d+=121;break;
			case 6:d+=152;break;
			case 7:d+=182;break;
			case 8:d+=213;break;
			case 9:d+=244;break;
			case 10:d+=274;break;
			case 11:d+=305;break;
			case 12:d+=335;break;
			case 1:;break;
		}
		c+=s1.get_day();
		d+=s2.get_day();
		return abs(c-d);
	}
	else if((s1.get_year()%400==0||(s1.get_year()%4==0&&s1.get_year()%100!=0))&&!(s2.get_year()%400==0||(s2.get_year()%4==0&&s2.get_year()%100!=0)))
	{
		switch(s2.get_mon())
		{
			case 2:c+=31;break;
			case 3:c+=59;break;
			case 4:c+=90;break;
			case 5:c+=120;break;
			case 6:c+=151;break;
			case 7:c+=181;break;
			case 8:c+=212;break;
			case 9:c+=243;break;
			case 10:c+=273;break;
			case 11:c+=304;break;
			case 12:c+=334;break;
			case 1:;break;
		}
		switch(s1.get_mon())
		{
			case 2:d+=31;break;
			case 3:d+=60;break;
			case 4:d+=91;break;
			case 5:d+=121;break;
			case 6:d+=152;break;
			case 7:d+=182;break;
			case 8:d+=213;break;
			case 9:d+=244;break;
			case 10:d+=274;break;
			case 11:d+=305;break;
			case 12:d+=335;break;
			case 1:;break;
		} 
		c+=s1.get_day();
		d+=s2.get_day();
		return abs(c-d);
	}
	if((s1.get_year()%400==0||(s1.get_year()%4==0&&s1.get_year()%100!=0))&&(s2.get_year()%400==0||(s2.get_year()%4==0&&s2.get_year()%100!=0)))
	{
		switch(s2.get_mon())
		{
			case 2:d+=31;break;
			case 3:d+=60;break;
			case 4:d+=91;break;
			case 5:d+=121;break;
			case 6:d+=152;break;
			case 7:d+=182;break;
			case 8:d+=213;break;
			case 9:d+=244;break;
			case 10:d+=274;break;
			case 11:d+=305;break;
			case 12:d+=335;break;
			case 1:;break;
		} 
		switch(s1.get_mon())
		{
			case 2:d+=31;break;
			case 3:d+=60;break;
			case 4:d+=91;break;
			case 5:d+=121;break;
			case 6:d+=152;break;
			case 7:d+=182;break;
			case 8:d+=213;break;
			case 9:d+=244;break;
			case 10:d+=274;break;
			case 11:d+=305;break;
			case 12:d+=335;break;
			case 1:;break;
		} 
		c+=s1.get_day();
		d+=s2.get_day();
		return abs(c-d);
	}
}
int main()
{
	date d1;
	date d2;
	cout<<date_ans(d1,d2)<<endl;
	return 0;
}

