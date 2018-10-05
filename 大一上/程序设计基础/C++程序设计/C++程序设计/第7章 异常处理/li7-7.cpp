#include <iostream>
#include <iomanip>
using namespace std;
#define max 3

class Info
{
protected:
	int no;
	char name[20];
	double score;
public:
	void getInfo()
	{
		cout<<"输入学号、姓名和成绩：";
		cin>>no>>name>>score;
		if(no<=0 || no>max)
			throw no;
		if(score<0.0 || score>100.0)
			throw score;
	}
	void show()
	{
		cout<<setw(4)<<no<<setw(20)<<name<<setw(6)<<score<<endl;
	}
};



int main()
{
	Info stu[max];
	cout<<"请输入信息：\n";
	for(int i=0;i<max;i++)
	{
		try{
			stu[i].getInfo();
		}
		catch(int)
		{
			cout<<"学号输入越界\n";
		}
		catch(double)
		{
			cout<<"成绩越界\n";
		}
	}
	cout<<"输入的数据为：\n";
	for(i=0;i<max;i++)
		stu[i].show();
	return 0;
}