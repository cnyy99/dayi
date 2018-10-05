#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	FILE * fp;
	fp = fopen("test.txt", "w");  // fopen_s(&fp,"test.txt", "w"); 更安全，有溢出检查
	if(!fp)
	{
		cout<<"cannot open this file.\n";
		exit(0);  //参数0正常退出，参数非0非正常退出，类似return，返回给操作系统
	}
	int temp = fclose(fp);  //fclose成功，返回0；错返回EOF
	if(temp == 0)
		cout<<"succeed\n";
	else
		cout<<"fail\n";
	
	return 0;
}