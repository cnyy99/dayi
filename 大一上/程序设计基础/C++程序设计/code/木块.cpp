#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int n;
vector<int>pile[111];
//找到木块所在的堆pile和高度height,以引用的形式返回调用者
void find_block(int a, int& p, int& h) 
{  //引用是传递地址...当在函数里修改其值,变量的值也会随着改变
    for (p = 0; p<n; p++)
        for (h = 0; h<pile[p].size(); h++)
            if (pile[p][h] == a) 
				return;//void中的return:退出函数体，如果在函数体结尾处不加也可自动退出，
                                        //如果在中途需要退出的话就用return
	
}
//把p堆高度为h的木块上方所有的木块移回原位置
void clear_above(int p, int h) 
{
    for (int i = h + 1; i<pile[p].size(); i++) 
	{
        int t = pile[p][i];
        pile[t].push_back(t);   //把标号为t的木块放回原位，即t堆
	}
    pile[p].resize(h + 1);    //重新定义p堆的长度
}
//把p堆高度为h及其上方的木块整体移到p2堆得尾部
void pile_onto(int p, int h, int p2) 
{
    for (int i = h; i<pile[p].size(); i++)
		pile[p2].push_back(pile[p][i]);
    pile[p].resize(h);
}
//输出木块最后的状态
void print() 
{
    for (int i = 0; i<n; i++) 
	{
        printf("%d:", i);
        for (int j = 0; j<pile[i].size(); j++) 
		{
            printf(" %d", pile[i][j]);
		}
        printf("\n");
		
	}

}
int main() {
    int a, b;
    string s1, s2;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) 
		pile[i].push_back(i);
    while (cin >> s1) 
	{
        if (s1 == "quit") break;
        cin >> a >> s2 >> b;
        int pa, pb, ha, hb;
        find_block(a, pa, ha);
        find_block(b, pb, hb);
        if (pa == pb) 
			continue;
        if (s2 == "onto") 
			clear_above(pb, hb);
        if (s1 == "move") 
			clear_above(pa, ha);
        pile_onto(pa, ha, pb);
	}
    print();
	system("pause");
    return 0;

}