#include "struct.h"
#include <string.h>
#include <stdio.h>

extern char currentArea[];
extern Student* nowStudent[];
extern int nowStudentNum;

/*
马汶研
根据姓名排序

students 从这些学生中寻找
mode 1正序排序 0倒序排序
num students中的学生总数 
*/ 
void sortByName(Student* students[], int mode, int num){
	int i, j;
	Student* t;
	if (mode == 1) {//正序排序 
		for (i = 0; i < num-1; i++) {//排序流程 
			for(j = i+1; j < num; j++) {
				if(strcmp(students[i]->name, students[j]->name) > 0) {
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	} else {//倒序排序 
		for (i = 0; i < num-1; i++){//排序流程 
			for(j = i+1; j<num; j++){
				if(strcmp(students[i]->name, students[j]->name) < 0){
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	}
}
 
/*
马汶研
根据姓名排序

subject 按第几门学科排序 第11门为平均值 
students 从这些学生中寻找
mode 1正序排序 0倒序排序
num students中的学生总数 
*/ 
void sortByScore(int subject, Student* students[], int mode, int num){
	int i, j;
	Student* t;
	if (mode == 1) {//正序排序 
		for (i = 0; i < num-1; i++){//排序流程 
			for(j = i+1; j < num; j++){
				if(students[i]->score[subject] > students[j]->score[subject]){
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	} else {//倒序排序
		for (i = 0; i < num-1; i++){//排序流程 
			for(j = i+1; j < num; j++){
				if(students[i]->score[subject] < students[j]->score[subject]){
					t = students[i];
					students[i] = students[j];
					students[j] = t;
				}
			}
		}
	}
}

/*
梁笑尘 
排序并输出流程 
*/ 
void sortAndPrint(){
	print("---------------------");
	print("排序与输出功能");
	print("当前范围：");
	print(currentArea);
	printSortOption();
	int choice = getChoice(0, 3);
	if (choice == 0){
		return;
	}
	print("正序排序输入1 倒序排序输入0");
	int sortChoice = getChoice(0, 1);
	switch (choice){
		case 1:
			sortByName(nowStudent, sortChoice, nowStudentNum);
			break;
		case 2:
			print("根据第几科的成绩排序？");
			int socreChoice = getChoice(1, 10);
			socreChoice--;
			sortByScore(socreChoice, nowStudent, sortChoice, nowStudentNum);
			break;
		case 3:
			sortByScore(10, nowStudent, sortChoice, nowStudentNum);
			break;
	}
	int i, j;
	printStudent(nowStudent, nowStudentNum);
}

