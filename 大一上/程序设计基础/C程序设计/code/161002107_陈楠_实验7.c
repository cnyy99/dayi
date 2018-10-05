#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE *fp;
	char ch,name[17];
	printf("Please input the file's name:");
	scanf("%s",name);
	if((fp=fopen(name,"w"))==NULL)
	{
		printf("Can not open this file.");
		exit (0);
	}
	printf("Please input the content:\n");
	getchar();
	ch=getchar();
	while(ch!=EOF)
	{
		fputc(ch,fp);
		ch=getchar();
	}
	fclose(fp);
	putchar(10);
	printf("The content of this file now are:\n");
	if((fp=fopen(name,"r"))==NULL)
	{
		printf("Can not open this file.");
		exit (0);
	}
	ch=fgetc(fp);
	while(!feof(fp))
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
	return 0;
}
