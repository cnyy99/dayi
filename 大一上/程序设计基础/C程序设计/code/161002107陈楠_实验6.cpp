#include<stdio.h>
#define n 4
struct student{
	int num;
	char name[21];
	float math;
	float psy;
	float it;
	float aver;
};
struct student stu[4];
int main(void)
{
	void input(struct student stu[]);
	int compare(struct student stu[]);
	void print1(struct student *stu);
	void print2(struct student *stu);
	input(stu);
	compare(stu);
	printf("\n");
	print1(stu);
	printf("\n");
	print2(&stu[compare(stu)]);
	return 0;
}
void input(struct student stu[])
{
	int i=0;
	while(i<n)
	{
		printf("请输入第%d个学生的学号：",i+1);
		scanf("%d",&stu[i].num);
		getchar();
		printf("请输入第%d个学生的姓名：",i+1);
		gets(stu[i].name);
		printf("请输入第%d个学生的数学成绩：",i+1);
		scanf("%f",&stu[i].math);
		printf("请输入第%d个学生的物理成绩：",i+1);
		scanf("%f",&stu[i].psy);
		printf("请输入第%d个学生的计算机成绩：",i+1);
		scanf("%f",&stu[i].it);
		stu[i].aver=(stu[i].math+stu[i].it+stu[i].psy)/3;
		i++;
	}
}
int compare(struct student stu[])
{
	int i=0,j=0;
	while(i<n)
	{
		if(stu[i].aver>stu[j].aver)
			j=i;
		i++;
	}
	return j;
}
void print1(struct student *stu)
{
	int i;
	stu--;
	for(i=-1;i<n;i++,stu++)
	{
		printf(i==-1?"学号\t姓名\t数学\t物理\t计算机\t平均成绩\n":"%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",stu->num,stu->name,stu->math,stu->psy,stu->it,stu->aver);
	}
}
void print2(struct student *stu)
{
	printf("平均成绩最高的同学的学号、姓名、数学、物理、计算机成绩和平均成绩为：\n");
	printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",stu->num,stu->name,stu->math,stu->psy,stu->it,stu->aver);
}






























