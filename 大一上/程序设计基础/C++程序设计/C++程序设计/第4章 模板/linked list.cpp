#include<stdio.h>

struct Student{
	char ID[20];
	char name[50];
	double score;
	Student * next;
};

int main()
{
	Student * linkHead, * linkTail, * student;
	double aveScore = 0.0;
	int totalStudent = 0;

	linkHead = linkTail = NULL;

	while(1){
		student = new Student;
		scanf("%s%s%lf", student->ID, student->name, &student->score);
		if(student->score < 0)
		{
			delete student;
			break;
		}else{
			aveScore += student->score;
			totalStudent++;
			student->next = NULL;
			if(linkTail == NULL)
				linkHead = linkTail = student;
			else
			{
				linkTail->next = student;
				linkTail = student;
			}
		}
	}
	printf("课程平均成绩：%.2lf\n", aveScore/totalStudent);

	while(linkHead != NULL)
	{
		student = linkHead;
		linkHead = linkHead->next;
		delete student;
	}

	return 0;
}