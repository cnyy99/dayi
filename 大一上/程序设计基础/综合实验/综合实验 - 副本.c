#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<conio.h> 
#include<stdlib.h> 
#define M 6 	 																//宏定义最多课程数量 
#define N 37	 																//宏定义最大学生人数 
void menu(void);																//定义菜单函数 
void test(void);																//定义测试是否输入过成绩函数 
void student_input(void);														//定义录入成绩函数												
void information_save(void);													//定义保存成绩函数
void student_change(void);														//定义修改成绩函数 
void student_del(void);															//定义删除成绩函数 
void student_aver1(void);														//定义求某个人的几门课程的平均成绩函数 
void student_sort(void);														//定义求所有人的平均成绩并排序函数 
void class_aver2(void);															//定义求某门课程的平均成绩函数
void class_sort2(void);															//定义求每门课程的平均成绩并排序函数 
void student_sort3(void);														//定义对某门课程所有人的成绩排序函数 
void student_rank(void);														//定义求某一个人在班级的名次函数 
void information_print(void);													//定义输出成绩函数
void program_out(void);															//定义退出系统函数 
bool Y_N_test2(void);
int cmp1(const void *a,const void *b);					
int cmp2(const void *a,const void *b);
int cmp3(const void *a,const void *b);
int cmp4(const void *a,const void *b);											//定义qsort函数所需参数 
int cmp5(const void *a,const void *b);
int cmp6(const void *a,const void *b);
int cmp7(const void *a,const void *b);
int cmp8(const void *a,const void *b);	
int cmp9(const void *a,const void *b);										
bool full=false;																//存储是否已经输入过成绩 
struct classes{																	//定义课程结构体 
	int number;																	//课程序号 
	float avers;																//该课程平均成绩
	char class_name[17];														//课程名字 		
};
struct student{																	//定义学生结构体 
	char num[11];																//学号 
	char name[17];																//姓名 
	float scores[M];															//各门成绩 
	float aver;																	//该学生的平均成绩 
};
struct classes mean[M];															//定义课程结构体数组 
struct student stu[N];															//定义学生结构体数组 
struct student *p=stu;
														
int n;																			//定义全局变量储存用户输入的学生人数 
int m;																			//定义全局变量储存用户输入的课程数量 
FILE *fp;																		//定义文件指针 


int main(void)
{

	printf( "                  	 ----------------------------\n"
			"                  	 欢迎进入班级学习成绩管理系统\n"
			"                  	 ----------------------------\n\n"
			"           	---版权所有：计算机类16-1班  陈楠  161002107---\n\n"); 
	menu();
	return 0;
} 																
void menu(void)
{
	int t;
	char ch,mh[10];																//定义字符，字符型数组储存用户输入的数据 
	printf(	"------------------------------------\n" 
			" 1)	录入成绩\n"
			" 2)	保存成绩\n"
			" 3)	修改成绩\n"
			" 4)	删除成绩\n"
			" 5)	求某个人的几门课程的平均成绩\n"
			" 6)	求所有人的平均成绩并排序\n"
			" 7)	求某门课程的平均成绩\n"
			" 8)	求每门课程的平均成绩并排序\n"
			" 9)	求某一个人在班级的名次\n"
			" 0)	对某门课程所有人的成绩排序\n"
			" T)	退出\n"
			"------------------------------------\n"
			"请选择操作（第一列代表操作）:");
//	if(isnumber())
//		getchar();
	scanf("%s",mh);									
	ch=mh[0];																	//令数字为字符型并直判断第一个字符，避免switch数字时输入字符造成的死循环 
//	getchar();
	switch(ch) 
	{ 
		case '1':student_input();break; 
		case '2':information_save();break; 
		case '3':student_change();break; 
		case '4':student_del();break; 
		case '5':student_aver1();break;											//通过输入的指令，决定执行哪一个函数 
		case '6':student_sort();break;
		case '7':class_aver2();break;
		case '8':class_sort2();break;
		case '9':student_rank();break; 
		case '0':student_sort3();break;
		case 't':
		case 'T':program_out();break;
		default:printf("输入错误!请重新输入\n");menu();break; 
	}	 
}
void student_input(void)
{
	int i,j;
	char ch;
	if(!full)																	//判断是否已经录入过成绩 
	{
		printf("请输入班级人数(1-37)与课程数量(1-6)：");
		scanf("%d%d",&n,&m);													//用户输入班级人数与课程数量 
		printf("请按顺序输入课程名字：\n");
		for(i=0;i<m;i++)
		{
			scanf("%s",mean[i].class_name);
		}
	}
	else
	{
		printf("已经录入过数据 是否重新录入？(Y为确认其他均为否认）:");
		getchar();																//接受回车符 
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		{
			full=false;
			student_input();
		}
		else
		{
			menu();
		}
	} 
		
	for(i=0;i<n;i++)															//循环输入每个学生的信息		
	{	
		stu[i].aver=0;															//初始化每个学生的平均成绩 
		printf("请输入第%d个学生的学号：",i+1);
		scanf("%s",stu[i].num);
		getchar();																//接受回车符 
		printf("请输入第%d个学生的姓名：",i+1);
		gets(stu[i].name);
		for(j=0;j<m;j++)														//循环输入每个学生的成绩 
		{
			printf("请输入第%d个学生%s成绩：",i+1,mean[j].class_name);
			scanf("%f",&stu[i].scores[j]);
			stu[i].aver+=stu[i].scores[j];	
		}	
		stu[i].aver/=m;															//计算每个学生的平均成绩 
	}
	printf("\n               --------------录入完成--------------\n\n");
	full=true;																	//令是否输入过成绩为真 
	printf("\n-------请按任意键继续......\n");
	getch();																	//无回显地取一个字符，令程序继续运行 
	system("CLS");																//清屏 
	menu(); 																	//回到菜单 
}
void information_save(void)
{
	test();																		//测试是否输入过成绩 
	int i,j;	
	char filename[17];
	qsort(stu,n,sizeof(stu[0]),cmp1);											//对结构体按总成绩总大到小进行排序 
	printf("请输入要保存的文件的名字：");
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)											//判断文件能否打开 
	{
		printf("无法打开此文件。\n");
		menu();
	}
	fprintf(fp,"名次\t学号\t姓名");
	for(j=0;j<m;j++)
	{
		fprintf(fp,"\t%s",mean[j].class_name);
	}
	fprintf(fp,"\t\t平均成绩\n");
	for(j=0;j<m+5;j++)
	{
		fprintf(fp,"--------");
	}
	fputc(10,fp);
	for(i=0;i<n;i++)															//循环写入成绩 
	{
		fprintf(fp,"%3d\t%s\t%s\t",i+1,stu[i].num,stu[i].name);					//采用格式化的方式写入数据 
		for(j=0;j<m;j++)
		{
			fprintf(fp,"%.1f\t",stu[i].scores[j]);
		} 
		fprintf(fp,"\t%.1f\n",stu[i].aver);
	}
	fclose(fp);	
	printf("\n               --------------保存成功--------------\n\n"
		   "\n-------请按任意键继续......\n");						
	getch();																	//无回显地取一个字符，令程序继续运行 
	system("CLS");																//清屏 
	menu();
	
}
void test(void)
{
	while(!full)																//判断是否输入过成绩 
	{
		system("CLS");		
		printf("\n\n                      -----没有数据，请录入成绩后进行本操作-----\n\n\n");
		menu();
	}
	return;
}
bool Y_N_test2(void)
{
	char ch;
	getchar();																	//接受回车符 
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
		return true;
	else
	{
		return false;
	}
}
void student_aver1(void)
{
	test();
	int i;
	char k[11];
	bool t=true;
	while(t)
	{
		printf("请输入要查询的学生的学号：");
		scanf("%s",k);
		for(i=0;i<n;i++)
		{
			if(strcmp(stu[i].num,k)==0)											//比较用户输入的的学号与已有学号是否相同 
			{
				printf("\n此学生目前的信息为：\n学号\t姓名\t平均成绩\n---------------------------\n%s\t%s\t%.1f\n",stu[i].num,stu[i].name,stu[i].aver);
				break;
			}
		}
		if(i==n)																//没有相同学号时运行 
		{
			printf("--无此学号!\n");
		} 
		printf("是否继续查询?(Y为确认其他均为否认）:");
		t=Y_N_test2();	
	}
	system("CLS");
	menu();
}
void student_rank(void)
{
	test();
	int i;
	char k[11];
	bool t=true;
	qsort(stu,n,sizeof(stu[0]),cmp1);
	while(t)
	{
		printf("请输入要查询的学生的学号：");
		scanf("%s",k);
		for(i=0;i<n;i++)
		{
			if(strcmp(stu[i].num,k)==0)
			{
				printf("\n此学生的名次为：%d\n",i+1);
				break;
			}
		}
		if(i==n)
		{
			printf("--无此学号!\n");
		 } 
		printf("\n是否继续查询?(Y为确认其他均为否认）:");
		t=Y_N_test2();
	}
	system("CLS");
	menu();
}
void program_out(void)
{
	char ch; 
	printf("确认退出系统？(Y为确认其他均为否认):"); 
	getchar();																	//接受回车符 
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	{
		printf( "\n\n\n                  	 ----------------------------\n"
				"                  	 感谢使用班级学习成绩管理系统\n"
				"                  	 ----------------------------\n\n"
				"           	---版权所有：计算机类16-1班  陈楠  161002107---\n\n");
		exit(EXIT_SUCCESS);
	} 
	else
	{
		system("CLS");		
		menu();
    }
}
void information_print(void)
{
	int i,j;
	printf("\n排序结果如下：\n");
	printf("\n\n名次\t学号\t姓名");
	for(j=0;j<m;j++)
	{
		printf("\t%s",mean[j].class_name);
	}
	printf("\t\t平均成绩\n");
	for(j=0;j<m+6;j++)
	{
		printf("--------");
	}
	for(i=0;i<n;i++)															//循环方式打印学生信息 
	{
		printf("\n%3d\t%s\t%s\t",i+1,stu[i].num,stu[i].name);
		for(j=0;j<m;j++)
			printf("%.1f\t",stu[i].scores[j]); 
		printf("\t%.1f",stu[i].aver);
	}
	printf("\n\n\n");
	return ;
}
void student_change(void)
{
	test();
	int i,j;
	char ch,k[11];
	bool t=true;
	system("CLS");																//清屏 
	printf( "\n                    -------------------------\n"
			"                    欢迎进入学员信息修改系统!\n"
			"                    -------------------------\n\n"); 
	while(t)
	{
		printf("请输入要修改的学生的学号：");
		scanf("%s",k);
		for(i=0;i<n;i++)
		{
			if(strcmp(stu[i].num,k)==0)											//比较用户输入的的学号与已有学号是否相同 
			{
				printf("\n此学生目前的信息为：\n学号\t姓名\t");
				for(j=0;j<m;j++)
				{
					printf("%s\t",mean[j].class_name);
				}
				putchar(10);
				for(j=0;j<m+2;j++)
				{
					printf("--------");
				}
				printf("\n%s\t%s\t",stu[i].num,stu[i].name);
				for(j=0;j<m;j++)
					printf("%.1f\t",stu[i].scores[j]); 
				printf("\n确认修改?(Y为确认其他均为否认):");
				getchar();														//接受回车符 
				scanf("%c",&ch);
				if(ch=='y'||ch=='Y')
				{
					stu[i].aver=0;
					printf("请输入新的信息：\n请输入新的学号：");
					scanf("%s",stu[i].num);
					printf("请输入新的姓名：");
					getchar();													//接受回车符 
					gets(stu[i].name);
					printf("请输入新的课程成绩：");
					for(j=0;j<m;j++)
					{
						scanf("%f",&stu[i].scores[j]);
						stu[i].aver+=stu[i].scores[j];
					}
					stu[i].aver/=m;												//计算新的平均值 
					printf("\n      --------------修改完成--------------\n\n");
					break;
				}
				else
					break;
			}
		}
		if(i==n)
		{
			printf("--无此学号!\n"); 
		} 
		printf("是否继续修改?(Y为确认其他均为否认）:");
		t=Y_N_test2();
	}
	printf( "\n\n                    ----------------------------\n"
			"                    感谢使用学员信息修改系统!\n"
			"                    ----------------------------\n"); 
	printf("\n-------请按任意键继续.....\n");
	getch(); 																	//无回显地取一个字符，令程序继续运行 
	system("CLS");																//清屏 	
	menu();		
}
void student_del(void)
{
	test();	
	int i,j;
	char ch,k[11];
	bool t=true;
	system("CLS");																//清屏 	
	printf( "\n                    -------------------------\n"
			"                    欢迎进入学员信息删除系统!\n"
			"                    -------------------------\n\n"); 
	while(t)
	{
		printf("请输入要删除的学生的学号：");
		scanf("%s",k);
		for(i=0;i<n;i++)
		{
			if(strcmp(stu[i].num,k)==0)											//比较用户输入的的学号与已有学号是否相同 		
			{
				printf("\n此学生目前的信息为：\n学号\t姓名\t");
				for(j=0;j<m;j++)
				{
					printf("%s\t",mean[j].class_name);
				}
				putchar(10);
				for(j=0;j<m+2;j++)
				{
					printf("--------");
				}
				printf("\n%s\t%s\t",stu[i].num,stu[i].name);
				for(j=0;j<m;j++)
					printf("%.1f\t",stu[i].scores[j]); 
				printf("%.1f\n",stu[i].aver);
				printf("确认删除?(Y为确认其他均为否认):");
				getchar();														//接受回车符 
				scanf("%c",&ch);
				if(ch=='y'||ch=='Y')
				{
					for(j=i;j<n;j++) 
						stu[j]=stu[j+1]; 
					printf("\n      --------------删除完成--------------\n\n");
					n--;
					goto loop;													//删除完成后，跳到loop处继续执行 
				}																//避免删除最后一条数据时输出无此学号 
				else
					break;
			}
		}
		if(i==n)
		{
			printf("--无此学号!\n");
		} 
		loop:printf("\n是否继续删除?(Y为确认其他均为否认）:");
		t=Y_N_test2();
	}
	printf( "\n               -------------------------\n"
			"               感谢使用学员信息删除系统!\n"
			"               -------------------------\n");
	printf("\n-------请按任意键继续......\n");
	getch(); 																	//无回显地取一个字符，令程序继续运行 
	system("CLS");																//清屏 	
	menu();	
 } 
void student_sort(void)
{
	test();
	qsort(stu,n,sizeof(stu[0]),cmp1);
	information_print();
	printf("\n-------请按任意键继续......\n");
	getch();																	//无回显地取一个字符，令程序继续运行 
	system("CLS");																//清屏 	
	menu();
}

void class_sort2(void)
{
	test();	
	int i,j;
	for(i=0;i<m;i++)															//初始化课程序号 
		mean[i].number=i+1;
	for(i=0;i<m;i++)
		mean[i].avers=0;														//初始化课程平均成绩 
	for(j=0;j<m;j++)															//循环方式计算课程的平均成绩 
	{
		for(i=0;i<n;i++)
		{
			mean[j].avers+=stu[i].scores[j];
		}
		mean[j].avers/=n;
	}
	qsort(mean,m,sizeof(mean[0]),cmp2);											//对课程结构体进行排序 
	printf("排序结果如下：\n\n");
	for(i=-1;i<m;i++)															//循环输出结果 
	{
		printf(i==-1?"\n排名\t课程\t平均成绩\n------------------------\n":"%3d\t%s\t  %4.1f\n",i+1,mean[i].class_name,mean[i].avers);
	}
	printf("\n\n");
	printf("\n-------请按任意键继续.....\n");
	qsort(mean,m,sizeof(mean[0]),cmp9);											//返回初始顺序 
	getch();																	//无回显地取一个字符，令程序继续运行 
	system("CLS");																//清屏 	
	menu();
}
void student_sort3(void)
{
	test();
	char k[17];
	int i,j,abc;
	bool t=true;
	for(i=0;i<m;i++)															//初始化课程序号 
		mean[i].number=i+1;
	while(t)
	{
		printf("请输入以哪门课程对所有人的成绩排序：");
//		getchar();																//接受回车符 
		scanf("%s",k);
	for(i=0;i<m;i++)
	{
		if(strcmp(mean[i].class_name,k)==0)											//比较用户输入的的学号与已有学号是否相同 		
		{
			abc=mean[i].number;
			switch(abc)																//switch要查询第几门课 
			{
				case 1:qsort(stu,n,sizeof(stu[0]),cmp3);break;
				case 2:qsort(stu,n,sizeof(stu[0]),cmp4);break;
				case 3:qsort(stu,n,sizeof(stu[0]),cmp5);break;
				case 4:qsort(stu,n,sizeof(stu[0]),cmp6);break;
				case 5:qsort(stu,n,sizeof(stu[0]),cmp7);break;
				case 6:qsort(stu,n,sizeof(stu[0]),cmp8);break;
				default:printf("无此课程！\n");goto laap;break;
			}
			information_print();
			printf("\n");
			break;
		}	
	}
	if(i==m)
	{
		printf("无此课程！\n");
	} 
		laap:printf("\n是否继续查询?(Y为确认其他均为否认）:");
		t=Y_N_test2();
	}
	system("CLS");
	menu();
}
int cmp1(const void *a,const void *b) 
{ 
	return (*(struct student *)a).aver<(*(struct student *)b).aver ? 1 : -1; 
}
int cmp2(const void *a,const void *b)
{
	return (*(struct classes *)a).avers<(*(struct classes *)b).avers ? 1 : -1;
} 
int cmp3(const void *a,const void *b)
{
	return (*(struct student *)a).scores[0]<(*(struct student *)b).scores[0] ? 1 : -1;
} 
int cmp4(const void *a,const void *b)
{
	return (*(struct student *)a).scores[1]<(*(struct student *)b).scores[1] ? 1 : -1;					//定义qsort函数所需参数
} 																										//按从大到小 
int cmp5(const void *a,const void *b)																	//进行排序 
{
	return (*(struct student *)a).scores[2]<(*(struct student *)b).scores[2] ? 1 : -1;
} 
int cmp6(const void *a,const void *b)
{
	return (*(struct student *)a).scores[3]<(*(struct student *)b).scores[3] ? 1 : -1;
} 
int cmp7(const void *a,const void *b)
{
	return (*(struct student *)a).scores[4]<(*(struct student *)b).scores[4] ? 1 : -1;
} 
int cmp8(const void *a,const void *b)
{
	return (*(struct student *)a).scores[5]<(*(struct student *)b).scores[5] ? 1 : -1;
} 
int cmp9(const void *a,const void *b)
{
	return (*(struct classes *)a).number>(*(struct classes *)b).number ? 1 : -1;
} 
void class_aver2(void)
{
	test();	
	int i,j;
	char k[17];
	bool t=true;	
	for(i=0;i<m;i++)																//初始化课程序号 
		mean[i].number=i+1;
	for(i=0;i<m;i++)
		mean[i].avers=0;															//初始化课程平均成绩 
	for(j=0;j<m;j++)																//循环方式计算课程的平均成绩 
	{
		for(i=0;i<n;i++)
		{
			mean[j].avers+=stu[i].scores[j];
		}
		mean[j].avers/=n;
	}
	while(t)
	{
		printf("\n请输入要求哪门课程的平均成绩：");
		scanf("%s",k);
		for(i=0;i<m;i++)
		{
			if(strcmp(k,mean[i].class_name)==0)
			{
				printf("\n%s的平均成绩为：%.1f\n",mean[i].class_name,mean[i].avers);
				break;
			}
		}
		if(i==m)
			printf("无此课程。\n");
		printf("\n是否继续查询?(Y为确认其他均为否认）:");
		t=Y_N_test2();
	}
	system("CLS");
	menu();
}
