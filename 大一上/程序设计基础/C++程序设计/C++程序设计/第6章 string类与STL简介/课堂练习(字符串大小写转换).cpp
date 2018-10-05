//#include<ctype.h>
#include <string>
#include<iostream>
using namespace std;


int main()
{
	string str("hello");
	for(string::size_type index = 0; index != str.size(); ++index)
		if(islower(str[index])) str[index] = toupper(str[index]);
	cout<<str<<endl;

	return 0;
}


