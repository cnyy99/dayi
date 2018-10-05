#include<iostream>
#include<vector>
#include<set>
#include<cstdio>
#include<queue>
#include<functional>
typedef unsigned long long ll;
using namespace std;
priority_queue<ll, vector<ll>, greater<unsigned long long>> v;
set<ll>k;
int jishu[] = { 2,3,5 };
int main()
{
	v.push(1);
	k.insert(1);
	ll i;
	for (i = 1; i < 10010; i++)
	{
		ll number = v.top();
		v.pop();
		for (ll j = 0; j < 3; j++)
		{
			ll sum = number*jishu[j];
			if (k.count(sum) == 0)
			{
				k.insert(sum);
				v.push(sum);
			}
		}
	}
	ll n;
	while (cin >> n && !cin.eof())
	{
		i = 0;
		auto p = k.begin();
		for (; i < n - 1; i++, p++);
		cout << *p << endl;

	}
	system("pause");
	return 0;
}