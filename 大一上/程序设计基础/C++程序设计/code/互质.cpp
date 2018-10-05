/*#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 100010

struct student
{
	string name;
	unsigned long long s1;
	unsigned long long s2;
	unsigned long long s3;
	unsigned long long num;
};
bool cmp(student &a,student &b)
{
	if (a.num==b.num)
	{
		return a.name<b.name;
	}
	return a.num>b.num;
}
student stu[M];
int main()
{
	long n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>stu[i].name>>stu[i].s1>>stu[i].s2>>stu[i].s3;
		stu[i].num=stu[i].s1+stu[i].s2+stu[i].s3;
	}
	sort(stu,stu+n,cmp);
	for (int i = 0; i < n; ++i)
	{
		cout<<stu[i].name<<endl;
	}
	return 0;
}*/
// UVa156 Ananagrams
// Rujia Liu
// 题意：输入一些单词，找出所有满足如下条件的单词：该单词不能通过字母重排得到输入文本中的另外一个单词
// 算法：把每个单词“标准化”，即全部转化为小写字母然后排序，然后放到map中进行统计
#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string,int> cnt;
vector<string> words;

// 将单词s进行“标准化”
string repr(string s) {
  string ans = s;
  for(auto &i:ans)
    i = tolower(i);
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  int n = 0;
  string s;
  while(cin >> s) {
    if(s[0] == '#') break;
    words.push_back(s);
    string r = repr(s);
    if(!cnt.count(r)) cnt[r] = 0;
    cnt[r]++;
  }
  vector<string> ans;
  for(int i = 0; i < words.size(); i++)
    if(cnt[repr(words[i])] == 1) ans.push_back(words[i]);
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] << "\n";
  return 0;
}
