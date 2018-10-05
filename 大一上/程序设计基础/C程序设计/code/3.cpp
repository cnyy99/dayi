#include<stdio.h>
int main(void)
{
	int n;
	printf("请输入学生人数：");
	scanf("%d",&n);
	float scores[n][5],aver_student[n],aver_class[5]={0};
	aver_student[n]={0};
	printf("请依次输入每个学生的五门成绩：\n");
	void gets_scores(int n,float a[][5]);
	void aver_classes(int n,float aver_class[],float a[][5]);
	void aver_students(int n,float aver_student[],float a[][5]);
	void find_largest(int n,float a[][5]);
//	void caulate_scores(int n,float a[][5]);
	void puts_scores(int n,float a[][5]);
	void puts_aver_scores(int n,float a[]);
	void puts_aver_class(int n,float a[]);
	gets_scores(n,scores);
	aver_classes(n,aver_class,scores);
	aver_students(n,aver_student,scores);
//	caulate_scores(n,scores);
	puts_scores(n,scores);
	puts_aver_scores(n,aver_student);
	puts_aver_class(5,aver_class);
	find_largest(n,scores);
	return 0;
}
void gets_scores(int n,float a[][5])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
		scanf("%f",&a[i][j]);
}
void puts_scores(int n,float a[][5])
{
	for(int i=0;i<n;i++)
	{
		printf("第%d个学生的成绩分别为：",i+1);
		for(int j=0;j<5;j++)
			printf("%.3f\t",a[i][j]);
		printf("\n");
	}
	printf("\n");
}
void aver_students(int n,float aver_student[],float a[][5])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			aver_student[i]+=a[i][j];
	for(int i=0;i<n;i++)
		aver_student[i]=aver_student[i]/5;
}
void puts_aver_scores(int n,float a[])
{
	for(int i=0;i<n;i++)
		printf("第%d个学生的平均分为:%.3f\n",i+1,a[i]);
	printf("\n");
}
void aver_classes(int n,float aver_class[],float a[][5])
{
	for(int i=0;i<5;i++)
		for(int j=0;j<n;j++)
			aver_class[i]+=a[j][i];
	for(int i=0;i<5;i++)
		aver_class[i]=aver_class[i]/n;
}
void puts_aver_class(int n,float a[])
{
	for(int i=0;i<n;i++)
		printf("第%d门课的平均分为:%.3f\n",i+1,a[i]);
	printf("\n");
}
void find_largest(int n,float a[][5])
{
	int student,classm;
	float max=a[0][0]-1;
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			if(a[i][j]>max)
			{
				max=a[i][j];
				student=i;
				classm=j;
			}
	printf("最高分是第%d名学生的第%d门课程",student+1,classm+1);
	printf("\n");
}
void caulate_scores(int n,float a[][5])
{
	
}








