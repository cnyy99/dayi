#include<iostream>
using namespace std;
int main(void)
{
   int x=30, y=300, z=1024;
   cout<<x<<' '<<y<<' '<<z<<endl;               //按十进制输出
   cout.setf(ios::showbase | ios::uppercase);   //设置基指示符输出和数值中的字母大写输出
   cout<<x<<' '<<y<<' '<<z<<endl;
   cout.unsetf(ios::showbase | ios::uppercase); //取消基指示符输出和数值中的字母大写输出
   cout.setf(ios::oct);                         //设置为八进制输出,此设置不取消一直有效
   cout<<x<<' '<<y<<' '<<z<<endl;               //按八进制输出
   cout.setf(ios::showbase | ios::uppercase);   //设置基指示符输出和数值中的字母大写输出
   cout<<x<<' '<<y<<' '<<z<<endl;
   cout.unsetf(ios::showbase | ios::uppercase); //取消基指示符输出和数值中的字母大写输出
   cout.unsetf(ios::oct);                       //取消八进制输出设置，恢复按十进制输出
   cout.setf(ios::hex);                         //设置为十六进制输出
   cout<<x<<' '<<y<<' '<<z<<endl;
   cout.setf(ios::showbase | ios::uppercase);  //设置基指示符输出和数值中的字母大写输出
   cout<<x<<' '<<y<<' '<<z<<endl;
   cout.unsetf(ios::showbase | ios::uppercase); //取消基指示符输出和数值中的字母大写输出
   cout.unsetf(ios::hex);                       //取消十六进制输出设置，恢复按十进制输出
   cout<<x<<' '<<y<<' '<<z<<endl;
   return 0;
}
