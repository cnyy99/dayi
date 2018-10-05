#include<stdio.h>
#include<string.h>
int main(void)
{
	int a,b,c,score;
	char x,y,s,str;
	int scores(char x,char y,char s,int a,int b,int c);
	while(scanf("%c %c %c",&x,&y,&s)!=EOF){
		score=0;
		scanf("%d %d %d",&a,&b,&c);
		score=scores(x,y,s,a,b,c);
		printf("%d\n",score);
		str=getchar();
	} 
	return 0;
}
int scores(char x,char y,char s,int a,int b,int c)
{
	if(x=='x'&&y=='y'&&s=='s')
		return 8*b-3*a+c;
	else if(x=='x'&&y=='s'&&s=='y')
		return 8*c-3*a+b;
	else if(x=='y'&&y=='x'&&s=='s')
		return 8*a-3*b+c;
	else if(x=='y'&&y=='s'&&s=='x')
		return 8*a-3*c+b;
	else if(x=='s'&&y=='x'&&s=='y')
		return 8*c-3*b+c;
	else if(x=='s'&&y=='y'&&s=='x')
		return 8*c-3*c+b;
}

