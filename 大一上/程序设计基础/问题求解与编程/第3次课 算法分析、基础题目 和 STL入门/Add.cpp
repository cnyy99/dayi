#include <stdio.h>
#include <string.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a && !b) return 0;
		int c = 0, ans = 0;
		while(a && b)
		{
			c = (a%10+b%10+c)>9 ? 1 : 0;
			ans += c;
			a /= 10; b /= 10; 
		}
		printf("%d\n", ans);
	}
	return 0;
}