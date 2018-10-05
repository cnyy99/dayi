#include <cstring>
#include <iostream>
using namespace std;
class student
{
private:
	int no;
	string name;
	char sex;
	int age;
	string adr;
public:
	 student(int no=0,string="No name",char sex='N',int age=0,string adr="No adr");
	 friend istream&operator>>(istream&is,student &stu);
	 friend ostream&operator<<(ostream&os,student &stu); 
	 ~student(){}
	
};
student::student(int no,string name,char sex,int age,string adr)
{
	this->no=no;
	this->name=name;
	this->sex=sex;
	this->age=age;
	this->adr=adr;
}
istream & operator>>(istream &is,student &stu)
{
	is>>stu.no>>stu.name>>stu.sex>>stu.age>>stu.adr;
	return is;
}
ostream & operator<<(ostream &os,student &stu)
{
	os<<stu.no<<" "<<stu.name<<" "<<stu.sex<<" "<<stu.age<<" "<<stu.adr;
	return os; 
}
int main()
{
	student s1(1001,"zhangming",'s',17,"london");
	student s2,s3;
	h
	cin>>s2;
	cout<<s1<<endl<<s2<<endl<<s3<<endl;
	return 0;
}