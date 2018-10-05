#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
class student{
	private:
		char name[17];
		int no;
		char sex;
		int age;
	public:
		void set(char *p,int n,char h,int m);

		char *show_name();
	
		int show_no();
		
		char show_sex();
		
		int show_age();
		
};
void student::set(char *name,int no,char sex,int age)
{
	strcpy(this->name,name);
	this->no = no;
	this->sex = sex;
	this->age = age;
}
char *student::show_name()
{
	return name;
}
int student::show_no()
{
	return no;
}
char student::show_sex()
{
	return sex;
}
int student::show_age()
{
	return age;
}
int main()
{
	int a,b,n;
	char name[17];
	char s;
	student stu;
	cin>>name>>a>>s>>n;
	stu.set(name,a,s,n);
	cout<<stu.show_name()<<' '<<stu.show_no()<<' '<<stu.show_sex()<<' '<<stu.show_age()<<endl;
	return 0;
}























