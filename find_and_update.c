#include "struct.h"
#include <stdio.h>
#include <string.h>
//全局变量 
extern char currentArea[];
extern Student* nowStudent[];
extern int nowStudentNum;

/*
林萱仪
根据姓名寻找学生

name 要寻找的学生姓名
students 从这些学生中寻找
num students中包含的学生数量
result 存放找到的学生信息
 
return 找到的学生数量 
*/
int findByName(char* name, Student* students[], int num, Student* result[]){
	int i;
	int resultNum = 0;//找到的学生数 
	for (i = 0; i < num; i++){
		if (strcmp(name, students[i]->name) == 0){//如果该学生的姓名和目标相同 
			result[resultNum] = students[i];//将找到的学生存到result 
			resultNum++;//找到的学生数加1 
		}
	}
	return resultNum;//返回找到的数量 
}

/*
梁笑尘
根据学号寻找学生

id 要寻找的学号
students 从这些学生中寻找
num students中包含的学生数

return 指向目标学生结构体的指针 
*/
Student* findById(int id, Student* students[], int num){
	int i;
	for (i = 0; i < num; i++){
		if (students[i]->id == id){//如果该学生的学号和目标相同 
			return students[i];//返回该学生的指针 
		}
	}
	Student no;
	no.id = -1; 
	Student* null = &no;
	return null;//没有目标则返回一个id为-1的学生 
}

/*
梁笑尘 
寻找学生并且更新的流程 
*/ 
void findAndUpdate(){
	print("---------------------");
	print("查询与修改");
	print("当前范围：");
	print(currentArea);
	printFindOption();
	int choice = getChoice(0, 2);
	if (choice == 0){
		return;
	}
	Student* result[5000];
	switch (choice){
		case 1:
			print("输入目标学生的学号：");
			int id;
			scanf("%d", &id);
			result[0] = findById(id, nowStudent, nowStudentNum);
			if (result[0]->id == -1){
				printf("没有学号为%d的学生\n", id);
				break;
			} else {
				printStudent(result, 1);
				print("是否需要修改该学生信息？");
				print("是：输入1 不是：输入0");
				int updateChoice = getChoice(0, 1);
				if (updateChoice){
					print("修改第几科的成绩？");
					int subjectChoice;
					do {
						scanf("%d", &subjectChoice);
						if (subjectChoice >= 1 && subjectChoice <= 10){
							break;
						}
					} while (1);
					print("输入新成绩");
					double newScore;
					do {
						scanf("%lf", &newScore);
						if (newScore >= 0 && newScore <= 100){
							break;
						}
					} while (1);
					double change = newScore - result[0]->score[subjectChoice-1];
					change /= 10;
					result[0]->score[10] += change;
					result[0]->score[subjectChoice-1] = newScore;
					print("已修改");
					printStudent(result, 1);
				}
			}
			break;
		case 2:
			print("输入目标学生的姓名：");
			char name[100];
			scanf("%s", name);
			int count = findByName(name, nowStudent, nowStudentNum, result);
			if (count == 0){
				printf("没有姓名为%s的学生\n", name);
				break;
			} else {
				printStudent(result, count);
				print("是否需要修改学生信息？");
				print("是：输入1 不是：输入0");
				int updateChoice = getChoice(0, 1);
				if (updateChoice){
					print("修改第几个学生的成绩？");
					int countChoice;
					do {
						scanf("%d", &countChoice);
						if (countChoice >= 1 && countChoice <= count){
							break;
						}
					} while (1);
					print("修改第几科的成绩？");
					int subjectChoice;
					do {
						scanf("%d", &subjectChoice);
						if (subjectChoice >= 1 && subjectChoice <= 10){
							break;
						}
					} while (1);
					print("输入新成绩");
					double newScore;
					do {
						scanf("%lf", &newScore);
						if (newScore >= 0 && newScore <= 100){
							break;
						}
					} while (1);
					double change = newScore - result[countChoice-1]->score[subjectChoice-1];
					change /= 10;
					result[countChoice-1]->score[10] += change;
					result[countChoice-1]->score[subjectChoice-1] = newScore;
					print("已修改");
					printStudent(result, count);
				}
			}
			break;
	}
}
 
