#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
class Hotel{
	private:
		string name;
		int no;
		static int n;
		static int get_n();
	public:
		Hotel(){}
		void add(string s);
		string getName();
		static int getTotal();
		void print();
};
void Hotel::add(string s)
{
	name = s;
	no = n++;
}
string Hotel::getName()
{
	return name;
}
int Hotel::n = get_n();
int Hotel::get_n()
{
	return 1;
}
int Hotel::getTotal()
{	
	return n;
}
void Hotel::print()
{
	cout<<no<<" "<<name<<" "<<n-1<<endl;
}
int main(){

 Hotel h[100];

 h[0].add("Susan");

 h[1].add("Peter");

 h[2].add("John");

 h[3].add("Mary");

 h[4].add("Alice");

 string name;

 cin>>name;

 for(int i=0;i<Hotel::getTotal();i++)

 {

  if(h[i].getName()==name)

  {

   h[i].print();

   break;

  }

 }

 return 0;

}
